CC = gcc
ASM = yasm

SRCDIR = src
TESTDIR = tests
INCDIR = includes
BUILDDIR = build

TARGET = file.o

SRCS = $(wildcard $(SRCDIR)/linked_list/*.c $(SRCDIR)/hardware/*.c $(SRCDIR)/util/*.c $(TESTDIR)/*.c)
SRC_BENCHMARK = $(wildcard $(SRCDIR)/benchmark/timing/*.c $(SRCDIR)/benchmark/register/*.c $(SRCDIR)/benchmark/session/*.c)
ASMS = $(wildcard $(SRCDIR)/util/*.asm)

OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS)) $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC_BENCHMARK)) $(patsubst $(SRCDIR)/util/%.asm,$(BUILDDIR)/util/%.o,$(ASMS))

# Compilation flags
CFLAGS = -I$(INCDIR) -pg -O3 -z noexecstack

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/util/%.o: $(SRCDIR)/util/%.asm
	mkdir -p $(dir $@)
	$(ASM) -f elf64 -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) main.c

clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o *.out

.PHONY: all clean