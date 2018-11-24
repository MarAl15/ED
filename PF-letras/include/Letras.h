#ifndef __Letras_h_
#define __Letras_h_

#include <iostream>

using namespace std;

/**
 @brief T.D.A. Letras
 
 \b Definición:
 Una instancia \e a del tipo de dato abstracto Letras se puede construir como
 
 - Un objeto vacío (Letra vacío) si no contiene ningún elemento.
 Lo denotamos {}.
 - Letras formada a partir de un char indicando la l, un entero para la puntuacion 
 de la misma y otro entero para almacenar el numero de veces que aparece.
 
 
 Para poder usar el tipo de dato Letras se debe incluir el fichero
 
 <tt>\#include Letras.h</tt>
 
 @author Alguacil Camarero, Mª del Mar
 @author Verona Almeida, Marta
 @date Enero 2015
 */

class Letras{
private:
    char letra;
    int num;
    int puntuacion;
public:
    /**
     *@brief Constructor por defecto
     */
    Letras(){
        letra=0;
        num = 0;
        puntuacion = 0;
    }
    
    /**
     *@brief Constructor por parametros
     *@param caracter Letra
     *@param num_veces Numero veces que aparece
     *@param puntua Puntuacion de la letra
     */
    Letras(char caracter, int num_veces , int puntua){
        letra= caracter;
        num_veces = num;
        puntuacion = puntua;
    }
    
    /**
     *@brief Letra
     *@return Dato miembro letra
     */
    char Letra() const{
        return letra;
    }
    
    /**
     *@brief Numero de veces que aparece
     *@return Dato miembro num
     */
    int NumVeces(){
        return num;
    }
    
    /**
     *@brief Puntuacion
     *@return Dato miembro puntuacion
     */
    int Puntuacion() const{
        return puntuacion;
    }
    
    /**
     *@brief Asigna letra
     *@param caracter Char a asignar
     */
    void asignaLetra(char caracter){
        letra = caracter;
    }
    
    /**
     *@brief Asigna numero de veces
     *@param n Entro con el numero de veces que aparece
     */
    void asignaNum(int n){
        num = n;
    }
    
    /**
     *@brief Asigna puntuacion
     *@param p Puntuacion a asignar
     */
    void asignaPuntos(int p){
        puntuacion = p;
    }

    /**
     *@brief 
     *@param
     *@return
     */
	bool operator< (const Letras &l) const{
		return (letra < l.letra);
	}
};


#endif /* defined(____Letras__) */
