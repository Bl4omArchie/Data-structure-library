CC = gcc
ASM = yasm

SRCDIR = src
TESTDIR = tests
INCDIR = includes
BUILDDIR = build

TARGET = file.o

SRCS = $(wildcard $(SRCDIR)/associative_array/*.c $(SRCDIR)/linked_list/*.c $(SRCDIR)/util/*.c $(TESTDIR)/*.c)
ASMS := $(wildcard $(SRCDIR)/*.asm)
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(subst $(SRCDIR)/,src/,$(subst $(TESTDIR)/,tests/,$(SRCS)))) $(patsubst $(SRCDIR)/%.asm, $(BUILDDIR)/%.o, $(ASMS))

CFLAGS = -I$(INCDIR) -pg

all: $(TARGET)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) main.c $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.asm
	$(ASM) -f elf64 -o $@ $<

clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o *.out

.PHONY: all clean