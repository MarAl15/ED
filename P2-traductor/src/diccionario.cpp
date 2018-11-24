#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "palabra.h"
#include "diccionario.h"

/*Contructor por defecto */
Diccionario::Diccionario(){
}

/* Constructor por parámetros */
Diccionario::Diccionario(char let, vector <Palabra> dic){
	Asignar(let,dic);
}

/*Constructor de copia */
Diccionario::Diccionario(const Diccionario &diccionario){
	Asignar(diccionario.letra, diccionario.dicLetra);
}

/* Función para asignar la letra */
void Diccionario::SetLetra(char letra){
	this->letra = letra;
}

/* Función para ampliar el vector de Palabra dicLetra */
void Diccionario::AumentarDicLetra(Palabra palabra){
	dicLetra.push_back(palabra);
}

/* Función para asignar el vector de Palabra */
void Diccionario::SetDicLetra(vector <Palabra> dicLetra){
	this->dicLetra = dicLetra;
}

/* Función para asignar tanto la letra como el vector de Palabras*/
void Diccionario::Asignar(char let,vector <Palabra> dic){
	SetLetra(let);
	SetDicLetra(dic);
}

/* Función para convertir string en char* */
char * Diccionario::ConvertirString(const string palabra_convertir){
	char * cad;
	int tope = palabra_convertir.size();
	
	cad = new char[100];

	for(int i=0; i<tope; i++)
		cad[i] = palabra_convertir.at(i);
	
	return cad;
	
	delete [] cad;
}

/* Función de ordenación del vector dicLetra */
void Diccionario::Ordenar(){
	bool cambio = true;
	int tamanio = dicLetra.size();
	Palabra aux;
	string cad;
	char *cad3,*cad4;

	cad3 = new char[100];
	cad4 = new char[100];	
 
	for(int i=1; i<tamanio-1 && cambio; i++){
		cambio = false;
		for(int j=0; j<tamanio-i-1; j++){

			// Convertimos cada palabra_origen de dicLetra en un char*
			//	para poderlas comparar
			cad = dicLetra.at(j).GetPalabraOrigen();
			cad3 = ConvertirString(cad);

			cad = dicLetra.at(j+1).GetPalabraOrigen();
			cad4 = ConvertirString(cad);

			// Comparamos las dos cadenas, y si cad3 es "mayor" ,segun el alfabeto, que cad4
			// 	intercambiamos ambas
			if(strcmp(cad3,cad4)>0){
				cambio = true;
				aux = dicLetra.at(j);
				dicLetra.at(j) = dicLetra.at(j+1);
				dicLetra.at(j+1) = aux;
			}
		}
	}


	delete [] cad3;
	delete [] cad4;
}

/* Sobrecarga del operador de asignación */
const Diccionario & Diccionario::operator=(const Diccionario &d){
	Asignar(d.letra, d.dicLetra);

	return *this;
}

/* Sobrecarga del operador <<, para la salida de datos */
ostream & operator<<(ostream& os, const Diccionario &d){
	int tope = d.dicLetra.size();

	os <<"\nLetra: " << d.letra << endl;

	for(int i=0; i<tope; i++)
		os << d.dicLetra.at(i) << endl;

	return os;
}


