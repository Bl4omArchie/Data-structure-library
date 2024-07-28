CC = gcc

SRCDIR = src
TESTDIR = tests
INCDIR = includes
BUILDDIR = build

TARGET = file.o

SRCS = $(wildcard $(SRCDIR)/associative_array/*.c $(SRCDIR)/linked_list/*.c $(SRCDIR)/util/*.c $(TESTDIR)/*.c)
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(subst $(SRCDIR)/,src/,$(subst $(TESTDIR)/,tests/,$(SRCS))))
CFLAGS = -I$(INCDIR) -pg

all: $(TARGET)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) main.c $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o *.out

.PHONY: all clean