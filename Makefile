CC = arm-none-eabi-gcc

CFLAGS += -mcpu=cortex-m33 -mthumb -g -O0

LFLAGS += -T ld/ram-exec.ld -nostartfiles -Wl,-Map=main.map

TARGET = main.elf
OBJECTS = main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^


