file main.elf

target extended-remote:3333
mon reset halt
load
set $sp = &__stack_top

# we are executing from sram so we put pc at the start of sram
# load should already do this but im putting it explicitly
set $pc = 0x20000000

b main
c


# some useful diagnostic commands
# print/x $sp
# info reg
