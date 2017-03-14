CC=bfin-elf-gcc
FLAGS=-WALL -O3 -c -fmessage-length=0 -mcpu=bf533-any -MMD -MP -gnu11
LDFLAGS=-g3  -mcpu=bf533-any -msim 

TARGET = test

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
