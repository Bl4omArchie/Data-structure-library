CC = gcc
ASM = yasm

SRCDIR = src
TESTDIR = tests
BENCHDIR = benchmark
INCDIR = includes
BUILDDIR = build

TARGET = file.o

SRCS = $(wildcard $(SRCDIR)/linked_list/*.c $(SRCDIR)/hardware/*.c $(SRCDIR)/benchmark/*.c $(SRCDIR)/utils/*.c $(BENCHDIR)/*.c $(TESTDIR)/*.c)
ASMS = $(wildcard $(SRCDIR)/utils/*.asm)

OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS)) $(patsubst $(SRCDIR)/utils/%.asm,$(BUILDDIR)/utils/%.o,$(ASMS))

# Compilation flags
CFLAGS = -I$(INCDIR) -pg -O3 -z noexecstack

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/utils/%.o: $(SRCDIR)/utils/%.asm
	mkdir -p $(dir $@)
	$(ASM) -f elf64 -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) main.c

clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o *.out

.PHONY: all clean