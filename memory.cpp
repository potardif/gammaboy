const u16 ROM_BANK_0_START = 0x0000;
const u16 ROM_BANK_0_END = 0x3FFF;

u8 mem_read(gb* gb, u16 addr) {
	if (ROM_BANK_0_START <= addr && addr <= ROM_BANK_0_END) {
		if (BIOS_START <= addr && addr <= BIOS_END) {
			return bios[addr - BIOS_START];
		}

		// We return the scrolling Nintendo logo data from the bios as if it was
		// contained in the cartridge. We do this so the bios doesn't get stuck
		// in an infinite loop.
		if (0x0104 <= addr && addr <= 0x0133) {
			const u16 i = addr - 0x0104;
			return bios[0x00A8 + i];
		}

		// We return 0 so the bios doesn't get stuck in an infinite loop.
		if (addr == 0x014D) return 0x00;

		// If there is no cartridge, we just return 0xFF.
		return 0xFF;
	} else if (HRAM_START <= addr && addr <= HRAM_END) {
		return gb->hram[addr - HRAM_START];
	} else {
		switch (addr) {
		case 0xFF42: return gb->scy; break;

		// We return 144 so the bios doesn't get stuck in an infinite loop.
		case 0xFF44: return 144; break; // LY: Lcdc Y-coordinate

		default:
			panic("Unimplemented memory read at 0x%04X.", addr);
			break;
		}
	}
}

void mem_set(gb* gb, u16 addr, u8 value) {
	if (VRAM_START <= addr && addr <= VRAM_END) {
		gb->vram[addr - VRAM_START] = value;
	} else if (HRAM_START <= addr && addr <= HRAM_END) {
		gb->hram[addr - HRAM_START] = value;
	} else {
		switch (addr) {
			case 0xFF11: break; // TODO Audio
			case 0xFF12: break; // TODO Audio
			case 0xFF13: break; // TODO Audio
			case 0xFF14: break; // TODO Audio
			case 0xFF24: break; // TODO Audio
			case 0xFF25: break; // TODO Audio
			case 0xFF26: break; // TODO Audio
			case 0xFF40: gb->lcdc = value; break;
			case 0xFF42: gb->scy = value; break;
			case 0xFF47: gb->bgp = value; break;
			default:
				panic("Unimplemented memory write at 0x%04X.", addr);
				break;
		}
	}
}
