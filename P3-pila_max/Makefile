SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c

all:$(BIN)/usopilas_max
all: $(BIN)/usocola_max

# ************ Compilación de módulos Pila max************
$(BIN)/usopilas_max:$(OBJ)/usopilas_max.o $(LIB)/libpila.a
	@echo Creando el ejecutable bin/usopilas_max...
	@$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o -I$(INC) -L$(LIB) -lpila

$(LIB)/libpila.a: $(OBJ)/Pila_max.o
	@echo Creando la libreria...
	@ar rvs $(LIB)/libpila.a $(OBJ)/Pila_max.o 

$(OBJ)/Pila_max.o:$(SRC)/Pila_max.cpp
	@echo Creando el modulo objeto obj/Pila_max.o ...
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Pila_max.o $(SRC)/Pila_max.cpp -I$(INC)

$(OBJ)/usopilas_max.o:$(SRC)/usopilas_max.cpp
	@echo Creando el modulo objeto obj/usopilas_max.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/usopilas_max.o $(SRC)/usopilas_max.cpp -I$(INC) 


# ************ Compilación de módulos Cola max ************
$(BIN)/usocola_max:$(OBJ)/usocola_max.o $(LIB)/libcola.a
	@echo Creando el ejecutable bin/usocola_max...
	@$(CXX) -o $(BIN)/usocola_max $(OBJ)/usocola_max.o -I$(INC) -L$(LIB) -lcola

$(LIB)/libcola.a: $(OBJ)/Cola_max.o
	@echo Creando la libreria...
	@ar rvs $(LIB)/libcola.a $(OBJ)/Cola_max.o 

$(OBJ)/Cola_max.o:$(SRC)/Cola_max.cpp
	@echo Creando el modulo objeto obj/Cola_max.o ...
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/Cola_max.o $(SRC)/Cola_max.cpp -I$(INC)

$(OBJ)/usocola_max.o:$(SRC)/usocola_max.cpp
	@echo Creando el modulo objeto obj/usocola_max.o
	@$(CXX) $(CPPFLAGS) -o $(OBJ)/usocola_max.o $(SRC)/usocola_max.cpp -I$(INC) 


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	@echo Limpiando...
	@-rm $(OBJ)/*.o $(LIB)/*.a $(BIN)/*

mrproper : clean
	@-rm -dfr doc/html/