/**
  * @file Cola_max.cpp
  * @brief Implementación del TDA Cola_max
  *
  */

#include <iostream>
#include <cassert>
#include "Cola_max.h"
using namespace std;

// Sobrecarga del operador de salida
ostream& operator<< (ostream &os, const elemento &orig){
	os << "\nElemento : " << orig.ele << endl;
	os << "\nMaximo elemento : " << orig.maximo << endl;
	return os;
}

#include "Pila_max_VD.cpp"

Cola_max::Cola_max(){
}

/* Constructor por parámetros */
Cola_max::Cola_max(const Pila_max cola){
	// Se copia la cola pasada como argumento.
	cola_max = cola;
}

/* Constructor de copia */
Cola_max::Cola_max(const Cola_max& otra_cola_max){
	// Se copia cola_max de otra_cola_max.
	cola_max = otra_cola_max.cola_max;
}

void Cola_max::poner(const int dato){
	Pila_max cola_aux;

	// Se añade el nuevo dato
	cola_max.poner(dato);
}

void Cola_max::quitar(){
	assert(!cola_max.vacia());

	Pila_max cola_aux;
	int tope = cola_max.numElementos();

	// Se guarda los elementos de pila_max en cola_aux, excepto el último. 
	for(int i=0; i<tope-1; i++){
		cola_aux.poner(cola_max.tope().ele);
		cola_aux.tope().maximo = cola_max.tope().maximo;
		cola_max.quitar();
	}

	// Se elimina el último elemento.
	cola_max.quitar();

	// Se vuelve a introducirlos en pila_max.
	while(!cola_aux.vacia()){
		cola_max.poner(cola_aux.tope().ele);
		cola_max.tope().maximo = cola_aux.tope().maximo;
		cola_aux.quitar();
	}
}

elemento& Cola_max::frente(){
	assert(!cola_max.vacia());

	Pila_max cola_aux;
	cola_aux = cola_max;;
	int tope = cola_max.numElementos();
	elemento primero;

	// Se guarda los elementos de pila_max en cola_aux, excepto el último. 
	for(int i=0; i<tope-1; i++)
		cola_aux.quitar();

	primero = cola_aux.tope();

	return primero;
}

const elemento& Cola_max::frente() const{
	assert(!cola_max.vacia());

	Pila_max cola_aux = cola_max;
	int tope = cola_max.numElementos();

	// Se guarda los elementos de pila_max en cola_aux, excepto el último. 
	for(int i=0; i<tope-1; i++)
		cola_aux.quitar();
	
	const elemento primero = cola_aux.tope();

	return primero;
}