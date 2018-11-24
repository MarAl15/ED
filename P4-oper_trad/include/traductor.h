/**
  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor
  */

#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "palabra.h"

using namespace std;

/**
  *  @brief T.D.A. Traductor
  *
  * Una instancia @e c del tipo de datos abstracto @c Traductor es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por el primer elemento del par denominado clave o key. Que en este caso es
  * la palabra en el idioma origen.
  *
  * @author Mª del Mar Alguacil
  * @date Diciembre 2014
  */

class Traductor{

/**
  * @page repTraductor Rep del TDA Traductor
  *
  * @section invTraductor Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e2i y e2j son distintos
  *		si e1i y e1j son iguales
  *
  * @section faTraductor Función de abstracción
  *
  * Un objeto válido @e rep del TDA Traductor representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */

    private:
		/** Diccionario del traductor */
        multimap <Palabra,Palabra> diccionario;

    public:

/**
  * @brief Constructor por defecto.
  */
        Traductor();  

/**
  * @brief Constructor por parámetros. 
  * @param palabras: Diccionario que se quiere copiar para iniciar la clase.
  */
        Traductor(multimap <Palabra,Palabra> palabras);

/** 
  * @brief Constructor de copia.
  * @param t.traductor: Diccionario para copiar al inicializar la clase.
  */
        Traductor(const Traductor &t);

		    
/**
  * @brief Acceso a un elemento.
  * @param palabra: Palabra en el idioma origen.
  * @return Palabras asociadas a las traducciones.
  */
		
		vector<string> GetTraducciones(const string & palabra) const;
  
/**
  * @brief Inserta un nueva palabra en el diccionario.
  * @param origen: Palabra en el idioma origen.
  * @param destino: Palabra/s en la lengua destino.
  * @return Un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado la nueva traducción o 
  * 	o false en caso contrario.
  */
		pair<multimap<Palabra,Palabra>::iterator,bool> insert(Palabra origen, Palabra destino);
		    
/**
  * @brief Inserta una nueva palabra.
  * @param p: pair con la palabra en el idioma origen y la traduccion asociada.
  * @return Un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertada la nueva traduccion o 
  *		o false en caso contrario.
  */
		pair<multimap<Palabra,Palabra>::iterator,bool> insert(pair<Palabra,Palabra> p);
		    
/**
  * @brief Borrar una palabra del diccionario y sus traducciones.
  * @param origen: Palabra en el idioma origen la cual se quiere borrar.
  */
		void borrar(const string &origen);
		    
/**
  * @brief Borrar una palabra con una de sus traducciones del diccionario.
  * @param origen: Palabra que se quiere borrar y traducción asociado.
  * @param destino: Traducción de la palabra que se quiere borrar.
  * @note Esta función permite borrar solamente aquella que coincida en la palabra y la traducción pasada como argumento.
  */
		void borrar(const Palabra &origen,const Palabra &destino);
		   
/**
  * @brief  Número de palabras en el diccionario.
  * @return Número de palabras asociadas.
  */
		int size()const{
			return diccionario.size();
		}	      
		    
/**
  * @brief Contabiliza cuantas traducciones tenemos asociados a una palabra.
  * @param origen: Palabra en el idioma origen sobre la que queremos consultar.
  * @return Traducciones asociadas a una palabra
  */

		unsigned int contabiliza(const Palabra &origen){
			return diccionario.count(origen);
		}
		    
/**
  * @brief Limpia el diccionario.
  */
		void clear(){
			diccionario.clear();
		}	 
		    
/**
  * @brief  Obtiene un diccionario con las palabras previas a una dada.
  * @param origen: Palabra delimitadora.
  * @param destino: Traducción asociada a palabra.
  * @return Nuevo diccionario sin palabras mayores que \a origen.
  */
		Traductor previos(const Palabra &origen,const Palabra &destino);  

/**
  * @brief  Obtiene un diccionario con las palabras del diccionario que se encuentra en d.
  * @param d: Traductor el cual contiene el diccionario a asignar.
  * @return Diccionario modificado.
  */
		Traductor operator=(const Traductor & d);    

/**
  * @brief Lectura del diccionario.
  * @param is: flujo de entrada. Es modificado.
  * @param d: diccionario. Es modificado.
  * @return El flujo de entrada.
  */
		    
		friend istream & operator>>(istream & is, Traductor & d);
		    

/**
  * @brief clase para iterar sobre el diccionario.
  */
	class iterator{
		private:
			multimap<Palabra,Palabra>::iterator it;
		
		public:	
			iterator(){}
			iterator(multimap<Palabra,Palabra>::iterator i):it(i){}
			iterator & operator++(){
				++it;
				return *this;
			}
			iterator & operator--(){
				--it;
				return *this;
			}

			pair<const Palabra,Palabra> &operator *(){
				return *it;
			}

			iterator & operator=(const iterator &i){
				it = i.it;
				return *this;
			}

			bool operator ==(const iterator &i){
				return i.it==it;
			}	  
		       
			bool operator !=(const iterator &i){
				return i.it!=it;
			}

			friend class Traductor;
			friend class const_iterator;
	};

/**
  * @brief clase constante para iterar sobre el diccionario.
  */
	class const_iterator{
		private:
			multimap<Palabra,Palabra>::const_iterator it;
			
		public:
			const_iterator(){}
			const_iterator(const const_iterator& v):it(v.it){}
			const_iterator & operator++(){
				++it;
				return *this;
			}
			const_iterator & operator--(){
				--it;
				return *this;
			}

			const pair<const Palabra,Palabra> &operator *() const{
				return *it;
			}
			const_iterator & operator=(const const_iterator &i){
				it = i.it;
				return *this;
			}

			const_iterator & operator=(const iterator &i){
				it = i.it;
				return *this;
			}

			const_iterator & operator=(multimap<Palabra,Palabra>::iterator i){
				it = i;
				return *this;
			}

			bool operator ==(const const_iterator &i) const{
				return i.it==it;
			}	  
		       
			bool operator !=(const const_iterator &i) const{
				return i.it!=it;
			}

			friend class Traductor;
	};
		    
/**
  * @brief Inicializa un iterator al comienzo del diccionario.
  */
		iterator begin(){
			iterator i;
			i.it = diccionario.begin();
			return i;
		}

/**
  * @brief Inicializa un iterator al final del diccionario.
  */
		iterator end(){
			iterator i;
			i.it=diccionario.end();
			return i;
		} 

/**
  * @brief Inicializa un iterator constante al comienzo del diccionario
  */
		const_iterator begin() const{
			const_iterator c;
			c.it = diccionario.begin();
			return c;
		}

/**
  * @brief Inicializa un iterator constante al final del diccionario.
  */
		const_iterator end() const{
			const_iterator c;
			c.it = diccionario.end();
			return c;
		} 

/**
  * @brief Sobrecarga del operador de comparación <.
  */
	inline bool operator<(const Traductor &i) const{
		return diccionario < i.diccionario;
	}	        
};

#endif
