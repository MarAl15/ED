#ifndef __Conjunto_Letras_h_
#define __Conjunto_Letras_h_

#include "Letras.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 @brief T.D.A. Conjunto_Letras
 
 \b Definición:
 Una instancia \e a del tipo de dato abstracto Conjunto_Letras sobre un dominio
 \e Letra se puede construir como
 
 - Un objeto vacío (conjunto vacío) si no contiene ningún elemento.
 Lo denotamos {}.
 - Conjunto formado a partir del tipo de dato abstracto Letra, es decir, 
 una coleccion de Letras.
 
 
 Para poder usar el tipo de dato Conjunto_Letras se debe incluir el fichero
 
 <tt>\#include Conjunto_Letras.h</tt>
 
 El espacio requerido para el almacenamiento es O(n), donde n es el número de
 letras que contiene el fichero de entrada.
 
 @author Alguacil Camarero, Mª del Mar
 @author Verona Almeida, Marta
 @date Enero 2015
 */

class Conjunto_Letras{
private:
    multiset<Letras> letras;
public:
    /**
     *@brief Constructor por defecto
     */
    Conjunto_Letras(){}
    
    /**
     *@brief comprueba si es vocal
     *@param l char a comprobar
     *@return bool true si es vocal, false si no lo es
     */
	bool vocal(char l){
		return ((l=='A') || (l=='E') || (l=='I') || (l=='O') || (l=='U'));
	}
  
    /**
     *@brief Hallar las vocales del conjunto
     *
     *@return Vector con las vocales del conjunto
     */
	vector<char> devuelveVocales();
    
    
    /**
     *@brief Halla consonantes del conjunto
     *
     *@return Vector con las consonantes del conjunto
     */
    vector<char> devuelveConsonantes();

    
    /**
     *@brief Operator extracción de flujo
     *@param is Stream de entrada
     *@param C conjunto de letras a leer
     *@return Referencia al stream de entrada
     */
    friend istream & operator >>(std::istream &is, Conjunto_Letras &C);

    /**
     *@brief Puntuacion de una palabra
     *@param palabra String a calcular
     *@return Suma de las puntuaciones de las letras que componen palabra
     */
    int getPuntuacion(string palabra);
};

#endif
