/**
  * @file VD.h
  * @brief Fichero cabecera del TDA VD
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos.
  */

#ifndef __VD__H__
#define __VD__H__

#include <cassert>

/**
 *  @brief T.D.A. VD (Vector Dinámico)
 *
 *
 * Una instancia @e c del tipo de dato abstracto Vector Dinámico sobre un dominio @e T es
 * una sucesión finita de elementos del mismo donde la salida del elemento puede 
 * puede ser según se prefiera, pudiendo acceder a cualquier dato que se encuentre
 * en la posición indicada. En un vector dinámico, las operaciones de inserción tienen
 * lugar en cualquier posición, igual que el borrado y la consulta. 
 * Un vector dinámico de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<
 *
 * Si n=0 diremos que la vector dinámico está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos del vector dinámico.
 *
 * @author Mª del Mar Alguacil
 * @date Noviembre 2014
*/

template <class T>
class VD{
	private:
	/** Elementos de la información */
		T *datos;

	/** Número de elementos del vector dinámico*/
		int numeroElementos;
	public:

	/**
      * @brief Añade un elemento en la posición indicada de la vector dinámico.
	  * @param nuevo_dato Elemento que se va a añadir.
	  * @param posicion 
	  */
		void poner(const T& nuevo_dato, int posicion);

	 // ---------------  Constructores ----------------
	/**
	  * @brief Constructor por defecto.
	  */
		VD<T>(): datos(0), numeroElementos(0){
		}
			
	/**
	 * @brief Constructor por parámetro.
	 * @param numeroElementos 
	 * @param valores 
	 */

		VD<T>(int numeroElementos, T *valores);

	/**
	 * @brief Constructor de copia. 
	 * @param orig El vector dinámico del cual se hará la copia
	 */
		VD<T>(const VD<T> &orig);

	// ------------------ Destructor ------------------
	/*
	 * @brief Destructor.
	 */
		~VD<T>();

	 // --------------- Otras funciones ---------------
	/**
	  * @brief Sobrecarga del operador de asignación.
	  * @param orig El vector dinámico el cual se va a asignar.
	  */ 
		VD<T> &operator= (const VD<T> &orig);
		
	/**
	  * @brief Tamaño del vector.
	  * @return Número de elementos.
	  */
		
		inline int size() const{
			assert(numeroElementos >= 0);
			return numeroElementos;
		}

	/**
      * @brief Quita el elemento de la posición indicada.
	  * @param posicion
	  */
		void quitar(int posicion);
		
	/**
      * @brief Comprueba si el vector está vacío.
      */
		bool vacia() const{
			return numeroElementos == 0;
		}
		
	/**
	  * @brief Sobrecarga del operador [].
	  * @param i Posicion del elemento indicado.
	  * @return Elemento en la posición i.
	  */
		inline T &operator[] (int i){
			assert(0 <= i && i < numeroElementos);
			return datos[i];
		}
		
	/**
	  * @brief Sobrecarga del operador [].
	  * @param i Posicion del elemento indicado.
	  * @return Elemento de solo lectura en la posición i.
	  */
		inline const T &operator[] (int i) const{
			assert(0 <= i && i < numeroElementos);
			return datos[i];
		}
		
	private:
	/**
	  * @brief Método auxiliar para cambiar el tamaño del vector. 
	  * @param nuevo_tamaño Número de elementos que se quiere que
	  *		tenga el vector dinámico.
	  */
		void resize(int nuevo_tamanio);

	/**
	  * @brief Metodo auxiliar para reservar espacio.
	  * @param tamanio Tamaño a reservar.
	  */
		void reservarEspacio(int tamanio);

	/**
	  * @brief Metodo auxiliar para liberar espacio.
	  */
		void liberarEspacio();
};

#include "VD.cpp"

#endif // __VD__H__ 