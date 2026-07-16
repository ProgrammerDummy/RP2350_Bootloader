/*
 * ram-exec.ld
 *
 * Minimal linker script to use gdb to load and execute code entirely in ram (no flash).
 * This requires GDB to jump to the addres of the start symbol
 */

MEMORY {
	/* 
	 * RP2350 address map (page 30 rp2350 datasheet
	 * Also RP2350 has 520 kB of SRAM (page 338 rp2350 datasheet)
	 */
	SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 520K
}

SECTIONS { 
	.text : {
		*(.text*) 
		*(.rodata*)
	} > SRAM

	.data : {
		*(.data*)
	} > SRAM

	.bss : {
		*(.bss*)
		*(COMMON)
	} > SRAM
}	
