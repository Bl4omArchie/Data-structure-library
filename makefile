CC = gcc

SRCDIR = src
INCDIR = includes
BUILDDIR = build

TARGET = file.o


SRCS = $(wildcard $(SRCDIR)/linked_list/*.c $(SRCDIR)/tests/*.c)
OBJS = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCS:$(SRCDIR)/%=%))
CFLAGS = -I$(INCDIR)


all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS)


clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o

.PHONY: all clean