CC = gcc

SRCDIR = src
TESTDIR = tests
BENCHDIR = benchmark
INCDIR = includes
BUILDDIR = build

TARGET = file.o

SRCS = $(wildcard $(SRCDIR)/linked_list/*.c $(SRCDIR)/hardware/*.c $(SRCDIR)/benchmark/*.c $(SRCDIR)/utils/*.c $(BENCHDIR)/*.c $(TESTDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

# Compilation flags
CFLAGS = -I$(INCDIR) -pg -O3 -z noexecstack

all: $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) main.c

clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o *.out

.PHONY: all clean