# Compilateur
CC = gcc

# Dossiers
SRCDIR = src
BENCHDIR = bench
INCDIR = includes
BUILDDIR = build

TARGET = file.o
BENCH_TARGET = bench.o

SRCS = $(wildcard $(SRCDIR)/*.c)
BENCH_SRCS = $(wildcard $(BENCHDIR)/*.c)


OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
BENCH_OBJS = $(patsubst $(BENCHDIR)/%.c, $(BUILDDIR)/%.o, $(BENCH_SRCS))

# Options de compilation
CFLAGS = -I$(INCDIR)

# Règles de construction
all: $(BUILDDIR) $(TARGET)
bench: $(BUILDDIR) $(BENCH_TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS)

$(BENCH_TARGET): $(OBJS)
	$(CC) benchmark.c -o $(BENCH_TARGET) $(OBJS)


clean:
	rm -rf $(BUILDDIR) $(TARGET) $(BENCH_TARGET) $(TEST_TARGET)

.PHONY: all clean