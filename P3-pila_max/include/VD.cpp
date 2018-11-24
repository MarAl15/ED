/**
  * @file VD.cpp
  * @brief Implementación del TDA VD (Vector Dinámico)
  *
  */

#include <iostream>
#include <cassert>
using namespace std;

/* _________________________________________________________________________ */

template <class T>
/* Constructor por parámetros */
VD<T>::VD(int numeroElementos, T *valores){
	assert(numeroElementos >= 0);

	this->numeroElementos = numeroElementos;

	// Si el número de elementos es mayor que cero
	// copiamos los valores pasados como argumentos,
	// reservando espacio para estos.
	if(numeroElementos != 0){
		reservarEspacio(numeroElementos);
		
		for(int i=0; i<numeroElementos; i++)
			datos[i] = valores[i];
	}
	else // Si numeroElementos = 0, datos apunta a NULL
		datos = 0;
}

/* _________________________________________________________________________ */

template <class T>
/* Constructor de copia */
VD<T>::VD(const VD<T> &orig){
	numeroElementos = orig.nelementos;

	// Si el número de elementos es mayor que cero
	// copiamos los valores pasados como argumentos,
	// reservando espacio para estos.
	if(numeroElementos != 0){
		reservarEspacio(numeroElementos);

		for(int i=0; i<numeroElementos; i++)
			datos[i] = orig.datos[i];
	}
	else{ // Si numeroElementos = 0, datos apunta a NULL
		datos = 0;
	}
}

/* _________________________________________________________________________ */

template <class T>
/* Destructor */
VD<T>::~VD(){
	// Se libera el espacio de la elementos del vector.
	liberarEspacio();	
}

/* _________________________________________________________________________ */

template <class T>
/* Método auxiliar para liberar espacio */
void VD<T>::liberarEspacio(){
	// Se comprueba que haya elementos en la lista.
	if(numeroElementos != 0) 
		delete [] datos;
}

/* _________________________________________________________________________ */

template <class T>
/* Método auxiliar para reservar espacio */
void VD<T>::reservarEspacio(int tamanio){
	assert(tamanio >= 0);

	// Se comprueba que haya un tamaño mayor a cero para reservar espacio.
	if(tamanio != 0){
		datos = new T[tamanio];
	}
}

/* _________________________________________________________________________ */

template <class T>
/* Función para añadir nuevo elemento */
void VD<T>::poner(const T& nuevo_dato, int posicion){
	assert(posicion>=0 && posicion<=numeroElementos);

	// Se redimensiona el vector para que reserve para un
	// elemento más.
	resize(numeroElementos+1);
	
	// Se mueven los valores anteriores a un posición mayor
	for(int i=numeroElementos-1; i>posicion; i--)
		datos[i] = datos[i-1];

	// Se introduce el nuevo valor en el vector en la posición indicada.
	datos[posicion] = nuevo_dato;

}

/* _________________________________________________________________________ */

template <class T>
/* Sobrecarga del operador de asignación */
VD<T>& VD<T>::operator= (const VD<T> &orig){
	if(this != &orig){
		numeroElementos = orig.numeroElementos;

		if(numeroElementos != 0) {
			liberarEspacio();

			reservarEspacio(numeroElementos);

			for(int i=0; i<numeroElementos-1; i++)
				datos[i] = orig.datos[i];
		}
	}

	return *this;
} 

/*___________________________________________________________________________ */

template <class T>

void VD<T>::quitar(int posicion){
	assert(posicion>=0 && posicion<=numeroElementos);

	for(int i=posicion+1; i<numeroElementos; i++)
		datos[i-1] = datos[i];

	numeroElementos--;
}

/* _________________________________________________________________________ */

template <class T>

void VD<T>::resize(int nuevo_tamanio){
	assert(nuevo_tamanio>=0);

	if(nuevo_tamanio != numeroElementos){
		if(nuevo_tamanio != 0){
			T*nuevos_datos;
			nuevos_datos = new T[nuevo_tamanio];
			if(numeroElementos>0){
				int minimo;
				if(numeroElementos<nuevo_tamanio)
					minimo = numeroElementos;
				else
					minimo = nuevo_tamanio;

				for(int i=0; i<minimo; i++)
					nuevos_datos[i] = datos[i];

				delete [] datos;

				datos = nuevos_datos;
			}
			else{
				datos = new T[nuevo_tamanio];
				
			}

			numeroElementos = nuevo_tamanio;
		}
		else{
			if(numeroElementos>0)
				delete [] datos;
			datos = 0;
			numeroElementos = 0;
		}
	}
}
/*__________________________________________________________________________________________________*/