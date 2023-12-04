C = gcc

# Dossiers
SRCDIR = src
BUILDDIR = build
TARGET = file.o

# Fichiers sources
SRCS = $(wildcard $(SRCDIR)/*.c)
# Fichiers objets
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(C) -c -o $@ $<

$(TARGET): $(OBJS)
	$(C) main.c -o $(TARGET) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean
