case 0x10:
	if (gb->log) {
		printf("RL B\n");
	}
	RL(gb, B);
	break;
case 0x11:
	if (gb->log) {
		printf("RL C\n");
	}
	RL(gb, C);
	break;
case 0x12:
	if (gb->log) {
		printf("RL D\n");
	}
	RL(gb, D);
	break;
case 0x13:
	if (gb->log) {
		printf("RL E\n");
	}
	RL(gb, E);
	break;
case 0x14:
	if (gb->log) {
		printf("RL H\n");
	}
	RL(gb, H);
	break;
case 0x15:
	if (gb->log) {
		printf("RL L\n");
	}
	RL(gb, L);
	break;
case 0x16:
	if (gb->log) {
		printf("RL mem(HL)\n");
	}
	RL(gb, mem(HL));
	break;
case 0x17:
	if (gb->log) {
		printf("RL A\n");
	}
	RL(gb, A);
	break;
case 0x40:
	if (gb->log) {
		printf("BIT 0, B\n");
	}
	BIT(gb, 0, B);
	break;
case 0x41:
	if (gb->log) {
		printf("BIT 0, C\n");
	}
	BIT(gb, 0, C);
	break;
case 0x42:
	if (gb->log) {
		printf("BIT 0, D\n");
	}
	BIT(gb, 0, D);
	break;
case 0x43:
	if (gb->log) {
		printf("BIT 0, E\n");
	}
	BIT(gb, 0, E);
	break;
case 0x44:
	if (gb->log) {
		printf("BIT 0, H\n");
	}
	BIT(gb, 0, H);
	break;
case 0x45:
	if (gb->log) {
		printf("BIT 0, L\n");
	}
	BIT(gb, 0, L);
	break;
case 0x46:
	if (gb->log) {
		printf("BIT 0, mem(HL)\n");
	}
	BIT(gb, 0, mem(HL));
	break;
case 0x47:
	if (gb->log) {
		printf("BIT 0, A\n");
	}
	BIT(gb, 0, A);
	break;
case 0x48:
	if (gb->log) {
		printf("BIT 1, B\n");
	}
	BIT(gb, 1, B);
	break;
case 0x49:
	if (gb->log) {
		printf("BIT 1, C\n");
	}
	BIT(gb, 1, C);
	break;
case 0x4A:
	if (gb->log) {
		printf("BIT 1, D\n");
	}
	BIT(gb, 1, D);
	break;
case 0x4B:
	if (gb->log) {
		printf("BIT 1, E\n");
	}
	BIT(gb, 1, E);
	break;
case 0x4C:
	if (gb->log) {
		printf("BIT 1, H\n");
	}
	BIT(gb, 1, H);
	break;
case 0x4D:
	if (gb->log) {
		printf("BIT 1, L\n");
	}
	BIT(gb, 1, L);
	break;
case 0x4E:
	if (gb->log) {
		printf("BIT 1, mem(HL)\n");
	}
	BIT(gb, 1, mem(HL));
	break;
case 0x4F:
	if (gb->log) {
		printf("BIT 1, A\n");
	}
	BIT(gb, 1, A);
	break;
case 0x50:
	if (gb->log) {
		printf("BIT 2, B\n");
	}
	BIT(gb, 2, B);
	break;
case 0x51:
	if (gb->log) {
		printf("BIT 2, C\n");
	}
	BIT(gb, 2, C);
	break;
case 0x52:
	if (gb->log) {
		printf("BIT 2, D\n");
	}
	BIT(gb, 2, D);
	break;
case 0x53:
	if (gb->log) {
		printf("BIT 2, E\n");
	}
	BIT(gb, 2, E);
	break;
case 0x54:
	if (gb->log) {
		printf("BIT 2, H\n");
	}
	BIT(gb, 2, H);
	break;
case 0x55:
	if (gb->log) {
		printf("BIT 2, L\n");
	}
	BIT(gb, 2, L);
	break;
case 0x56:
	if (gb->log) {
		printf("BIT 2, mem(HL)\n");
	}
	BIT(gb, 2, mem(HL));
	break;
case 0x57:
	if (gb->log) {
		printf("BIT 2, A\n");
	}
	BIT(gb, 2, A);
	break;
case 0x58:
	if (gb->log) {
		printf("BIT 3, B\n");
	}
	BIT(gb, 3, B);
	break;
case 0x59:
	if (gb->log) {
		printf("BIT 3, C\n");
	}
	BIT(gb, 3, C);
	break;
case 0x5A:
	if (gb->log) {
		printf("BIT 3, D\n");
	}
	BIT(gb, 3, D);
	break;
case 0x5B:
	if (gb->log) {
		printf("BIT 3, E\n");
	}
	BIT(gb, 3, E);
	break;
case 0x5C:
	if (gb->log) {
		printf("BIT 3, H\n");
	}
	BIT(gb, 3, H);
	break;
