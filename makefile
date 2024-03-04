# Compilateurs
CC = gcc
CXX = g++
ASM = yasm

# Dossiers
SRCDIR = src
INCDIR = includes
BUILDDIR = build

TARGET = file.o
BENCH_TARGET = bench.o
TEST_TARGET = test_suite.o

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)
ASMS := $(wildcard $(SRCDIR)/*.asm)

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS)) $(patsubst $(SRCDIR)/%.asm, $(BUILDDIR)/%.o, $(ASMS))

# Options de compilation
CFLAGS = -I$(INCDIR)
CXXFLAGS = -I$(INCDIR) -pthread -lgtest_main -lgtest

# Règles de construction
all: $(BUILDDIR) $(TARGET)
test: $(BUILDDIR) $(TEST_TARGET)
bench: $(BUILDDIR) $(BENCH_TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.asm
	$(ASM) -f elf64 -o $@ $<

$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS)

$(BENCH_TARGET): $(OBJS)
	$(CC) bench.c -o $(BENCH_TARGET) $(OBJS)

$(TEST_TARGET): $(OBJS)
	(git clone https://github.com/google/googletest.git ; cd googletest ; mkdir build ; cd build ; cmake .. ; make)
	$(CXX) test.cpp -o $(TEST_TARGET) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(BENCH_TARGET) $(TEST_TARGET) .vscode/

.PHONY: all clean