/**
  * @file Pila_max.cpp
  * @brief Fichero de definiciones para insertar la implementación deseada
  *
  * Incluye la definición correspondiente dependiendo de la selección en Pila_max.h
  *
  */

#include <iostream>
#include "Pila_max.h" // Aquí se define el valor de CUAL_COMPILO
using namespace std;

// Sobrecarga del operador de salida
ostream& operator<< (ostream &os, const elemento &orig){
	os << "\nElemento : " << orig.ele;
	os << "\nMaximo elemento : " << orig.maximo << endl;
	return os;
}

#if CUAL_COMPILO==1
  #include "Pila_max_VD.cpp"
#elif CUAL_COMPILO==2
  #include "Pila_max_List.cpp"
#else
  #include "Pila_max_Cola.cpp"
#endif