case 0x5D:
	if (gb->log) {
		printf("BIT 3, L\n");
	}
	BIT(gb, 3, L);
	break;
case 0x5E:
	if (gb->log) {
		printf("BIT 3, mem(HL)\n");
	}
	BIT(gb, 3, mem(HL));
	break;
case 0x5F:
	if (gb->log) {
		printf("BIT 3, A\n");
	}
	BIT(gb, 3, A);
	break;
case 0x60:
	if (gb->log) {
		printf("BIT 4, B\n");
	}
	BIT(gb, 4, B);
	break;
case 0x61:
	if (gb->log) {
		printf("BIT 4, C\n");
	}
	BIT(gb, 4, C);
	break;
case 0x62:
	if (gb->log) {
		printf("BIT 4, D\n");
	}
	BIT(gb, 4, D);
	break;
case 0x63:
	if (gb->log) {
		printf("BIT 4, E\n");
	}
	BIT(gb, 4, E);
	break;
case 0x64:
	if (gb->log) {
		printf("BIT 4, H\n");
	}
	BIT(gb, 4, H);
	break;
case 0x65:
	if (gb->log) {
		printf("BIT 4, L\n");
	}
	BIT(gb, 4, L);
	break;
case 0x66:
	if (gb->log) {
		printf("BIT 4, mem(HL)\n");
	}
	BIT(gb, 4, mem(HL));
	break;
case 0x67:
	if (gb->log) {
		printf("BIT 4, A\n");
	}
	BIT(gb, 4, A);
	break;
case 0x68:
	if (gb->log) {
		printf("BIT 5, B\n");
	}
	BIT(gb, 5, B);
	break;
case 0x69:
	if (gb->log) {
		printf("BIT 5, C\n");
	}
	BIT(gb, 5, C);
	break;
case 0x6A:
	if (gb->log) {
		printf("BIT 5, D\n");
	}
	BIT(gb, 5, D);
	break;
case 0x6B:
	if (gb->log) {
		printf("BIT 5, E\n");
	}
	BIT(gb, 5, E);
	break;
case 0x6C:
	if (gb->log) {
		printf("BIT 5, H\n");
	}
	BIT(gb, 5, H);
	break;
case 0x6D:
	if (gb->log) {
		printf("BIT 5, L\n");
	}
	BIT(gb, 5, L);
	break;
case 0x6E:
	if (gb->log) {
		printf("BIT 5, mem(HL)\n");
	}
	BIT(gb, 5, mem(HL));
	break;
case 0x6F:
	if (gb->log) {
		printf("BIT 5, A\n");
	}
	BIT(gb, 5, A);
	break;
case 0x70:
	if (gb->log) {
		printf("BIT 6, B\n");
	}
	BIT(gb, 6, B);
	break;
case 0x71:
	if (gb->log) {
		printf("BIT 6, C\n");
	}
	BIT(gb, 6, C);
	break;
case 0x72:
	if (gb->log) {
		printf("BIT 6, D\n");
	}
	BIT(gb, 6, D);
	break;
case 0x73:
	if (gb->log) {
		printf("BIT 6, E\n");
	}
	BIT(gb, 6, E);
	break;
case 0x74:
	if (gb->log) {
		printf("BIT 6, H\n");
	}
	BIT(gb, 6, H);
	break;
case 0x75:
	if (gb->log) {
		printf("BIT 6, L\n");
	}
	BIT(gb, 6, L);
	break;
case 0x76:
	if (gb->log) {
		printf("BIT 6, mem(HL)\n");
	}
	BIT(gb, 6, mem(HL));
	break;
case 0x77:
	if (gb->log) {
		printf("BIT 6, A\n");
	}
	BIT(gb, 6, A);
	break;
case 0x78:
	if (gb->log) {
		printf("BIT 7, B\n");
	}
	BIT(gb, 7, B);
	break;
case 0x79:
	if (gb->log) {
		printf("BIT 7, C\n");
	}
	BIT(gb, 7, C);
	break;
case 0x7A:
	if (gb->log) {
		printf("BIT 7, D\n");
	}
	BIT(gb, 7, D);
	break;
case 0x7B:
	if (gb->log) {
		printf("BIT 7, E\n");
	}
	BIT(gb, 7, E);
	break;
case 0x7C:
	if (gb->log) {
		printf("BIT 7, H\n");
	}
	BIT(gb, 7, H);
	break;
case 0x7D:
	if (gb->log) {
		printf("BIT 7, L\n");
	}
	BIT(gb, 7, L);
	break;
case 0x7E:
	if (gb->log) {
		printf("BIT 7, mem(HL)\n");
	}
	BIT(gb, 7, mem(HL));
	break;
case 0x7F:
	if (gb->log) {
		printf("BIT 7, A\n");
	}
	BIT(gb, 7, A);
	break;
