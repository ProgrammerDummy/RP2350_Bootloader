/*
 * ram-exec.ld
 *
 * Minimal linker script to load and exec code directly in RAM.
 * It's expected to run GDB and set $sp=&__stack_top and $sp=0x20000000
 */

ENTRY(main)

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

/* In ARM architecture usually the stack grows downward from the highest memaddr of SRAM */
__stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
