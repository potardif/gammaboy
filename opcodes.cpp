case 0x01:
	if (gb->log) {
		printf("LD BC, imm_u16\n");
	}
	LD(gb, BC, imm_u16);
	break;
case 0x02:
	if (gb->log) {
		printf("LD mem(BC), A\n");
	}
	LD(gb, mem(BC), A);
	break;
case 0x03:
	if (gb->log) {
		printf("INC_u16 BC\n");
	}
	INC_u16(gb, BC);
	break;
case 0x04:
	if (gb->log) {
		printf("INC_u8 B\n");
	}
	INC_u8(gb, B);
	break;
case 0x05:
	if (gb->log) {
		printf("DEC B\n");
	}
	DEC(gb, B);
	break;
case 0x06:
	if (gb->log) {
		printf("LD B, imm_u8\n");
	}
	LD(gb, B, imm_u8);
	break;
case 0x0A:
	if (gb->log) {
		printf("LD A, mem(BC)\n");
	}
	LD(gb, A, mem(BC));
	break;
case 0x0C:
	if (gb->log) {
		printf("INC_u8 C\n");
	}
	INC_u8(gb, C);
	break;
case 0x0D:
	if (gb->log) {
		printf("DEC C\n");
	}
	DEC(gb, C);
	break;
case 0x0E:
	if (gb->log) {
		printf("LD C, imm_u8\n");
	}
	LD(gb, C, imm_u8);
	break;
case 0x11:
	if (gb->log) {
		printf("LD DE, imm_u16\n");
	}
	LD(gb, DE, imm_u16);
	break;
case 0x12:
	if (gb->log) {
		printf("LD mem(DE), A\n");
	}
	LD(gb, mem(DE), A);
	break;
case 0x13:
	if (gb->log) {
		printf("INC_u16 DE\n");
	}
	INC_u16(gb, DE);
	break;
case 0x14:
	if (gb->log) {
		printf("INC_u8 D\n");
	}
	INC_u8(gb, D);
	break;
case 0x15:
	if (gb->log) {
		printf("DEC D\n");
	}
	DEC(gb, D);
	break;
case 0x16:
	if (gb->log) {
		printf("LD D, imm_u8\n");
	}
	LD(gb, D, imm_u8);
	break;
case 0x17:
	if (gb->log) {
		printf("RLA\n");
	}
	RLA(gb);
	break;
case 0x18:
	if (gb->log) {
		printf("JR imm_i8\n");
	}
	JR(gb, imm_i8);
	break;
case 0x1A:
	if (gb->log) {
		printf("LD A, mem(DE)\n");
	}
	LD(gb, A, mem(DE));
	break;
case 0x1C:
	if (gb->log) {
		printf("INC_u8 E\n");
	}
	INC_u8(gb, E);
	break;
case 0x1D:
	if (gb->log) {
		printf("DEC E\n");
	}
	DEC(gb, E);
	break;
case 0x1E:
	if (gb->log) {
		printf("LD E, imm_u8\n");
	}
	LD(gb, E, imm_u8);
	break;
case 0x20:
	if (gb->log) {
		printf("JR F.NZ, imm_i8\n");
	}
	JR(gb, F.NZ, imm_i8);
	break;
case 0x21:
	if (gb->log) {
		printf("LD HL, imm_u16\n");
	}
	LD(gb, HL, imm_u16);
	break;
case 0x22:
	if (gb->log) {
		printf("LDI mem(HL), A\n");
	}
	LDI(gb, mem(HL), A);
	break;
case 0x23:
	if (gb->log) {
		printf("INC_u16 HL\n");
	}
	INC_u16(gb, HL);
	break;
case 0x24:
	if (gb->log) {
		printf("INC_u8 H\n");
	}
	INC_u8(gb, H);
	break;
case 0x25:
	if (gb->log) {
		printf("DEC H\n");
	}
	DEC(gb, H);
	break;
case 0x26:
	if (gb->log) {
		printf("LD H, imm_u8\n");
	}
	LD(gb, H, imm_u8);
	break;
case 0x28:
	if (gb->log) {
		printf("JR F.Z, imm_i8\n");
	}
	JR(gb, F.Z, imm_i8);
	break;
case 0x2A:
	if (gb->log) {
		printf("LDI A, mem(HL)\n");
	}
	LDI(gb, A, mem(HL));
	break;
