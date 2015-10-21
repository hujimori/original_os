PREFIX  = /usr/
ARCH    = h8300-elf
BINDIR  = $(PREFIX)/bin
#ADDNAME = $(ARCH)-

AR      = $(BINDIR)/ar
AS      = $(BINDIR)/as
CC      = $(BINDIR)/gcc
LD      = $(BINDIR)/ld
NM      = $(BINDIR)/nm
OBJCOPY = $(BINDIR)/objcopy
OBJDUMP = $(BINDIR)/objdump
RANLIB  = $(BINDIR)/ranlib
STRIP   = $(BINDIR)/strip

H8WRITE = /usr/local/bin/h8write

H8WRITE_SERDEV = /dev/cuad0

OBJS = vector.o startup.o main.o
OBJS += lib.o serial.o

TARGET = kzload

CFLAGS = -Wall -mh -nostdinc -nostdlib -fno-builtin
CFLAGS += -I.
CFLGAS += -Os
CFLAGS += -DKZLOAD

LFLAGS = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
	cp  $(TARGET) $(TARGET).elf
	$(STRIP) $(TARGET)
	.c.o:     $<
	$(CC) -c $(CFLAGS) $<
	.s.o:     $<
	$(CC) -c $(CFLAGS) $<
	$(TARGET).mot: $(TARGET)
	$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot
	image:         $(TARGET).mot
	write:         $(TARGET).mot
	$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot
