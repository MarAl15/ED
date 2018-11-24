/**  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor
  *
  */

#ifndef __TRADUCTOR
#define __TRADUCTOR

#include <iostream>
#include <vector>
#include <string>
#include "palabra.h"
#include "diccionario.h"

using namespace std;

/**
  * @brief T.D.A. Traductor
  *
  * Una instancia @e t del tipo de datos abstracto @t Traductor es un objeto
  * del conjunto formado  por el "array" de Diccionario utilizado para la 
  * separación del vector de la clase Palabra según las letras del abecedario,
  * formando asi un diccionario ordenado por los primeros carácteres del
  * alfabeto de la palabra en el idioma origen. Lo representamos por: 
  *
  * diccionarioLetras
  *
  * Un ejemplo de su uso:
  * @include pruebatraductor.cpp
  *
  * @author Mª del Mar Alguacil
  */

class Traductor{
    private:
/**
  * @page repConjunto Rep del TDA Traductor
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es que \e rep.diccionarioLetras tenga un tamaño fijo de 27 ('Z'-'A'+2),
  * ya que incluimos tanto al alfabeto como al punto.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Traductor representa: 
  *
  * rep.diccionarioLetras[0] / (rep.diccionarioLetras[0].letra = 'a') \n
  * ... \n
  * rep.diccionarioLetras[tamAlfabeto-2] / (rep.diccionarioLetras[tamAlfabeto-2].letra = 'z') \n
  * rep.diccionarioLetras[tamAlfabeto-1] / (rep.diccionarioLetras[tamAlfabeto-1].letra = '.') \n
  */

		/**Tamaño del vector diccionarioLetras*/
		static const int tamAlfabeto = 'Z'-'A'+3;
 
		/**Vector de la clase Diccionario*/
		Diccionario diccionarioLetras[tamAlfabeto]; 

    public:

/**
  * @brief Inicializamos las letras de diccionarioLetras de la 'A' hasta la 'Z'
  */
		void Inicializar();

/**
  * @brief Constructor por defecto.
  */
        Traductor(); 

/** 
  * @brief Función de asignación al vector de Palabra, diccionario.
  * @param palabra -> Vector de Palabra, el cual se incluye en diccionarioLetras.dicLetra, introduciendo cada elemento 
  * 	de la clase Palabra en diccionarioLetras[indice].dicLetra, cuyo indice sea donde se encuentra la letra que coincida
  * 	con el primer carácter de la palabra en el idioma origen.
  */
        void Asignar(vector <Palabra> palabras); 

/** 
  * @brief Constructor por parámetros. Crea un diccionarioLetra nuevo, inicializándolo con otro ya creado.
  * @param palabras -> Vector de elemento de la clase Palabra para inicializar la clase rellenando diccionarioLetras.dicLetra,
  */
        Traductor(vector <Palabra> palabras);

/**
  * @brief Constructor de copia. Crea un elemento de esta clase, inicializándolo con otro ya creado.
  * @param t -> Elemento de esta clase, con el cual se quiere inicializar.
  */
        Traductor(const Traductor &t);

/**
  * @brief Destructor.
  */
		~Traductor() {};

/**
  * @brief Función para cambiar la primera letra a mayúscula.
  * @param palabra -> Palabra que se quiere transformar la primera letra a mayúscula.
  */
		string CambiarMayuscula(const string palabra);

/**
  * @brief Función para ordenar diccionarioLetras por orden alfabético.
  */
		void Ordenar();

/**
  * @brief Separar el vector de palabras, diccionario, por letras de la A hasta Z.
  * 	Inserta en dicLetra del "array" de diccionarioLetras cuyo indice es la diferencia
  * 	de la primera letra de la palabra origen de "palabra" y A. Esto se ha para incluir 
  * 	dicha "palabra" en el Diccionario cuya letra sea igual a la primera de la palabra origen.
  */
		void IncluirEnDiccionario(Palabra palabra);

/** 
  * @brief Entrada de un Traductor desde istream. 
  * @param is -> Stream de entrada.
  * @param traductor -> Elemento de esta clase que quiere ser leido
  * @retval Todas las palabras leídas en el idioma origen y en el de destino.
  * @pre Los elementos de la clase Palabra tienen que estar en distintas líneas.
  */
        friend istream& operator>> (istream& is,Traductor &traductor);

/**
  * @brief Función para localizar una palabra en el diccionario.
  * @param palabra_buscada -> Palabra que queremos encontrar.
  * @param incide -> Posicion de la primera letra de la palabra en diccionarioLetras.
  * @return Si palabra_buscada se halla en el diccionario se devuelve la posición en que se encuentra,
  *     y -1, si esto no ocurriese.
  */
        int Localizar(string palabra_buscada, int indice);

/**
  * @brief Traducción de una sola palabra.
  * @param palabra_origen -> Palabra la cual queremos saber su traducción
  *     en el idioma destino.
  * @return Palabra/s traducidas al idioma destino.
  */
		vector <string> GetTraducciones(string palabra_origen);	

/** 
  * @brief Salida de un Traductor desde ostream. 
  * @param os -> Stream de salida.
  * @param traductor -> Elemento de esta clase que quiere ser escrito.
  * @post Se obtiene un diccionario ordenado según el orden alfabético.
  */
        friend ostream & operator<<(ostream& os, const Traductor &traductor);
};

#endif 