case 0x2C:
	if (gb->log) {
		printf("INC_u8 L\n");
	}
	INC_u8(gb, L);
	break;
case 0x2D:
	if (gb->log) {
		printf("DEC L\n");
	}
	DEC(gb, L);
	break;
case 0x2E:
	if (gb->log) {
		printf("LD L, imm_u8\n");
	}
	LD(gb, L, imm_u8);
	break;
case 0x30:
	if (gb->log) {
		printf("JR F.NC, imm_i8\n");
	}
	JR(gb, F.NC, imm_i8);
	break;
case 0x31:
	if (gb->log) {
		printf("LD SP, imm_u16\n");
	}
	LD(gb, SP, imm_u16);
	break;
case 0x32:
	if (gb->log) {
		printf("LDD mem(HL), A\n");
	}
	LDD(gb, mem(HL), A);
	break;
case 0x33:
	if (gb->log) {
		printf("INC_u16 SP\n");
	}
	INC_u16(gb, SP);
	break;
case 0x34:
	if (gb->log) {
		printf("INC_u8 mem(HL)\n");
	}
	INC_u8(gb, mem(HL));
	break;
case 0x35:
	if (gb->log) {
		printf("DEC mem(HL)\n");
	}
	DEC(gb, mem(HL));
	break;
case 0x36:
	if (gb->log) {
		printf("LD mem(HL), imm_u8\n");
	}
	LD(gb, mem(HL), imm_u8);
	break;
case 0x38:
	if (gb->log) {
		printf("JR F.C, imm_i8\n");
	}
	JR(gb, F.C, imm_i8);
	break;
case 0x3A:
	if (gb->log) {
		printf("LDD A, mem(HL)\n");
	}
	LDD(gb, A, mem(HL));
	break;
case 0x3C:
	if (gb->log) {
		printf("INC_u8 A\n");
	}
	INC_u8(gb, A);
	break;
case 0x3D:
	if (gb->log) {
		printf("DEC A\n");
	}
	DEC(gb, A);
	break;
case 0x3E:
	if (gb->log) {
		printf("LD A, imm_u8\n");
	}
	LD(gb, A, imm_u8);
	break;
case 0x40:
	if (gb->log) {
		printf("LD B, B\n");
	}
	LD(gb, B, B);
	break;
case 0x41:
	if (gb->log) {
		printf("LD B, C\n");
	}
	LD(gb, B, C);
	break;
case 0x42:
	if (gb->log) {
		printf("LD B, D\n");
	}
	LD(gb, B, D);
	break;
case 0x43:
	if (gb->log) {
		printf("LD B, E\n");
	}
	LD(gb, B, E);
	break;
case 0x44:
	if (gb->log) {
		printf("LD B, H\n");
	}
	LD(gb, B, H);
	break;
case 0x45:
	if (gb->log) {
		printf("LD B, L\n");
	}
	LD(gb, B, L);
	break;
case 0x46:
	if (gb->log) {
		printf("LD B, mem(HL)\n");
	}
	LD(gb, B, mem(HL));
	break;
case 0x47:
	if (gb->log) {
		printf("LD B, A\n");
	}
	LD(gb, B, A);
	break;
case 0x48:
	if (gb->log) {
		printf("LD C, B\n");
	}
	LD(gb, C, B);
	break;
case 0x49:
	if (gb->log) {
		printf("LD C, C\n");
	}
	LD(gb, C, C);
	break;
case 0x4A:
	if (gb->log) {
		printf("LD C, D\n");
	}
	LD(gb, C, D);
	break;
case 0x4B:
	if (gb->log) {
		printf("LD C, E\n");
	}
	LD(gb, C, E);
	break;
case 0x4C:
	if (gb->log) {
		printf("LD C, H\n");
	}
	LD(gb, C, H);
	break;
case 0x4D:
	if (gb->log) {
		printf("LD C, L\n");
	}
	LD(gb, C, L);
	break;
case 0x4E:
	if (gb->log) {
		printf("LD C, mem(HL)\n");
	}
	LD(gb, C, mem(HL));
	break;
case 0x4F:
	if (gb->log) {
		printf("LD C, A\n");
	}
	LD(gb, C, A);
	break;
