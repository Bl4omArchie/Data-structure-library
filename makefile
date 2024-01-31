# Compilateur
CC = gcc
CXX = g++
TEST_TARGET = test_suite.o

# Dossiers
SRCDIR = src
INCDIR = includes
BUILDDIR = build
TESTDIR = test
TARGET = file.o
BENCH_TARGET = bench.o

SRCS = $(wildcard $(SRCDIR)/*.c)
TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)

OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SRCS))

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

$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS)

$(BENCH_TARGET): $(OBJS)
	$(CC) benchmark.c -o $(BENCH_TARGET) $(OBJS)

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET) $(BENCH_TARGET) $(TEST_TARGET)

.PHONY: all clean
