const int AF_i = 0;
const int BC_i = 1;
const int DE_i = 2;
const int HL_i = 3;
const int PC_i = 4;
const int SP_i = 5;

class gb {
public:
	u16 regs[6] = {
		[AF_i] = 0x0000,
		[BC_i] = 0x0000,
		[DE_i] = 0x0000,
		[HL_i] = 0x0000,
		[PC_i] = 0x0000,
		[SP_i] = 0x0000,
	};
};
