#define panic(...) \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\n"); \
	exit(EXIT_FAILURE)

using u8 = uint8_t;
using i8 = int8_t;
using u16 = uint16_t;

template<typename T>
bool get_bit(T x, int bit) {
	assert(0 <= bit && bit < static_cast<int>(sizeof(T)) * 8);

	return ((x >> bit) & 1) != 0;
}

template<typename T>
T set_bit(T x, int bit, bool value) {
	assert(0 <= bit && bit < static_cast<int>(sizeof(T)) * 8);

	if (value) {
		x |= 1 << bit;
	} else {
		x &= ~(1 << bit);
	}
	return x;
}

void binary_repr(u8 x, char* s) {
	for (int i = 0; i <= 7; ++i) {
		const int bit = 7 - i;
		s[i] = get_bit(x, bit) ? '1' : '0';
	}
	s[8] = '\0';
}

template<typename T>
void read_file(const char* path, T get_buffer) {
	FILE* f = fopen(path, "rb");
	if (f == nullptr) {
		panic("Could not open file \"%s\".", path);
	}

	// Get file size.
	assert(fseek(f, 0, SEEK_END) == 0);
	const size_t length = static_cast<size_t>(ftell(f));
	assert(fseek(f, 0, SEEK_SET) == 0); // Rewind.

	u8* buffer = get_buffer(length);
	assert(fread(buffer, sizeof(u8), length, f) == length);

	assert(fclose(f) == 0);
}

void sha256(const u8* data, size_t length, u8* hash) {
	sha256_ctx ctx;
	sha256_init(&ctx);
	sha256_update(&ctx, length, data);
	sha256_digest(&ctx, SHA256_DIGEST_SIZE, hash);
}

// 2 chars per byte, plus one char for '\0'.
const size_t SHA256_STRING_SIZE = SHA256_DIGEST_SIZE * 2 + 1;

void sha256_string(const u8* hash, char* s) {
	for (int i = 0; i < SHA256_DIGEST_SIZE; ++i) {
		sprintf(&s[i * 2], "%02x", hash[i]);
	}
}