case 0x50:
	if (gb->log) {
		printf("LD D, B\n");
	}
	LD(gb, D, B);
	break;
case 0x51:
	if (gb->log) {
		printf("LD D, C\n");
	}
	LD(gb, D, C);
	break;
case 0x52:
	if (gb->log) {
		printf("LD D, D\n");
	}
	LD(gb, D, D);
	break;
case 0x53:
	if (gb->log) {
		printf("LD D, E\n");
	}
	LD(gb, D, E);
	break;
case 0x54:
	if (gb->log) {
		printf("LD D, H\n");
	}
	LD(gb, D, H);
	break;
case 0x55:
	if (gb->log) {
		printf("LD D, L\n");
	}
	LD(gb, D, L);
	break;
case 0x56:
	if (gb->log) {
		printf("LD D, mem(HL)\n");
	}
	LD(gb, D, mem(HL));
	break;
case 0x57:
	if (gb->log) {
		printf("LD D, A\n");
	}
	LD(gb, D, A);
	break;
case 0x58:
	if (gb->log) {
		printf("LD E, B\n");
	}
	LD(gb, E, B);
	break;
case 0x59:
	if (gb->log) {
		printf("LD E, C\n");
	}
	LD(gb, E, C);
	break;
case 0x5A:
	if (gb->log) {
		printf("LD E, D\n");
	}
	LD(gb, E, D);
	break;
case 0x5B:
	if (gb->log) {
		printf("LD E, E\n");
	}
	LD(gb, E, E);
	break;
case 0x5C:
	if (gb->log) {
		printf("LD E, H\n");
	}
	LD(gb, E, H);
	break;
case 0x5D:
	if (gb->log) {
		printf("LD E, L\n");
	}
	LD(gb, E, L);
	break;
case 0x5E:
	if (gb->log) {
		printf("LD E, mem(HL)\n");
	}
	LD(gb, E, mem(HL));
	break;
case 0x5F:
	if (gb->log) {
		printf("LD E, A\n");
	}
	LD(gb, E, A);
	break;
case 0x60:
	if (gb->log) {
		printf("LD H, B\n");
	}
	LD(gb, H, B);
	break;
case 0x61:
	if (gb->log) {
		printf("LD H, C\n");
	}
	LD(gb, H, C);
	break;
case 0x62:
	if (gb->log) {
		printf("LD H, D\n");
	}
	LD(gb, H, D);
	break;
case 0x63:
	if (gb->log) {
		printf("LD H, E\n");
	}
	LD(gb, H, E);
	break;
case 0x64:
	if (gb->log) {
		printf("LD H, H\n");
	}
	LD(gb, H, H);
	break;
case 0x65:
	if (gb->log) {
		printf("LD H, L\n");
	}
	LD(gb, H, L);
	break;
case 0x66:
	if (gb->log) {
		printf("LD H, mem(HL)\n");
	}
	LD(gb, H, mem(HL));
	break;
case 0x67:
	if (gb->log) {
		printf("LD H, A\n");
	}
	LD(gb, H, A);
	break;
case 0x68:
	if (gb->log) {
		printf("LD L, B\n");
	}
	LD(gb, L, B);
	break;
case 0x69:
	if (gb->log) {
		printf("LD L, C\n");
	}
	LD(gb, L, C);
	break;
case 0x6A:
	if (gb->log) {
		printf("LD L, D\n");
	}
	LD(gb, L, D);
	break;
case 0x6B:
	if (gb->log) {
		printf("LD L, E\n");
	}
	LD(gb, L, E);
	break;
case 0x6C:
	if (gb->log) {
		printf("LD L, H\n");
	}
	LD(gb, L, H);
	break;
case 0x6D:
	if (gb->log) {
		printf("LD L, L\n");
	}
	LD(gb, L, L);
	break;
case 0x6E:
	if (gb->log) {
		printf("LD L, mem(HL)\n");
	}
	LD(gb, L, mem(HL));
	break;
case 0x6F:
	if (gb->log) {
		printf("LD L, A\n");
	}
	LD(gb, L, A);
	break;
case 0x70:
	if (gb->log) {
		printf("LD mem(HL), B\n");
	}
	LD(gb, mem(HL), B);
	break;
