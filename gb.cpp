const int AF_i = 0;
const int BC_i = 1;
const int DE_i = 2;
const int HL_i = 3;
const int PC_i = 4;
const int SP_i = 5;

const u16 VRAM_START = 0x8000;
const u16 VRAM_END = 0x9FFF;
const size_t VRAM_LENGTH = VRAM_END - VRAM_START + 1;

const u16 HRAM_START = 0xFF80;
const u16 HRAM_END = 0xFFFE;
const size_t HRAM_LENGTH = HRAM_END - HRAM_START + 1;

class gb {
public:
	// Options
	bool log = false;

	// Registers
	u16 regs[6] = {
		[AF_i] = 0x0000,
		[BC_i] = 0x0000,
		[DE_i] = 0x0000,
		[HL_i] = 0x0000,
		[PC_i] = 0x0000,
		[SP_i] = 0x0000,
	};

	// Memory
	u8 vram[VRAM_LENGTH]; // Video ram
	u8 lcdc = 0x00; // 0xFF40 LCD Control
	u8 scy = 0x00; // 0xFF42 SCroll Y
	u8 bgp = 0x00; // 0xFF47 BackGround Palette
	u8 hram[HRAM_LENGTH]; // High ram, Zero Page

	gb();
};

gb::gb() {
	memset(vram, 0x00, VRAM_LENGTH);
	memset(hram, 0x00, HRAM_LENGTH);
}
