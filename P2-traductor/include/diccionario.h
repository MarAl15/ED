/**  * @file diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef __DICCIONARIO
#define __DICCIONARIO

#include <iostream>
#include <vector>
#include "palabra.h"

using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia @e d del tipo de datos abstracto @d Diccionario es un objeto
  * del conjunto formado por una letra y por un vector de la clase Diccionario, 
  * el cual contiene elementos de la clase Palabra, cuya palabra en el idioma
  * origen comienza por dicha letra. Lo representamos por:
  *
  * letra - dicLetra
  *
  *
  * @author Mª del Mar Alguacil
  */

class Diccionario{

	private:
/**
  * @page repConj Rep del TDA Diccionario
  *
  * @section invConj Invariante de la representación
  *
  * El invariante es que en \e rep.dicLetra, cada una de las palabras en 
  * el idioma origen comiencen por el carácter que contiene \e rep.letra.
  *
  * @section faConj Función de abstracción
  *
  * Un objeto válido @e rep del TDA Diccionario representa: 
  *
  * rep.letra \n
  * rep.dicLetra[0] \n
  *	... \n
  * rep.dicLetra[n-1] \n
  */

		/**Carácter del alfabeto por el cual empiezan 
			las palabras en el idoma origen de dicLetra*/
		char letra; 

		/**Vector de Palabra*/
		vector <Palabra> dicLetra; 

	public:

/** 
  * @brief Constructor por defecto.
  */
		Diccionario();

/** 
  * @brief Función para la asignación del dato privado letra.
  * @param letra -> carácter que contiene la letra a asignar a this->letra.
  */

		void SetLetra(char letra);

/** 
  * @brief Función para la asignación del dato privado dicLetra.
  * @param dicLetra -> vector que contiene elementos de la clase Palabra a asignar a this->dicLetra.
  */
		void SetDicLetra(vector <Palabra> dicLetra);

/**
  * @brief Función para la asignación de los datos privados.
  * @param letra -> carácter que contiene la letra a asignar a this->letra.
  * @param dicLetra -> vector que contiene elementos de la clase Palabra a asignar a this->dicLetra.
  */
		void Asignar(char let,vector <Palabra> dic);

/** 
  * @brief Constructor por parámetros. Crea un elemento de esta clase con la letra y las palabras
  * 	pasadas como párametros.
  * @param let -> Carácter con que queremos inicializar letra.
  * @param dic -> vector de Palabra para inicializar dicLetra.
  */

		Diccionario(char let, vector <Palabra> dic);

/** 
  * @brief Contructor de copia. Crea un elemento de esta clase a partir de otro ya creado.
  * @param diccionario -> elemento de esta clase, con el cual se quiere inicializar
  */

		Diccionario(const Diccionario &diccionario);

/**
  * @brief Destructor.
  */

		~Diccionario() {}

/** 
  * @brief Letra
  * @return Dato privado letra.
  */
		inline char GetLetra(){
			return letra;
		}

/**
  * @brief Vector de Palabra
  * @return Dato privado dicLetra.
  */

		inline vector <Palabra> GetDicLetra(){
			return dicLetra;
		}

/** 
  * @brief Función inline para devolver el tamaño del vector de Palabra dicLetra.
  * @return Tamaño de dicLetra. 
  */

		inline const int GetTamanio(){
			return dicLetra.size();
		}
	
/** 
  * @brief Función para introducir nuevas palabras a DicLetra.
  * @param palabra -> Palabra a introducir en el vector dicLetra.
  */
		void AumentarDicLetra(Palabra palabra);

/**
  * @brief Convertir un string a char*
  * @param palabra_convertir -> Palabra la cual se quiere pasar de string a char*.
  * @return Puntero de carácteres con la palabra_convertir.
  */
		char *ConvertirString(const string palabra_convertir);

/** 
  * @brief Función para la ordenación del vector de Palabra dicLetra, por orden alfabético.
  */
		void Ordenar();

/** 
  * @brief Sobrecarga del operador de asignación.
  * @param d -> elemento de esta clase al que se quiere igualar.
  */
		const Diccionario &operator=(const Diccionario &d);

/** 
  * @brief Salida de un Diccionario desde ostream.
  * @param os -> Stream de salida.
  * @param d -> Elemento de esta clase, el cual quiere ser escrito.
  * @post Se obtiene la letra con la cual comienzan todas las palabras en el idioma origen de dicLetra,
  * 	y los elementos de dicLetra.
  */

		friend ostream & operator<<(ostream& os, const Diccionario &d);
};

#endif