case 0x71:
	if (gb->log) {
		printf("LD mem(HL), C\n");
	}
	LD(gb, mem(HL), C);
	break;
case 0x72:
	if (gb->log) {
		printf("LD mem(HL), D\n");
	}
	LD(gb, mem(HL), D);
	break;
case 0x73:
	if (gb->log) {
		printf("LD mem(HL), E\n");
	}
	LD(gb, mem(HL), E);
	break;
case 0x74:
	if (gb->log) {
		printf("LD mem(HL), H\n");
	}
	LD(gb, mem(HL), H);
	break;
case 0x75:
	if (gb->log) {
		printf("LD mem(HL), L\n");
	}
	LD(gb, mem(HL), L);
	break;
case 0x77:
	if (gb->log) {
		printf("LD mem(HL), A\n");
	}
	LD(gb, mem(HL), A);
	break;
case 0x78:
	if (gb->log) {
		printf("LD A, B\n");
	}
	LD(gb, A, B);
	break;
case 0x79:
	if (gb->log) {
		printf("LD A, C\n");
	}
	LD(gb, A, C);
	break;
case 0x7A:
	if (gb->log) {
		printf("LD A, D\n");
	}
	LD(gb, A, D);
	break;
case 0x7B:
	if (gb->log) {
		printf("LD A, E\n");
	}
	LD(gb, A, E);
	break;
case 0x7C:
	if (gb->log) {
		printf("LD A, H\n");
	}
	LD(gb, A, H);
	break;
case 0x7D:
	if (gb->log) {
		printf("LD A, L\n");
	}
	LD(gb, A, L);
	break;
case 0x7E:
	if (gb->log) {
		printf("LD A, mem(HL)\n");
	}
	LD(gb, A, mem(HL));
	break;
case 0x7F:
	if (gb->log) {
		printf("LD A, A\n");
	}
	LD(gb, A, A);
	break;
case 0x80:
	if (gb->log) {
		printf("ADD B\n");
	}
	ADD(gb, B);
	break;
case 0x81:
	if (gb->log) {
		printf("ADD C\n");
	}
	ADD(gb, C);
	break;
case 0x82:
	if (gb->log) {
		printf("ADD D\n");
	}
	ADD(gb, D);
	break;
case 0x83:
	if (gb->log) {
		printf("ADD E\n");
	}
	ADD(gb, E);
	break;
case 0x84:
	if (gb->log) {
		printf("ADD H\n");
	}
	ADD(gb, H);
	break;
case 0x85:
	if (gb->log) {
		printf("ADD L\n");
	}
	ADD(gb, L);
	break;
case 0x86:
	if (gb->log) {
		printf("ADD mem(HL)\n");
	}
	ADD(gb, mem(HL));
	break;
case 0x87:
	if (gb->log) {
		printf("ADD A\n");
	}
	ADD(gb, A);
	break;
case 0x90:
	if (gb->log) {
		printf("SUB B\n");
	}
	SUB(gb, B);
	break;
case 0x91:
	if (gb->log) {
		printf("SUB C\n");
	}
	SUB(gb, C);
	break;
case 0x92:
	if (gb->log) {
		printf("SUB D\n");
	}
	SUB(gb, D);
	break;
case 0x93:
	if (gb->log) {
		printf("SUB E\n");
	}
	SUB(gb, E);
	break;
case 0x94:
	if (gb->log) {
		printf("SUB H\n");
	}
	SUB(gb, H);
	break;
case 0x95:
	if (gb->log) {
		printf("SUB L\n");
	}
	SUB(gb, L);
	break;
case 0x96:
	if (gb->log) {
		printf("SUB mem(HL)\n");
	}
	SUB(gb, mem(HL));
	break;
case 0x97:
	if (gb->log) {
		printf("SUB A\n");
	}
	SUB(gb, A);
	break;
case 0xA8:
	if (gb->log) {
		printf("XOR B\n");
	}
	XOR(gb, B);
	break;
case 0xA9:
	if (gb->log) {
		printf("XOR C\n");
	}
	XOR(gb, C);
	break;
case 0xAA:
	if (gb->log) {
		printf("XOR D\n");
	}
	XOR(gb, D);
	break;
case 0xAB:
	if (gb->log) {
		printf("XOR E\n");
	}
	XOR(gb, E);
	break;
