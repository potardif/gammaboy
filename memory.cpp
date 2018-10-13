u8 mem_read(u16 addr) {
	if (addr < BIOS_LENGTH) {
		return bios[addr];
	} else {
		panic("Unimplemented memory read at 0x%04X.", addr);
	}
}
