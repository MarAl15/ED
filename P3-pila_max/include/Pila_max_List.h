/** 
  * @file Pila_max_List.h
  * @brief Fichero cabecera del TDA Pila_max_List
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo.
  */

#ifndef __PILA_MAX_LIST_H__
#define __PILA_MAX_LIST_H__

#include <cassert>
#include <iostream>
#include "Lista.h"

/**
 *  @brief T.D.A. Pila_max
 *
 *
 * Una instancia @e c del tipo de dato abstracto Pila_max sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e LIFO
 * (Last In, First Out}). En una pila, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, igual que
 * el borrado y consulta , denominado @e tope de la pila. 
 * Una cola de longitud @e n la denotamos
 * 
 * - <a1,a2,a3,..,an<
 *
 * En esta pila, tendremos acceso únicamente al elemento del @e Tope,
 * es decir, a @e an. El borrado o consulta de un elemento será también sobre @e an,
 * igual que la inserción de un nuevo elemento se hará después de
 * @e an (final de la pila_max).
 *
 * Si n=0 diremos que la pila está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la pila.
 *
 * @author Mª del Mar Alguacil
 * @date Noviembre 2014
*/

class Pila_max{
	
	private:
		/** Pila de elementos */
		Lista <elemento> pila_max;

	public:

	/*
	 * @brief Se comprueba si la lista de elementos esta vacía.
	 * @return True si es cierto que esta vacía y false en caso contrario.
  	 */
		inline bool vacia() const{
			return pila_max.size() == 0;
		}

	/*
     * @brief Añadir a la lista de datos.
 	 * @param dato Elemento a añadir a la lista en la última posición.
  	 */
		void poner(const int dato);

	/*
	 * @brief Constructor por defecto.
	 */
		Pila_max();
	
	/*
	 * @brief Constructor por parámetros.
	 * @param pila lista de elementos para inicializar pils_max.
	 */
		Pila_max(const Lista <elemento> pila);


	/*
	 * @brief Constructor de copia. Inicializa el dato privado pila_max con el 
	 * 	de un elemento de Pila_max ya creado.
	 * @param otra_pila_max Elemento de esta clase con el cual se quiere inicializar
	 *	pila_max.
	 */
		Pila_max(const Pila_max& otra_pila_max);

	/*
   	 * @brief Operador de asignación.
	 */
		Pila_max& operator=(const Pila_max& otra);

	/*
	 * @brief Eliminar el último elemento de la pila.
	 */
		void quitar();

	/*
	 * @brief Último elemento de la pila.
 	 * @return Tope.
	 */
		elemento& tope();

		const elemento& tope() const;

	/*
  	 * @brief Número de elementos que contiene la pila.
	 * @return Número de elementos.
	 */

		inline int numElementos() const{
			return pila_max.size();
		}
};

#endif // __PILA_MAX_LIST_H__