case 0xAC:
	if (gb->log) {
		printf("XOR H\n");
	}
	XOR(gb, H);
	break;
case 0xAD:
	if (gb->log) {
		printf("XOR L\n");
	}
	XOR(gb, L);
	break;
case 0xAE:
	if (gb->log) {
		printf("XOR mem(HL)\n");
	}
	XOR(gb, mem(HL));
	break;
case 0xAF:
	if (gb->log) {
		printf("XOR A\n");
	}
	XOR(gb, A);
	break;
case 0xB8:
	if (gb->log) {
		printf("CP B\n");
	}
	CP(gb, B);
	break;
case 0xB9:
	if (gb->log) {
		printf("CP C\n");
	}
	CP(gb, C);
	break;
case 0xBA:
	if (gb->log) {
		printf("CP D\n");
	}
	CP(gb, D);
	break;
case 0xBB:
	if (gb->log) {
		printf("CP E\n");
	}
	CP(gb, E);
	break;
case 0xBC:
	if (gb->log) {
		printf("CP H\n");
	}
	CP(gb, H);
	break;
case 0xBD:
	if (gb->log) {
		printf("CP L\n");
	}
	CP(gb, L);
	break;
case 0xBE:
	if (gb->log) {
		printf("CP mem(HL)\n");
	}
	CP(gb, mem(HL));
	break;
case 0xBF:
	if (gb->log) {
		printf("CP A\n");
	}
	CP(gb, A);
	break;
case 0xC1:
	if (gb->log) {
		printf("POP BC\n");
	}
	POP(gb, BC);
	break;
case 0xC5:
	if (gb->log) {
		printf("PUSH BC\n");
	}
	PUSH(gb, BC);
	break;
case 0xC6:
	if (gb->log) {
		printf("ADD imm_u8\n");
	}
	ADD(gb, imm_u8);
	break;
case 0xC9:
	if (gb->log) {
		printf("RET\n");
	}
	RET(gb);
	break;
case 0xCD:
	if (gb->log) {
		printf("CALL imm_u16\n");
	}
	CALL(gb, imm_u16);
	break;
case 0xD1:
	if (gb->log) {
		printf("POP DE\n");
	}
	POP(gb, DE);
	break;
case 0xD5:
	if (gb->log) {
		printf("PUSH DE\n");
	}
	PUSH(gb, DE);
	break;
case 0xD6:
	if (gb->log) {
		printf("SUB imm_u8\n");
	}
	SUB(gb, imm_u8);
	break;
case 0xE0:
	if (gb->log) {
		printf("LD mem(FF00(imm_u8)), A\n");
	}
	LD(gb, mem(FF00(imm_u8)), A);
	break;
case 0xE1:
	if (gb->log) {
		printf("POP HL\n");
	}
	POP(gb, HL);
	break;
case 0xE2:
	if (gb->log) {
		printf("LD mem(FF00(C)), A\n");
	}
	LD(gb, mem(FF00(C)), A);
	break;
case 0xE5:
	if (gb->log) {
		printf("PUSH HL\n");
	}
	PUSH(gb, HL);
	break;
case 0xEA:
	if (gb->log) {
		printf("LD mem(imm_u16), A\n");
	}
	LD(gb, mem(imm_u16), A);
	break;
case 0xEE:
	if (gb->log) {
		printf("XOR imm_u8\n");
	}
	XOR(gb, imm_u8);
	break;
case 0xF0:
	if (gb->log) {
		printf("LD A, mem(FF00(imm_u8))\n");
	}
	LD(gb, A, mem(FF00(imm_u8)));
	break;
case 0xF1:
	if (gb->log) {
		printf("POP AF\n");
	}
	POP(gb, AF);
	break;
case 0xF2:
	if (gb->log) {
		printf("LD A, mem(FF00(C))\n");
	}
	LD(gb, A, mem(FF00(C)));
	break;
case 0xF5:
	if (gb->log) {
		printf("PUSH AF\n");
	}
	PUSH(gb, AF);
	break;
case 0xFA:
	if (gb->log) {
		printf("LD A, mem(imm_u16)\n");
	}
	LD(gb, A, mem(imm_u16));
	break;
case 0xFE:
	if (gb->log) {
		printf("CP imm_u8\n");
	}
	CP(gb, imm_u8);
	break;
