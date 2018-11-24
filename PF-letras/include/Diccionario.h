#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <vector>
#include "ArbolGeneral.h"

using namespace std;
/**
   @brief T.D.A. Diccionario
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Diccionario sobre un dominio 
   \e info se puede construir como
   
   - Un objeto vacío (diccionario vacío) si no contiene ningún elemento. 
   Lo denotamos {}.
   - Diccionario formado a partir de un el tipo de dato abstracto ArbolGeneral de
   	info, es decir, cada nodo contiene una letra y si es el final de una palabra.
     
   
   Para poder usar el tipo de dato Diccionario se debe incluir el fichero
   
   <tt>\#include Diccionario.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   letras que contiene el Diccionario.
   
   @author Alguacil Camarero, Mª del Mar
   @author Verona Almeida, Marta
   @date Enero 2015
*/

struct info{
	char c; ///<< caracter que se almacena en un nodo
	bool final; ///< nos indica si es final o no de la palabra

	info(){
		c = '\0';
		final = false;
	}

	info(char car, bool f):c(car),final(f){}

	bool operator== (const info inf) const{
		return ((c == inf.c) && (final == inf.final));
	}
};

class Diccionario{
	private:
		ArbolGeneral<info> datos;
	public:
		/**
		  * @brief Construye un diccionario vacío.
		  */
    	Diccionario();

		/**
		  * @brief Devuelve el número de palabras en el diccionario.
		  */
    	int size() const;

		/**
		  * @brief Obtiene todas las palabras en el diccionario de una longitud dada.
		  * @param longitud: la longitud de las palabras de salida.
		  * @return Un vector con las palabras de longitud especifica en el parámetro de entrada.
		  */
    	vector<string> PalabrasLongitud(int longitud);

		/**
		  * @brief Indica si una palabra está en el diccionario o no.
		  * @param palabra: la palabra que se quiere buscar.
		  * @return true si la palabra está en el diccionario. False en caso contrario.
		  */
    	bool Esta(string palabra);
		
		/** 
		  * @brief Lee de un flujo de entrada un diccionario.
		  * @aparam is: flujo de entrada.
		  * @param D: el objeto donde se realiza la lectura.
		  * @return El flujo de entrada.
		  */
		friend istream & operator>>(istream & is, Diccionario &D);

		/** 
		  * @brief Escribe en un flujo de salida un diccionario.
		  * @param os: flujo de salida.
		  * @param D: el objeto diccionario que se escribe.
		  * @return El flujo de salida.
		  */
		friend ostream & operator<<(ostream & os, const Diccionario &D);
    

	/** 
     * @brief TDA. Iterador de Diccionario
     * */
		class iterator{
			private:
				ArbolGeneral<info>::iter_preorden it;
				string cad; // Mantiene los carácteres desde el nivel 1 hasta donde se encuentra it.
			public:
			  /**
	  			* @brief Constructor por defecto
	  			* 
	  			* */
				iterator (){}

			  /**
	  			* @brief Obtiene la palabra almacenada hasta el momento
	  			* 
	 			* */
				string operator *(){
					return cad;
				}

			  /**
	  		  	* @brief Obtiene un iterador al siguiente info
	  			* 
	  			* */
				iterator & operator ++(){
					if((*it).final)
						cad.clear();

					++it;

					cad.push_back((*it).c);

                    return *this;
				}

			  /**
	  			* @brief Compara dos iteradores
	  			* @param i: iterador con el  que se compara
	  			* @return true si los dos iteradores son iguales. False en caso contrario
	  			* */
				bool operator ==(const iterator &i){
					return (*this == i) || (cad == i.cad);
				}

			  /**
	  			* @brief Compara dos iteradores
	  			* @param i: iterador con el  que se compara
	  			* @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
	  			* */
				bool operator !=(const iterator &i){
					return (*this != i) || (cad != i.cad);
				}

			  /**
			  	* @brief Muestra si cad es unca palabra de diccionario
			  	*/
				bool FinPalabra(){
					return (*it).final;
				}

				friend class Diccionario;
		};

/** 
     * @brief TDA. Const_iterador de Diccionario
     * */
		class const_iterator{
			private:
				ArbolGeneral<info>::const_iter_preorden it;
				string cad; // Mantiene los carácteres desde el nivel 1 hasta donde se encuentra it.
			public:
			  /**
	  			* @brief Constructor por defecto
	  			* 
	  			* */
				const_iterator (){}

			  /**
	  			* @brief Obtiene la palabra almacenada hasta el momento
	  			* 
	 			* */
				const string operator *(){
					return cad;
				}

			  /**
	  		  	* @brief Obtiene un iterador al siguiente info
	  			* 
	  			* */
				const_iterator & operator ++(){
					if((*it).final)
						cad.clear();

					++it;

					cad.push_back((*it).c);
					
					return *this;
				}

			  /**
	  			* @brief Compara dos iteradores
	  			* @param i: iterador con el  que se compara
	  			* @return true si los dos iteradores son iguales. False en caso contrario
	  			* */
				bool operator ==(const const_iterator &i){
					return (*this == i) || (cad == i.cad);
				}

			  /**
	  			* @brief Compara dos iteradores
	  			* @param i: iterador con el  que se compara
	  			* @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
	  			* */
				bool operator !=(const const_iterator &i){
					return (*this != i) || (cad != i.cad);
				}

			  /**
			  	* @brief Muestra si cad es unca palabra de diccionario
			  	*/
				bool FinPalabra(){
					return (*it).final;
				}

				friend class Diccionario;
		};

    /**
     * @brief Inicializa un iterador a la primera palabra del diccionario.
     */
		iterator begin(){
			iterator it;
			it.it = datos.begin();
			//++it.it;
			return it;
		}

		const_iterator begin() const{
			const_iterator it;
			it.it = datos.begin();
			//++it.it;
			return it;
		}


	/**
      * @brief Inicializa un iterador al nodo nulo con la raiz del arbol. Nivel -1
      */
		iterator end(){
			iterator it;
			it.it = datos.end();
			return it;
		}
		
		const_iterator end() const{
			const_iterator it;
			it.it = datos.end();
			return it;
		}
};

#endif