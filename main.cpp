#include <assert.h> // assert
#include <nettle/sha2.h> // sha256_*, SHA256_DIGEST_SIZE
#include <stddef.h> // size_t
#include <stdio.h> // f*, SEEK_*, sprintf, stderr
#include <stdint.h> // int8_t, uint*_t
#include <stdlib.h> // exit, EXIT_*
#include <string.h> // memcmp, memset, strcmp

#include "util.cpp"
#include "gb.cpp"
#include "registers.cpp"

const u16 BIOS_START = 0x0000;
const u16 BIOS_END = 0x00FF;
const size_t BIOS_LENGTH = BIOS_END - BIOS_START + 1;
u8 bios[BIOS_LENGTH];

#include "memory.cpp"
#include "cpu.cpp"

void load_bios(const char* path) {
	read_file(path, [path](size_t length) {
		if (length != BIOS_LENGTH) {
			panic("The bios file \"%s\" has a size of %zu bytes."
				" It should be %zu bytes.",
				path, length, BIOS_LENGTH);
		}
		return bios;
	});

	u8 hash[SHA256_DIGEST_SIZE];
	sha256(bios, BIOS_LENGTH, hash);

	// cf053eccb4ccafff9e67339d4e78e98dce7d1ed59be819d2a1ba2232c6fce1c7
	const u8 DMG_bios_hash[SHA256_DIGEST_SIZE] = {
		0xcf, 0x05, 0x3e, 0xcc, 0xb4, 0xcc, 0xaf, 0xff, 0x9e, 0x67, 0x33, 0x9d,
		0x4e, 0x78, 0xe9, 0x8d, 0xce, 0x7d, 0x1e, 0xd5, 0x9b, 0xe8, 0x19, 0xd2,
		0xa1, 0xba, 0x22, 0x32, 0xc6, 0xfc, 0xe1, 0xc7,
	};
	if (memcmp(hash, DMG_bios_hash, SHA256_DIGEST_SIZE) != 0) {
		char hash_string[SHA256_STRING_SIZE];
		sha256_string(hash, hash_string);

		char DMG_bios_hash_string[SHA256_STRING_SIZE];
		sha256_string(DMG_bios_hash, DMG_bios_hash_string);

		panic("The bios file \"%s\" has a SHA-256 hash of %s. It should be %s.",
			path, hash_string, DMG_bios_hash_string);
	}
}

[[noreturn]]
void panic_usage() {
	panic("Usage: ./gammaboy path/to/DMG_bios [--log]");
}

int main(int argc, const char* argv[]) {
	// Parse command line arguments.
	const char* path_to_DMG_bios;
	bool log = false;
	if (argc >= 2) {
		path_to_DMG_bios = argv[1];

		for (int i = 2; i < argc; ++i) {
			const char* arg = argv[i];
			if (strcmp(arg, "--log") == 0) {
				log = true;
			} else {
				panic_usage();
			}
		}
	} else {
		panic_usage();
	}

	load_bios(path_to_DMG_bios);

	gb gb_;
	gb_.log = log;
	gb* gb = &gb_;
	for (;;) {
		if (gb_.log) {
			printf(
				"PC=0x%04X AF=0x%04X BC=0x%04X DE=0x%04X HL=0x%04X SP=0x%04X\n",
				PC.get(gb), AF.get(gb), BC.get(gb),
				DE.get(gb), HL.get(gb), SP.get(gb)
			);
		}

		fetch_decode_execute(gb);
	}

	return EXIT_SUCCESS;
}
