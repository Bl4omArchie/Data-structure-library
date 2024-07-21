# Compilateurs
CC = gcc

# Dossiers
SRCDIR = src
INCDIR = includes
BUILDDIR = build

TARGET = file.o
TEST_TARGET = test.o

# Sources
SRCS = $(wildcard $(SRCDIR)/linked_list/*.c $(SRCDIR)/tests/*.c)

# Objets
OBJS = $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCS:$(SRCDIR)/%=%))

# Options de compilation
CFLAGS = -I$(INCDIR)


all: $(BUILDDIR) $(TARGET)
test: $(BUILDDIR) $(TEST_TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS)

$(TEST_TARGET): $(OBJS)
	$(CC) main.c -o $(TEST_TARGET) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET) .vscode/ *.o

.PHONY: all clean