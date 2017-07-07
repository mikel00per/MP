
	BIN = bin
	SRC = src
	INC = include
	OBJ = obj
	LIB = lib

	CXX = g++
	ANSI = -ansi
	CXXFLAGS = -Wall -g -I$(INC) -c
	LDXFLAGS = -std=c++11

# ************ Creación de todo ************

all: main

# ************ Creación de ejecutables ************

main: lista.o main.o
	$(CXX) $(OBJ)/lista.o $(OBJ)/main.o -o $(BIN)/main $(ANSI) $(LDXFLAGS)

# ************ Compilación de módulos ************

lista.o: $(INC)/lista.h $(SRC)/lista.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o

main.o: $(INC)/lista.h $(SRC)/main.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

# ************ Limpieza ************

clean:
	echo "Limpiado..."
	-rm $(OBJ)/* $(LIB)/*

mrproper: clean
	-rm -R $(BIN)/* doc/html doc/latex doc/rtf *.pgm *.txt
 

