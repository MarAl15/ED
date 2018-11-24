#include <cassert>
#include <iostream>
#include "Lista.h"
#include "Pila_max_List.h"
using namespace std;

/* Contructor por defecto */
Pila_max::Pila_max(){
}

/* Constructor por parámetros */
Pila_max::Pila_max(const Lista <elemento> pila){
	// Se copia la pila pasada como argumento.
	pila_max = pila;
}

/* Constructor de copia */
Pila_max::Pila_max(const Pila_max& otra_pila_max){
	// Se copia pila_max de otra_pila_max.
	pila_max = otra_pila_max.pila_max;
}

/* Añadir nuevos elementos a pila_max*/
void Pila_max::poner(const int dato){
	elemento elem_aux;
	elem_aux.ele = dato;
	int num_elementos = pila_max.size();

	// Se calcula el maximo.
	if(pila_max.vacia() || pila_max.end().maximo < dato)
		elem_aux.maximo = dato;
	else
		elem_aux.maximo = pila_max.end().maximo;
	

	// Se añade el nuevo elemento en la última posición.
	pila_max.poner(num_elementos,elem_aux);
}

/* Eliminar el último elemento de pila_max */
void Pila_max::quitar(){
	assert(!pila_max.vacia());

	// Se elimina la última Celda.
	pila_max.quitar(pila_max.size()-1);	
}

/* Devolver el último elemento de pila_max */
elemento & Pila_max::tope(){
	assert(!pila_max.vacia());

	// Se devuelve el elemento que se encuentra en la última Celda.
  	return pila_max.end();
}

/* Devolver el último elemento de la pila_max constante para que no se pueda modificar */
const elemento & Pila_max::tope() const{
	assert(!pila_max.vacia());

	// Se devuelve el elemento que se encuentra en la última Celda de forma constante.
  	return pila_max.end();
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