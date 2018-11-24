SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario
all: $(BIN)/juego
all: $(BIN)/frecuencialetras

# ************ Compilación de módulo testdiccionario ************
$(BIN)/testdiccionario:$(OBJ)/testdiccionario.o $(LIB)/libdiccionario.a
	@echo Creando el ejecutable bin/testdiccionario...
	@$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o -I$(INC) -L$(LIB) -ldiccionario

$(LIB)/libdiccionario.a: $(OBJ)/Diccionario.o
	@echo Creando la libreria Diccionario...
	@ar rvs $(LIB)/libdiccionario.a $(OBJ)/Diccionario.o 

$(OBJ)/Diccionario.o:$(SRC)/Diccionario.cpp
	@echo Creando el modulo objeto obj/Diccionario.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/testdiccionario.o:$(SRC)/testdiccionario.cpp 
	@echo Creando el modulo objeto obj/testdiccionario.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INC)


# ************ Compilación de módulo juego y frecuencialetras ************
$(BIN)/juego:$(OBJ)/juego.o $(LIB)/libjuego.a
	@echo Creando el ejecutable bin/juego...
	@$(CXX) -o $(BIN)/juego $(OBJ)/juego.o -I$(INC) -L$(LIB) -ljuego

$(BIN)/frecuencialetras:$(OBJ)/frecuencialetras.o $(LIB)/libjuego.a
	@echo Creando el ejecutable bin/frecuencialetras...
	@$(CXX) -o $(BIN)/frecuencialetras $(OBJ)/frecuencialetras.o -I$(INC) -L$(LIB) -ljuego

$(LIB)/libjuego.a: $(OBJ)/juego.o $(OBJ)/frecuencialetras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letras.o
	@echo Creando la libreria juego...
	@ar rvs $(LIB)/libjuego.a $(OBJ)/juego.o $(OBJ)/frecuencialetras.o $(OBJ)/Diccionario.o $(OBJ)/Conjunto_Letras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/Letras.o

$(OBJ)/Letras.o:$(SRC)/Letras.cpp
	@echo Creando el modulo objeto obj/Letras.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Letras.o $(SRC)/Letras.cpp -I$(INC)

$(OBJ)/Bolsa_Letras.o:$(SRC)/Bolsa_Letras.cpp
	@echo Creando el modulo objeto obj/Bolsa_Letras.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Bolsa_Letras.o $(SRC)/Bolsa_Letras.cpp -I$(INC)

$(OBJ)/Conjunto_Letras.o:$(SRC)/Conjunto_Letras.cpp
	@echo Creando el modulo objeto obj/Conjunto_Letras.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Conjunto_Letras.o $(SRC)/Conjunto_Letras.cpp -I$(INC)

$(OBJ)/juego.o:$(SRC)/juego.cpp 
	@echo Creando el modulo objeto obj/juego.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/juego.o $(SRC)/juego.cpp -I$(INC) 

$(OBJ)/frecuencialetras.o:$(SRC)/frecuencialetras.cpp 
	@echo Creando el modulo objeto obj/frecuencialetras.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/frecuencialetras.o $(SRC)/frecuencialetras.cpp -I$(INC) 


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile



# ************ Limpieza ************
clean :
	@echo Limpiando...
	@-rm $(OBJ)/*.o $(BIN)/* $(LIB)/*.a

mrproper : clean
	@-rm -dfr doc/html/
