// ---------------
// Memory location
// ---------------

template<typename T>
class mem {
private:
	const T addr;

public:
	mem(const T p_addr);
	u8 get(gb* gb) const;
	void set(gb* gb, u8 value) const;
};

template<typename T>
mem<T>::mem(const T p_addr) :
	addr(p_addr)
{}

template<typename T>
u8 mem<T>::get(gb* gb) const {
	return mem_read(gb, addr.get(gb));
}

template<typename T>
void mem<T>::set(gb* gb, u8 value) const {
	mem_set(gb, addr.get(gb), value);
}

// ---------------
// 0xFF00 + offset
// ---------------

template<typename T>
class FF00 {
private:
	const T offset;

public:
	FF00(const T p_offset);
	u16 get(gb* gb) const;
};

template<typename T>
FF00<T>::FF00(const T p_offset) :
	offset(p_offset)
{}

template<typename T>
u16 FF00<T>::get(gb* gb) const {
	const u8 offset_value = offset.get(gb);
	return 0xFF00 + offset_value;
}

// ---------------
// 8-bit immediate
// ---------------

class imm_u8 {
public:
	u8 get(gb* gb) const;
};

u8 imm_u8::get(gb* gb) const {
	const u8 value = mem_read(gb, PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	return value;
}

const imm_u8 imm_u8;

// ----------------------
// Signed 8-bit immediate
// ----------------------

class imm_i8 {
public:
	i8 get(gb* gb) const;
};

i8 imm_i8::get(gb* gb) const {
	const u8 value = mem_read(gb, PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	return static_cast<i8>(value);
}

const imm_i8 imm_i8;

// ----------------
// 16-bit immediate
// ----------------

class imm_u16 {
public:
	u16 get(gb* gb) const;
};

u16 imm_u16::get(gb* gb) const {
	const u8 little_end = mem_read(gb, PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	const u8 big_end = mem_read(gb, PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	return static_cast<u16>((big_end << 8) | little_end);
}

const imm_u16 imm_u16;

// -------------------
// Carries and borrows
// -------------------

bool carry(u8 x, u8 y) {
	return x + y > 0xFF;
}

bool half_carry(u8 x, u8 y) {
	return (x & 0x0F) + (y & 0x0F) > 0x0F;
}

bool borrow(u8 x, u8 y) {
	return x < y;
}

bool half_borrow(u8 x, u8 y) {
	return (x & 0x0F) < (y & 0x0F);
}

// --------------
// CPU operations
// --------------

// UM0080.pdf rev 11 p159,161,162 / 332
template<typename T>
void ADD(gb* gb, T x) {
	const u8 v1 = A.get(gb);
	const u8 v2 = x.get(gb);

	const u8 result = v1 + v2;
	A.set(gb, result);

	F.Z.set(gb, result == 0x00);
	F.N.reset(gb);
	F.H.set(gb, half_carry(v1, v2));
	F.C.set(gb, carry(v1, v2));
}

// UM0080.pdf rev 11 p257,259 / 332
template<typename T>
void BIT(gb* gb, int x, T y) {
	assert(0 <= x && x <= 7);

	F.Z.set(gb, !get_bit(y.get(gb), x));
	F.N.reset(gb);
	F.H.set(gb);
}

// UM0080.pdf rev 11 p295 / 332
template<typename T>
void CALL(gb* gb, T x) {
	const u16 jump_location = x.get(gb);

	SP.set(gb, SP.get(gb) - 1);
	const u8 big_end = PC.get(gb) >> 8;
	mem_set(gb, SP.get(gb), big_end);

	SP.set(gb, SP.get(gb) - 1);
	const u8 little_end = static_cast<u8>(PC.get(gb));
	mem_set(gb, SP.get(gb), little_end);

	PC.set(gb, jump_location);
}

// UM0080.pdf rev 11 p177 / 332
template<typename T>
void CP(gb* gb, T x) {
	const u8 v1 = A.get(gb);
	const u8 v2 = x.get(gb);

	F.Z.set(gb, v1 == v2);
	F.N.set(gb);
	F.H.set(gb, half_borrow(v1, v2));
	F.C.set(gb, borrow(v1, v2));
}

// UM0080.pdf rev 11 p184 / 332
template<typename T>
void DEC(gb* gb, T x) {
	const u8 v1 = x.get(gb);
	const u8 v2 = 1;

	const u8 result = v1 - v2;
	x.set(gb, result);

	F.Z.set(gb, result == 0x00);
	F.N.set(gb);
	F.H.set(gb, half_borrow(v1, v2));
}

// UM0080.pdf rev 11 p179,181 / 332
template<typename T>
void INC_u8(gb* gb, T x) {
	const u8 v1 = x.get(gb);
	const u8 v2 = 1;

	const u8 result = v1 + v2;
	x.set(gb, result);

	F.Z.set(gb, result == 0x00);
	F.N.reset(gb);
	F.H.set(gb, half_carry(v1, v2));
}

// UM0080.pdf rev 11 p212 / 332
template<typename T>
void INC_u16(gb* gb, T x) {
	x.set(gb, x.get(gb) + 1);
}

// UM0080.pdf rev 11 p279 / 332
template<typename T>
void JR(gb* gb, T x) {
	const i8 offset = x.get(gb);
	const u16 jump_location = static_cast<u16>(PC.get(gb) + offset);
	PC.set(gb, jump_location);
}

// UM0080.pdf rev 11 p281,283,285,287 / 332
template<typename T1, typename T2>
void JR(gb* gb, T1 x, T2 y) {
	const i8 offset = y.get(gb);
	if (x.get(gb)) {
		const u16 jump_location = static_cast<u16>(PC.get(gb) + offset);
		PC.set(gb, jump_location);
	}
}

template<typename T1, typename T2>
void LD(gb* gb, T1 x, T2 y) {
	x.set(gb, y.get(gb));
}

// pandocs
// ldd  (HL),A      32         8 ---- (HL)=A, HL=HL-1
// ldd  A,(HL)      3A         8 ---- A=(HL), HL=HL-1
template<typename T1, typename T2>
void LDD(gb* gb, T1 x, T2 y) {
	x.set(gb, y.get(gb));
	HL.set(gb, HL.get(gb) - 1);
}

// pandocs
// ldi  (HL),A      22         8 ---- (HL)=A, HL=HL+1
// ldi  A,(HL)      2A         8 ---- A=(HL), HL=HL+1
template<typename T1, typename T2>
void LDI(gb* gb, T1 x, T2 y) {
	x.set(gb, y.get(gb));
	HL.set(gb, HL.get(gb) + 1);
}

// UM0080.pdf rev 11 p133 / 332
template<typename T>
void POP(gb* gb, T x) {
	const u8 little_end = mem_read(gb, SP.get(gb));
	SP.set(gb, SP.get(gb) + 1);

	const u8 big_end = mem_read(gb, SP.get(gb));
	SP.set(gb, SP.get(gb) + 1);

	const u16 result = static_cast<u16>((big_end << 8) | little_end);
	x.set(gb, result);
}

// UM0080.pdf rev 11 p129 / 332
template<typename T>
void PUSH(gb* gb, T x) {
	const u16 value = x.get(gb);

	SP.set(gb, SP.get(gb) - 1);
	const u8 big_end = value >> 8;
	mem_set(gb, SP.get(gb), big_end);

	SP.set(gb, SP.get(gb) - 1);
	const u8 little_end = static_cast<u8>(value);
	mem_set(gb, SP.get(gb), little_end);
}

// UM0080.pdf rev 11 p299 / 332
void RET(gb* gb) {
	const u8 little_end = mem_read(gb, SP.get(gb));
	SP.set(gb, SP.get(gb) + 1);

	const u8 big_end = mem_read(gb, SP.get(gb));
	SP.set(gb, SP.get(gb) + 1);

	const u16 result = static_cast<u16>((big_end << 8) | little_end);
	PC.set(gb, result);
}

// UM0080.pdf rev 11 p235 / 332
template<typename T>
void RL(gb* gb, T x) {
	const u8 old_value = x.get(gb);
	const bool old_bit_7 = get_bit(old_value, 7);
	const bool old_carry_flag = F.C.get(gb);

	const u8 new_value = static_cast<u8>((old_value << 1) | old_carry_flag);
	x.set(gb, new_value);

	F.Z.set(gb, new_value == 0x00);
	F.N.reset(gb);
	F.H.reset(gb);
	F.C.set(gb, old_bit_7);
}

// UM0080.pdf rev 11 p221 / 332
void RLA(gb* gb) {
	const u8 old_value = A.get(gb);
	const bool old_bit_7 = get_bit(old_value, 7);
	const bool old_carry_flag = F.C.get(gb);

	const u8 new_value = static_cast<u8>((old_value << 1) | old_carry_flag);
	A.set(gb, new_value);

	F.N.reset(gb);
	F.H.reset(gb);
	F.C.set(gb, old_bit_7);
}

// UM0080.pdf rev 11 p167 / 332
template<typename T>
void SUB(gb* gb, T x) {
	const u8 v1 = A.get(gb);
	const u8 v2 = x.get(gb);

	const u8 result = v1 - v2;
	A.set(gb, result);

	F.Z.set(gb, result == 0x00);
	F.N.set(gb);
	F.H.set(gb, half_borrow(v1, v2));
	F.C.set(gb, borrow(v1, v2));
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

	const u8 opcode = mem_read(gb, PC.get(gb));
	PC.set(gb, PC.get(gb) + 1);

	if (opcode != 0xCB) {
		switch (opcode) {
		#include "opcodes.cpp"
		default:
			char binary_opcode[9];
			binary_repr(opcode, binary_opcode);
			panic("Unknown opcode 0x%02X=0b%s at 0x%04X.",
				opcode, binary_opcode, PC_0);
			break;
		}
	} else {
		const u8 extended_opcode = mem_read(gb, PC.get(gb));
		PC.set(gb, PC.get(gb) + 1);

		switch (extended_opcode) {
		#include "extended_opcodes.cpp"
		default:
			char binary_extended_opcode[9];
			binary_repr(extended_opcode, binary_extended_opcode);
			panic("Unknown extended opcode 0xCB-0x%02X=0b%s at 0x%04X.",
				extended_opcode, binary_extended_opcode, PC_0);
			break;
		}
	}
}
