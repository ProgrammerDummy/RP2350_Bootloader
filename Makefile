CC = arm-none-eabi-gcc

CFLAGS += -mcpu=cortex-m33 -mthumb -g -O0
LFLAGS += -T ld/ram-exec.ld -nostartfiles -Wl,-Map=main.map

TARGET = main.elf
OBJECTS = main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

main.o: main.c rp2350_regs.h

clean:
	rm -f $(OBJECTS) $(TARGET) main.map

.PHONY: all clean


