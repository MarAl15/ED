/**
  * @file Pila_max.h
  * @brief Fichero cabecera para insertar la implementación deseada.
  *
  * Permite modificar la implementación mediante un número del 1 al 3.
  *
  */

#include <iostream>
using namespace std;

#define CUAL_COMPILO 1

struct elemento{
	int ele;   		//< Elemento menor
	int maximo;		//<Maximo elemento

	/**
	  * @brief Sobrecarga del operador <<. Salida de un elemento.
	  * @param os Stream de salida.
	  * @param orig Elemento a escribir.
	  * @post Se obtiene el elemento menor y el maximo de aux.
	  */
	friend ostream& operator<< (ostream &os,const elemento& aux);
};

#if CUAL_COMPILO==1
  #include "Pila_max_VD.h"
#elif CUAL_COMPILO==2
  #include "Pila_max_List.h"
#else
  #include "Pila_max_Cola.h"
#endif