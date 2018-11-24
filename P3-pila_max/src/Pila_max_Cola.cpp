#include <cassert>
#include <iostream>
#include "cola.h"
#include "Pila_max_Cola.h"
using namespace std;

/* Contructor por defecto */
Pila_max::Pila_max(){
}

/* Constructor por parámetros */
Pila_max::Pila_max(const Cola <elemento> pila){
	// Se copia la pila pasada como argumento.
	pila_max = pila;
}

/* Constructor de copia */
Pila_max::Pila_max(const Pila_max& otra_pila_max){
	// Se copia pila_max de otra_pila_max.
	pila_max = otra_pila_max.pila_max;
}

/* Función para añadir nuevos elementos a pila_max*/
void Pila_max::poner(const int dato){
	elemento elem_aux;
	elem_aux.ele = dato;

	// Se calcula el maximo.
	if(pila_max.vacia() || pila_max.frente().maximo < dato)
		elem_aux.maximo = dato;
	else
		elem_aux.maximo = pila_max.frente().maximo;
	
	// Se añade el nuevo elemento.
	pila_max.poner(elem_aux);
}

/* Elimina el último elemento de pila_max */
void Pila_max::quitar(){
	assert(!pila_max.vacia());
	Cola <elemento> cola_aux;
	int tope = pila_max.num_elementos();

	// Se guarda los elementos de pila_max en cola_aux, excepto el último. 
	for(int i=0; i<tope-1; i++){
		cola_aux.poner(pila_max.frente());
		pila_max.quitar();
	}

	// Se elimina el último elemento.
	pila_max.quitar();

	// Se vuelve a introducirlos en pila_max.
	pila_max = cola_aux;	
}

/* Devolver el último elemento de pila_max */
elemento & Pila_max::tope(){
	assert(!pila_max.vacia());

	elemento ultimo;
	int tope = pila_max.num_elementos();
	Cola <elemento> cola_aux;
	
	// Se copia pila_max en una cola auxiliar.
	cola_aux = pila_max;

	// Se elimina todos los elementos menos el último.
	for(int i=0; i<tope-1;i++){
		cola_aux.quitar();
	}

	// Se devuelve el último elemento.
	ultimo = cola_aux.frente(); 
	return ultimo;
}

/* Devolver el último elemento de la pila_max constante para que no se pueda modificar */
const elemento & Pila_max::tope() const{
	assert(!pila_max.vacia());

	int tope = pila_max.num_elementos();
	Cola <elemento> cola_aux;
	
	// Se copia pila_max en una cola auxiliar.
	cola_aux = pila_max;

	// Se elimina todos los elementos menos el último.
	for(int i=0; i<tope-1;i++){
		cola_aux.quitar();
	}

	// Se devuelve el último elemento.
	const elemento ultimo = cola_aux.frente(); 
	return ultimo;
}

/* Sobrecarga del operador de asignación */
Pila_max& Pila_max::operator=(const Pila_max& otra){
	// Se comprueba que no haya autoasignación.
	if(this != &otra){
		pila_max = otra.pila_max;
	}

	// Se devuelve el objeto
	return *this;
}