# Compilateur
CC = gcc

# Dossiers
SRCDIR = src
INCDIR = includes
BUILDDIR = build

TARGET = file.o
BENCH_TARGET = bench.o

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

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
	$(CC) bench.c -o $(BENCH_TARGET) $(OBJS)


$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	(git clone https://github.com/google/googletest.git ; cd googletest ; mkdir build ; cd build ; cmake .. ; make)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(BENCH_TARGET) $(TEST_TARGET) .vscode/

.PHONY: all clean