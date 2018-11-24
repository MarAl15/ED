#ifndef __Bolsa_Letras_h__
#define __Bolsa_Letras_h__

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Conjunto_Letras.h"

using namespace std;

/**
   @brief T.D.A. Bolsa_Letras
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Bolsa de Letras almacena carácteres
   correspondientes a una letra de un Conjunto de Letras. Este carácter aparece en 
   la Bolsa_Letras repetido tantas veces como diga el campo cantidad de la letra.
   Y esta formada por un vector aleatorio de vocales y otro de consonantes.

   -Un objeto vacío (bolsa de letras vacía) si no contiene ninguna letra. 
   Lo denotamos {}.
   -En la Bolsa de Letras aparecen las letras de forma aleatoria.
     
   
   Para poder usar el tipo de dato Bolsa_Letras se debe incluir el fichero
   
   <tt>\#include Bolsa_Letras.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es las 
   letras que contienen en total vocales y consonantes.
   
   @author Alguacil Camarero, Mª del Mar
   @author Verona Almeida, Marta
   @date Enero 2015
*/

class Bolsa_Letras{
private:
	vector<char> vocales;
	vector<char> consonantes;
	
public:
    /**
     *@brief Constructor por defecto
     */
	Bolsa_Letras();

    /**
      *@brief Inicializa el dato miembro vocales de forma aletoria
      *@param c Objeto de la clase Conjunto_Letras
      *Tiene en cuenta que tienen que ser los especificados por el fichero letras,
      * por eso necesita c como parametro
      */
	void vocalAleatoria(Conjunto_Letras &c);
    
    /**
     *@brief Inicializa el dato miembro consonante de forma aleatoria
     *@param c Objeto de la clase Conjunto_Letras
     *
     *Tiene en cuenta que tienen que ser los especificados por el fichero letras, 
     * por eso necesita c como parametro
     */
	void consonanteAleatoria(Conjunto_Letras &c);

    /**
     *@brief vector vocales
     *
     *@return dato miembro vocales
     */
	vector<char>getVocales(){
		return vocales;
	}
    /**
     *@brief vector consonantes
     *
     *@return dato miembro consonantes
     */
    vector<char>getConsonantes(){
        return consonantes;
    }
   
};

#endif