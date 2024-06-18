SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj
INCLUDE_DIR := include

# Actualiza esta ruta si SFML está en un lugar diferente
SFML_INCLUDE_PATH := /usr/local/include

# Define CPPFLAGS here
CPPFLAGS := -I$(INCLUDE_DIR) -I/opt/homebrew/include -std=c++11

#INCLUDE := -I$(SRC_DIR) -I$(INCLUDE_DIR) -I/usr/local/include/SFML
#INCLUDE := -I/usr/local/include -I/usr/local/include/SFML -I/usr/local/include/box2d
#LIB := -L/usr/local/lib
#SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d $(INCLUDE) $(LIB)
#INCLUDE := -I/opt/homebrew/include
LIB := -L/opt/homebrew/lib
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d $(INCLUDE) $(LIB)
INCLUDE := -I$(SRC_DIR) -I$(INCLUDE_DIR) -I/opt/homebrew/include

# Obtener todos los archivos.cpp en el directorio de origen
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Generar los nombres de los archivos.o en el directorio de destino
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Regla para compilar cada archivo.cpp y generar el archivo.o correspondiente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@g++ -c $< -o $@ $(INCLUDE) $(CPPFLAGS)

# Regla para enlazar todos los archivos.o y generar el ejecutable
$(BIN_DIR)/traga_bolas: $(OBJ_FILES)
	@g++ $^ -o $@ $(LIB) $(SFML)

# Regla por defecto para compilar todos los archivos.cpp
all: $(BIN_DIR)/traga_bolas

# Regla para ejecutar el archivo.exe
run: $(BIN_DIR)/traga_bolas
	./$<

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/traga_bolas

.PHONY: all run clean
