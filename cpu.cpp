// ----------------
// 16-bit immediate
// ----------------

class imm_u16 {
public:
	u16 get(gb* gb) const;
};

u16 imm_u16::get(gb* gb) const {
	const u8 little_end = mem_read(PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	const u8 big_end = mem_read(PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	return static_cast<u16>((big_end << 8) | little_end);
}

const imm_u16 imm_u16;

// --------------
// CPU operations
// --------------

template<typename T1, typename T2>
void LD(gb* gb, T1 x, T2 y) {
	x.set(gb, y.get(gb));
}

// UM0080.pdf rev 11 p175 / 332
template<typename T>
void XOR(gb* gb, T x) {
	const u8 result = A.get(gb) ^ x.get(gb);
	A.set(gb, result);

	F.Z.set(gb, result == 0x00);
	F.N.reset(gb);
	F.H.reset(gb);
	F.C.reset(gb);
}

// ----------------------
// Fetch, decode, execute
// ----------------------

void fetch_decode_execute(gb* gb) {
	const u16 PC_0 = PC.get(gb);

	const u8 opcode = mem_read(PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	switch (opcode) {
	case 0x21:
		printf("LD HL, imm_u16\n");
		LD(gb, HL, imm_u16);
		break;
	case 0x31:
		printf("LD SP, imm_u16\n");
		LD(gb, SP, imm_u16);
		break;
	case 0xAF:
		printf("XOR A\n");
		XOR(gb, A);
		break;
	default:
		char binary_opcode[9];
		binary_repr(opcode, binary_opcode);
		panic("Unknown opcode 0x%02X=0b%s at 0x%04X.",
			opcode, binary_opcode, PC_0);
		break;
	}
}
