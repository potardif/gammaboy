// ----------------
// 16-bit registers
// ----------------

class reg16 {
private:
	const int i;
	const u16 mask;

public:
	reg16(int p_i);
	u16 get(const gb* gb) const;
	void set(gb* gb, u16 value) const;
};

reg16::reg16(int p_i) :
	i(p_i),
	mask(p_i == AF_i ? 0xFFF0 : 0xFFFF) // The last 4 bits of F are always 0.
{}

u16 reg16::get(const gb* gb) const {
	return gb->regs[i] & mask;
}

void reg16::set(gb* gb, u16 value) const {
	gb->regs[i] = value & mask;
}

const reg16 AF(AF_i);
const reg16 BC(BC_i);
const reg16 DE(DE_i);
const reg16 HL(HL_i);
const reg16 PC(PC_i); // Program Counter
const reg16 SP(SP_i); // Stack Pointer

// --------------------
// High 8-bit registers
// --------------------

class hi_reg8 {
private:
	const reg16* parent;

public:
	hi_reg8(const reg16* p_parent);
	u8 get(const gb* gb) const;
	void set(gb* gb, u8 value) const;
};

hi_reg8::hi_reg8(const reg16* p_parent) :
	parent(p_parent)
{}

u8 hi_reg8::get(const gb* gb) const {
	return parent->get(gb) >> 8;
}

void hi_reg8::set(gb* gb, u8 value) const {
	u16 payload = parent->get(gb);
	payload &= 0x00FF;
	payload |= value << 8;
	parent->set(gb, payload);
}

const hi_reg8 A(&AF); // Accumulator
const hi_reg8 B(&BC);
const hi_reg8 D(&DE);
const hi_reg8 H(&HL);

// -------------------
// Low 8-bit registers
// -------------------

class lo_reg8 {
private:
	const reg16* parent;

public:
	lo_reg8(const reg16* p_parent);
	u8 get(const gb* gb) const;
	void set(gb* gb, u8 value) const;
};

lo_reg8::lo_reg8(const reg16* p_parent) :
	parent(p_parent)
{}

u8 lo_reg8::get(const gb* gb) const {
	return static_cast<u8>(parent->get(gb));
}

void lo_reg8::set(gb* gb, u8 value) const {
	u16 payload = parent->get(gb);
	payload &= 0xFF00;
	payload |= value;
	parent->set(gb, payload);
}

const lo_reg8 C(&BC);
const lo_reg8 E(&DE);
const lo_reg8 L(&HL);

// -----------------------
// Flags and Flag register
// -----------------------

class flag {
private:
	const int bit;

public:
	flag(int p_bit);
	bool get(const gb* gb) const;
	void set(gb* gb, bool value) const;
	void set(gb* gb) const;
	void reset(gb* gb) const;
};

flag::flag(int p_bit) :
	bit(p_bit)
{}

bool flag::get(const gb* gb) const {
	return get_bit(AF.get(gb), bit);
}

void flag::set(gb* gb, bool value) const {
	u16 payload = AF.get(gb);
	payload = set_bit(payload, bit, value);
	AF.set(gb, payload);
}

void flag::set(gb* gb) const {
	set(gb, true);
}

void flag::reset(gb* gb) const {
	set(gb, false);
}

// Negative flag
class nflag {
private:
	const int bit;

public:
	nflag(int p_bit);
	bool get(const gb* gb) const;
};

nflag::nflag(int p_bit) :
	bit(p_bit)
{}

bool nflag::get(const gb* gb) const {
	return !get_bit(AF.get(gb), bit);
}

class F : public lo_reg8 {
public:
	const flag Z; // Zero flag
	const flag N; // Negative flag
	const flag H; // Half-carry flag
	const flag C; // Carry flag

	const nflag NZ; // Negative Zero flag
	const nflag NC; // Negative Carry flag

	F();
};

F::F() :
	lo_reg8(&AF),
	Z(7),
	N(6),
	H(5),
	C(4),
	NZ(7),
	NC(4)
{}

const F F; // Flag register
