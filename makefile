CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lncurses

SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
EXECUTABLE = $(BINDIR)/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*.o $(BINDIR)/main

run: $(EXECUTABLE)
	./$(EXECUTABLE)
