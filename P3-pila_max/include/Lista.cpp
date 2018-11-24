
#include <iostream>
#include <cassert>
using namespace std;

/* _________________________________________________________________________ */

//template <class T>
/* Constructor por defecto de la clase Celda */
/*Celda::Celda(T valor) {
    dato = valor;
    sig = 0;
}*/

/* _________________________________________________________________________ */

template <class T>
/* Constructor por defecto de la clase Lista */
Lista<T>::Lista() {
    numeroElementos = 0;
	cabecera = new Celda;

	// Como no hay elementos el último apunta a NULL
    cabecera->sig = ultimo = 0;
}

/* _________________________________________________________________________ */

template <class T>
/* Constructor por parámetros especificando el número de elementos
	que se le pasa como parámetro*/
Lista<T>::Lista(int numeroElementos) {
    this->numeroElementos = numeroElementos;

    // Se reserva espacio
    reservarEspacio(numeroElementos);
}

/* _________________________________________________________________________ */

template <class T>
/* Metodo auxiliar para reservar espacio */
void Lista<T>::reservarEspacio(int numElementos) {
    Celda *pCelda;
	//T datoCel;

	cabecera = new Celda;
    ultimo = new Celda;

	cabecera->sig = ultimo;

    // Se van creando nuevos elementos a la lista y se
    // van enlazando a medida que se crean
    for (int i = 1; i <= numElementos; i++) {
        pCelda = new Celda;

        // Se hace que el elemento previo apunte al
        // nuevo elemento creado
        ultimo->sig = pCelda;

        // Se actualiza el previo, indicando que el ultimo
        // es el recien creado
        ultimo = pCelda;
    }
}

/* _________________________________________________________________________ */

template <class T>
/* Constructor de copia */
Lista<T>::Lista(const Lista &lista) {
    // Se asigna el numero de elementos
    numeroElementos = lista.numeroElementos;

    // Se reserva espacio para todos los elementos de lista
    reservarEspacio(numeroElementos);

    // Se asigna los nuevos elementos pasados como argumentos
    asignarValores(0, lista);
}

/* _________________________________________________________________________ */

template <class T>
/* Metodo auxiliar para copiar los valores de la lista */
void Lista<T>::asignarValores(int posicion, const Lista<T> &lista) {
    // Se comprueba que no nos salimos de rango.
    assert((posicion < numeroElementos - 1) && 
           (numeroElementos - posicion >= lista.numeroElementos));

    // Se avanza hasta llegar al elemento que
    // ocupa la posicion indicada.
    Celda *pCelda = cabecera;
    for (int i = 0; i <= posicion; i++) {
        pCelda = pCelda->sig;
    }

    // Se asignan los valores.
    Celda *pCeldaArgumento = lista.cabecera;
    while (pCeldaArgumento != 0) {
        pCelda->dato = pCeldaArgumento->dato;

        // Se avanzan ambos punteros
        pCelda = pCelda->sig;
        pCeldaArgumento = pCeldaArgumento->sig;
    }
}

/* _________________________________________________________________________ */

template <class T>
/* Destructor */
Lista<T>::~Lista() {
    // Se libera el espacio de las celdas
    liberarEspacio();
}

/* _________________________________________________________________________ */

template <class T>
/* Función para liberar el espacio de memoria */
void Lista<T>::liberarEspacio() {
    Celda *pCelda = cabecera, *pSiguiente;

    // Se borran las celdas una a una. Para no perder la
    // referencia al siguiente elemento del borrado, se
    // mantiene apuntado por siguiente
    for (int i = 0; i <= numeroElementos; i++) {
        pSiguiente = pCelda->sig;
        
        // Se borra la celada apunta por pCelda
        delete pCelda;
        
        // Se hace que pCelda acceda al siguiente elemento
        pCelda = pSiguiente;
    }
}

/* _________________________________________________________________________ */

template <class T>
/* Función para eliminar el elemento en la posicón indicada*/
void Lista<T>::quitar(int posicion){
	Celda *aux = cabecera;
	Celda *otra;

	// Se avanza hasta llegar al elemento que
    // ocupa la posicion indicada.
	for(int i=0; i<posicion; i++)
		aux = aux->sig;

	// Se copia la referencia al elemento que se 
	// encuentra en la posición indicada.
	otra = aux->sig;
	// Se asigna la referencia al elemento siguiente 
	// al que se encuentra en la posición indicada. 
	aux->sig = otra->sig;

	//Se borra la Celda que se encuentra en posicion.
	delete otra;

	// Si la posición indicada es igual al número de elementos,
	// ultimo apunta a la celda anterior.
	if(posicion == (numeroElementos-1))
		ultimo = aux;

	// Se disminuye el número de elementos.
	numeroElementos--;
}

/* _________________________________________________________________________ */

template <class T>
/* Sobrecarga del operador de asignacion */
Lista<T> & Lista<T>::operator=(const Lista &lista) {
    // Evitar tratar sentencias p=p
    if (this != &lista) {
        // Se libera el espacio
        liberarEspacio();

        // Se asigna el número de elementos
        numeroElementos = lista.numeroElementos;

        // Se reserva nuevo espacio
        reservarEspacio(numeroElementos);

        // Se copian los valores
        asignarValores(0, lista);
    }

    // Se devuelve la referencia
    return *this;
}

/* _________________________________________________________________________ */

template <class T>
/* Función que añade un nuevo elemento en la posición indicada*/
void Lista<T>::poner(int posicion, T nuevo_dato){
	Celda * pCelda;
	pCelda = new Celda(nuevo_dato,0);
	Celda *aux = cabecera;
	Celda *otra;

	// Se avanza hasta a la posición indicada.
	for(int i=0; i<posicion; i++)
		aux = aux->sig;

	//Se añade la nueva Celda
	otra = aux->sig;
	aux->sig = pCelda;
	pCelda->sig = otra;

	// Si la posición es igual al número de elementos 
	// se hace que ultimo apunte a la nueva Celda creada (pCelda).
	if(posicion == numeroElementos)
		ultimo = pCelda;

	// Se aumenta el número de elementos
	numeroElementos++;
}

/* _________________________________________________________________________ */

template <class T>
/* Sobrecarga del operador [] */
T & Lista<T>::operator[] (int i){
	assert(0 <= i && i < numeroElementos);

	// Se busca el elemento de la posición indicada.
	if(i == 0)
		return begin();
	else if(i == (numeroElementos-1))
		return end();
	else{
		Celda *aux = cabecera;

		// Se avanza hasta a la posición indicada.
		for(int j=0; j<=i; j++)
			aux = aux->sig;

		return aux->dato;
	}
}

/* _________________________________________________________________________ */

template <class T>
/* Sobrecarga del operador [] y se devuelve de forma constante para que no sea modificado */
const T & Lista<T>::operator[] (int i) const{
	assert(0 <= i && i < numeroElementos);

	// Se busca el elemento de la posición indicada.
	if(i == 0)
		return begin();
	else if(i == (numeroElementos-1))
		return end();
	else{
		Celda *aux = cabecera;

		// Se avanza hasta a la posición indicada.
		for(int j=0; j<=i; j++)
			aux = aux->sig;

		return aux->dato;
	}
}