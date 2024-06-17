INCLUDE := -I/opt/homebrew/include
LIB := -L/opt/homebrew/lib
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC_DIR := src
BIN_DIR := bin

CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
EXE_FILE := $(BIN_DIR)/traga_bolas

$(EXE_FILE): $(CPP_FILES)
	g++ $^ -o $@ $(SFML) $(INCLUDE) $(LIB)

all: $(EXE_FILE)

run: $(EXE_FILE)
	./$(EXE_FILE)

clean:
	rm -f $(EXE_FILE)

.PHONY: all clean run
