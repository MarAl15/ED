/**  * @file palabra.h
  * @brief Fichero cabecera del TDA Palabra
  *
  */

#ifndef __PALABRA
#define __PALABRA

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
  * @brief T.D.A. Palabra
  *
  * Una instancia @e p del tipo de datos abstracto @p Palabra es un objeto
  * del conjunto de palabras, donde tenemos un vocablo en el idioma origen
  * y uno/s en el idioma destino. Lo representamos por:
  *
  * palabra_origen--->palabras_destino
  *
  *
  * @author Mª del Mar Alguacil
  */

class Palabra{

    private:
/**
  * @page repC Rep del TDA Palabra
  *
  * @section invC Invariante de la representación
  *
  * El invariante es que \e rep.palabra_origen y \e rep.palabras_destino[i] no contengan ni tíldes 
  * 	ni el caracter ñ, para todo i perteneciente a los naturales comprendidos en el intervalo [0,n-1]. 
  *
  * @section faC Función de abstracción
  *
  * Un objeto válido @e rep del TDA Palabra representa:
  *
  * Palabra en el idioma origen: \n
  * 	-- rep.palabra_origen \n
  * Palabra/s en el idioma destino: \n
  * 	1) rep.palabras_destino[0] \n
  *		... \n
  * 	n) rep.palabras_destino[n-1] \n
  */

		/**Palabra en el idioma origen*/
        string palabra_origen; 

		/**Palabra/s en el idioma destino*/
        vector <string> palabras_destino; 

    public:

/** 
  * @brief Función de asignación a palabra_origen y palabras_destino.
  * @param origen -> palabra en el idioma origen, la cual se le asigna a palabra_origen.
  * @param destino -> palabra/s en la lengua destino, la/s cual/es se le asignan a palabras_destino.
  */
        void Asignar(string origen, vector <string> destino);

/**
  * @brief Constructor por defecto.
  */
        Palabra() {}

/** 
  * @brief Constructor por parámetros. Crea una Palabra con palabra_origen = origen y 
  * 	palabra_destino = destino.
  * @param origen -> Palabra en el idioma origen, la cual se quiere traducir.
  * @param destino -> Palabra/s traducida/s a la lengua destino.
  * @pre Ninguna palabra debe contener ni acentos ni la letra ñ.
  */
        Palabra(string origen, vector <string> destino);

/** 
  * @brief Constructor de copia. Crea una Palabra inicializada con los datos privados de otra, p.
  * @param p.palabra_origen -> Palabra en el idioma origen de la Palabra a construir.
  * @param p.palabras_destino -> Palabra/s en la lengua destino de la Palabra a construir.
  */
        Palabra(const Palabra &p);
/**
  * Destructor.
  */
 		~Palabra() {}

/** 
  * @brief Palabra en el idioma origen.
  * @return String palabra_origen.
  */
        inline string GetPalabraOrigen(){
			return palabra_origen;
		}

/** 
  * @brief Palabra/s en el idioma destino.
  * @return Vector de string de palabras_destino.
  */
        inline vector <string> GetPalabraDestino(){
			return palabras_destino;
		}

/** 
  * @brief Entrada de una Palabra desde istream (Función amiga).
  * @param is -> Stream de entrada.
  * @param pal -> Palabra que recibe el resultado.
  * @retval La Palabra leída en pal.
  * @pre La entrada tiene ser que ser primero la palabra en el idioma origen y 
  * 	a continuación la/s palabra/s en la lengua destino, separadas por ";".
  */
        friend istream& operator>> (istream& is, Palabra& pal);

/** 
  * @brief Comparación de dos Palabras.
  * @param p -> Referencia a un elemento de la clase Palabra.
  * @return True si p.palabra_origen y p.palabra_destino es igual a palabra_origen
  *     y palabra_destino respectivamente y, false en caso contrario.
  */
        bool operator==(const Palabra &p) const;

/** 
  * @brief Se le asigna los valores de p, a this
  * @param p -> Referencia a un elemento de la clase Palabra.
  * @return Este elemento (*this).
  */
        const Palabra &operator=(const Palabra &p);

/** @brief Salida de una Palabra desde ostream.
  * @param os -> Stream de salida.
  * @param pal -> Palabra a escribir.
  * @post Se obtiene la palabra en el idioma origen y las traducciones de esta
  * 	en la lengua destino.
  */
        friend ostream & operator<<(ostream &os, const Palabra &pal);            

};

#endif