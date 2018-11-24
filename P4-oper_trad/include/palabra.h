/**
  * @file palabra.h
  * @brief Fichero cabecera del TDA Palabra
  */

#ifndef __PALABRA
#define __PALABRA

#include <iostream>
#include <string>

using namespace std;

/**
  * @brief T.D.A. Palabra
  *
  * Una instancia @e p del tipo de datos abstracto @p Palabra es un objeto
  * formado por un conjunto de letras, dicha palabra se encuentra en un 
  * idioma cualquiera el cual no contiene ni tildes ni ñ ni letras distintas
  * 26 letras comunes.
  *
  *
  *
  * @author Mª del Mar Alguacil
  * @date Diciembre 2014
  */

class Palabra{

/**
  * @page repPalabra Rep del TDA Palabra
  *
  * @section invPalabra Invariante de la representación
  *
  * El invariante es que \e rep.palabra no contengan ni tíldes ni el caracter ñ
  *
  * @section faC Función de abstracción
  *
  * Un objeto válido @e rep del TDA Palabra representa:
  *
  * Palabra: \n
  * 	-- rep.palabra \n
  */

    private:
		/** Palabra */
        string palabra;  

    public:

/**
  * @brief Constructor por defecto.
  */
		Palabra();

/** 
  * @brief Función de asignación a palabra.
  * @param nueva_palabra: Nueva palabra la cual se le asigna a palabra.
  */
        void insert(string nueva_palabra);

/** 
  * @brief Constructor por parámetros. Crea una Palabra con nueva_palabra.
  * @param nueva_palabra: Palabra en el idioma deseado.
  * @pre Ninguna palabra debe contener ni acentos ni la letra ñ.
  */
        Palabra(string nueva_palabra);

/** 
  * @brief Constructor de copia. Crea una Palabra inicializada con los datos privados de otra, p.
  * @param p.palabra: Palabra en el idioma deseado de la Palabra a construir.
  */
        Palabra(const Palabra &p);
/**
  * Destructor.
  */
 		~Palabra() {}

/** 
  * @brief Palabra.
  * @return String palabra.
  */
        string GetPalabra() const{
			return palabra;
		}

/** 
  * @brief Comparación de dos Palabras.
  * @param p: Referencia a un elemento de la clase Palabra.
  * @return True si p.palabra es igual a palabra y, false en caso contrario.
  */
        bool operator==(const Palabra &p) const;

/** 
  * @brief Se le asigna los valores de p, a this.
  * @param p: Referencia a un elemento de la clase Palabra.
  * @return Este elemento (*this).
  */
        Palabra &operator=(const Palabra &p);   

/**
  * @brief Sobrecarga del operador de comparación <.
  */
		inline bool operator<(const Palabra &i) const{
			return palabra < i.palabra;
		}

/**
  * @brief Escritura de la palabra.
  * @param os: Flujo de salida. Es modificado.
  * @param d: Palabra que se escribe.
  * @return El flujo de salida.
  */

	friend ostream & operator<<(ostream & os, Palabra & d){
		os << d.palabra;

		return os;
	}
};

#endif
