CFLAGS += -c -mcpu=cortex-m33

all:
	arm-none-eabi-gcc $(CFLAGS) main.c -o main.o


