SRC=src
INC=include
OBJ=obj
BIN=bin
CXX=g++
LIB=lib
CPPFLAGS=-Wall -g -I$(INC) -c

all:$(BIN)/pruebatraductor
all:$(BIN)/traductor_inverso
all:$(BIN)/concatenar
all:$(BIN)/interseccion

# ************ Generación de documentación ******************
documentacion:
	@echo Creando documentacion...
	@doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebatraductor:$(OBJ)/pruebatraductor.o $(LIB)/libtraductor.a
	@echo Creando el ejecutable bin/pruebatraductor...
	@$(CXX) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o -I$(INC) -L$(LIB) -ltraductor

$(BIN)/traductor_inverso:$(OBJ)/traductor_inverso.o $(LIB)/libtraductor.a
	@echo Creando el ejecutable bin/traductor_inverso..
	@$(CXX) -o $(BIN)/traductor_inverso $(OBJ)/traductor_inverso.o -I$(INC) -L$(LIB) -ltraductor

$(BIN)/concatenar:$(OBJ)/concatenar.o $(LIB)/libtraductor.a
	@echo Creando el ejecutable bin/concatenar..
	@$(CXX) -o $(BIN)/concatenar $(OBJ)/concatenar.o -I$(INC) -L$(LIB) -ltraductor

$(BIN)/interseccion:$(OBJ)/interseccion.o $(LIB)/libtraductor.a
	@echo Creando el ejecutable bin/interseccion..
	@$(CXX) -o $(BIN)/interseccion $(OBJ)/interseccion.o -I$(INC) -L$(LIB) -ltraductor


$(LIB)/libtraductor.a:$(OBJ)/palabra.o $(OBJ)/traductor.o
	@echo Creando la libreria...
	@ar rvs $(LIB)/libtraductor.a $(OBJ)/palabra.o $(OBJ)/traductor.o

$(OBJ)/palabra.o:$(SRC)/palabra.cpp
	@echo Creando el modulo objeto obj/palabra.o ...
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INC)

$(OBJ)/traductor.o:$(SRC)/traductor.cpp
	@echo Creando el modulo objeto obj/traductor.o ...
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/traductor.o $(SRC)/traductor.cpp -I$(INC)


$(OBJ)/pruebatraductor.o:$(SRC)/pruebatraductor.cpp
	@echo Creando el modulo objeto obj/pruebatraductor.o
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebatraductor.o $(SRC)/pruebatraductor.cpp -I$(INC) 

$(OBJ)/traductor_inverso.o:$(SRC)/traductor_inverso.cpp
	@echo Creando el modulo objeto obj/traductor_inverso.o
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/traductor_inverso.o $(SRC)/traductor_inverso.cpp -I$(INC) 

$(OBJ)/concatenar.o:$(SRC)/concatenar.cpp
	@echo Creando el modulo objeto obj/concatenar.o
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/concatenar.o $(SRC)/concatenar.cpp -I$(INC) 

$(OBJ)/interseccion.o:$(SRC)/interseccion.cpp
	@echo Creando el modulo objeto obj/interseccion.o
	@$(CXX) $(CPPFLAGS)  -o $(OBJ)/interseccion.o $(SRC)/interseccion.cpp -I$(INC) 


# ************ Limpieza ************
clean:
	@echo Limpiando...
	@-rm $(OBJ)/*.o $(LIB)/*.a $(BIN)/*

mrproper:clean
	@-rm -dfr doc/html/
