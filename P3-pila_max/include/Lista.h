/**
  * @file Lista.h
  * @brief Fichero cabecera del TDA Lista
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos.
  */

#ifndef __LISTA__H__
#define __LISTA__H__

#include <iostream>
#include <cassert>

/**
 *  @brief T.D.A. Lista
 *
 *
 * Una instancia @e c del tipo de dato abstracto Lista sobre un dominio @e T es
 * una sucesión finita de elementos del mismo donde la salida del elemento puede 
 * puede ser según se prefiera, pudiendo acceder a cualquier dato que se encuentre
 * en la posición indicada. En una lista, las operaciones de inserción tienen
 * lugar en cualquier posición, igual que el borrado y la consulta 
 * Una lista de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<
 *
 * Si n=0 diremos que la lista está vacía.
 *
 *
 * @author Mª del Mar Alguacil
 * @date Noviembre 2014
*/

/**
 * Clase Lista
 */
template <class T>
class Lista {
	private:
		struct Celda {       
			T dato;        ///< Elemento de información.
			Celda * sig; ///< Puntero al siguiente nodo.

		/**
		  * @brief Constructor por defecto
		  */
			Celda() : sig(0){
			}
		/**
		  * @brief Constructor con parámetros
		  * @param elem Elemento de información.
		  * @param siguiente Puntero al siguiente nodo.
		  */
			Celda(const T & elem, Celda * siguiente): dato(elem), sig(siguiente){
			}
		};

	/** Cabecera de la lista */
    	Celda *cabecera;
		
	/** Puntero al último elemento */
		Celda *ultimo;
	
    /** Número de elementos de la lista */
    	int numeroElementos;

	public:
		// ---------------  Constructores ----------------
    /**
	  * @brief Constructor por defecto.
	  */
    	Lista();

    /**
	  * @brief Constructor por parámetros.
	  * @param numElementos Tamaño de la lista.
	  */
    	Lista(int numElementos);

    /**
	  * @brief Constructor de copia.
	  * @param lista La lista de la cual se hará la copia.
	  */
    	Lista(const Lista &lista);
	
	// ------------------ Destructor ------------------
    /**
	  * @brief Destructor.
	  */
    	~Lista();
	
	// --------------- Otras funciones ---------------
    /**
	  * @brief Sobrecarga de operador de asignacion.
 	  * @param lista La lista que se va a asignar.
 	  */
    	Lista<T> & operator=(const Lista<T> &lista);
	
	/**
	  * @brief Añade el dato en la posición indica de la lista.
	  * @param posicion Lugar a insertar el dato.
	  * @param dato Elemento a añadir.
  	  */
		void poner(int posicion, T dato);
	
	/**
	  * @brief Elimina el dato que se encuentra indicada.
	  * @param posicion Posición en la que se encuentra el dato a eliminar.
	  */
		void quitar(int posicion);
    	
	/**
	  * @brief Número de elementos que contiene la lista.
	  * @return numeroElementos
	  */
		inline int size() const{
			assert(numeroElementos >= 0);
			return numeroElementos;
		}
	
	/**
	  * @brief Comprueba si la lista esta vacia, es decir, si tiene algún elemento.
	  * @return Valor booleano: true si el numero de elementos es cero, false en caso contrario.
	  */
		inline bool vacia() const{
			return numeroElementos == 0;
		}
 	/**
	  *	@brief Primer elemento de la lista.
	  * @return Elemento que se encuentra en la primera posición de la lista.
	  */
		inline T & begin(){
			return cabecera->sig->dato;
		}
	
	/**
	  *	@brief Primer elemento de la lista.
	  * @return Elemento que se encuentra en la primera posición de la lista el cual no se puede modificar.
	  */
		inline const T & begin() const{
			return cabecera->sig->dato;
		}

	/**
	  *	@brief Último elemento de la lista.
	  * @return Elemento que se encuentra en la última posición de la lista.
	  */
		inline T & end(){
			return ultimo->dato;
		}
	
	/**
	  *	@brief Último elemento de la lista.
	  * @return Elemento que se encuentra en la última posición de la lista el cual no se puede modificar.
	  */
		inline const T & end() const{
			return ultimo->dato;
		}

	/**
	  * @brief Sobrecarga del operador [].
	  * @param i Posicion del elemento indicado.
	  * @return Elemento en la posición i.
	  */
		T &operator[] (int i);
		
	/**
	  * @brief Sobrecarga del operador [].
	  * @param i Posicion del elemento indicado.
	  * @return Elemento de solo lectura en la posición i.
	  */
		const T &operator[] (int i) const;
	
	private:
	/**
	  * @brief Metodo auxiliar para reservar espacio.
	  * @param numeroElementos Tamaño a reservar.
	  */
    	void reservarEspacio(int numeroElementos);
	
	/**
	  * @brief Metodo auxiliar para liberar espacio.
	  */
    	void liberarEspacio();
	
	/**
	  * @brief Metodo auxiliar para copiar los valores de la lista
	  *		 pasada como argumento en la lista sobre la que se hace
	  * 	la llamada, a partir de la posicion indicada.
	  * @param posicion a partir de la cual se asigna los valores de lista.
	  * @param lista de la cual se copian los valores.
	  */
    	void asignarValores(int posicion, const Lista &lista);
};
	
#include "Lista.cpp"
#endif