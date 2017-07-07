####### ****************** ABREVIATURAS ********************* #######

    SRC = src
    INC = include
    OBJ = obj
    BIN = bin
    LIB = lib

    CXX = g++

    CXXFLAGS = -Wall -g -c -I$(INC)
    LDXFLAGS = -ansi -std=c++11 -pedantic



####### ****************** TOO ********************* #######

all: $(BIN)/testimagen $(BIN)/testarteASCII $(BIN)/arteASCII2 $(BIN)/suma


####### ****************** OBJETOS ********************* #######

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CXXFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h
	$(CXX) $(CXXFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CXXFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CXXFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp $(INC)/imagen.h
	$(CXX) $(CXXFLAGS) $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o $(CXXFLAGS)

$(OBJ)/suma.o: $(SRC)/suma.cpp $(INC)/imagen.h
	$(CXX)  $(CXXFLAGS) $(SRC)/suma.cpp -o $(OBJ)/suma.o $(CXXFLAGS)

$(OBJ)/arteASCII.o: $(SRC)/arteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CXXFLAGS) $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CXXFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o

$(OBJ)/testarteASCII.o: $(SRC)/testarteASCII.cpp $(INC)/imagen.h
	$(CXX) $(CXXFLAGS) $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o



####### ****************** EJECUTABLES ********************* #######

$(BIN)/suma: $(LIB)/libimagen.a $(OBJ)/suma.o
	$(CXX) $(OBJ)/suma.o -o $(BIN)/suma -L$(LIB)/ -limagen $(LDXFLAGS)

$(BIN)/testimagen: $(LIB)/libimagen.a $(OBJ)/testimagen.o
	$(CXX) $(OBJ)/testimagen.o -o $(BIN)/testimagen -L$(LIB)/ -limagen $(LDXFLAGS)

$(BIN)/arteASCII2: $(LIB)/libimagen.a $(OBJ)/lista.o $(OBJ)/arteASCII2.o
	$(CXX) $(OBJ)/arteASCII2.o -o $(BIN)/arteASCII2 -L$(LIB)/ -limagen $(LDXFLAGS)

$(BIN)/testarteASCII: $(LIB)/libimagen.a $(OBJ)/testarteASCII.o
	$(CXX) $(OBJ)/testarteASCII.o -o $(BIN)/testarteASCII -L$(LIB)/ -limagen $(LDXFLAGS)

####### ****************** LIBRERIA IMAGEN ********************* #######

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar -rsv $(LIB)/libimagen.a $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o $(OBJ)/imagen.o



####### ****************** DOCUMENTACIÓN ********************* #######

documentacion:
	doxygen doc/doxys/Doxyfile



####### ****************** LIMPIEZA ********************* #######

clean:
	-rm $(OBJ)/* $(LIB)/*

mrproper: clean
	-rm -R $(BIN)/* doc/html doc/latex doc/rtf *.pgm gioascii*.txt ascii_*.txt
