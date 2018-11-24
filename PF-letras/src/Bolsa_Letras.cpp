#include <iostream>
#include <vector>
#include <cstdlib>
#include "Bolsa_Letras.h"
#include "Conjunto_Letras.h"

using namespace std;

Bolsa_Letras::Bolsa_Letras(){
}

void Bolsa_Letras::vocalAleatoria(Conjunto_Letras &c){
	vector<char>aux = c.devuelveVocales();
	int i,pos; 
		

	while( !aux.empty()){
	 	i = aux.size();

		pos = rand() % i;

		vocales.push_back(aux.at(pos));
		aux.erase(aux.begin()+pos);
	
	}
}

void Bolsa_Letras::consonanteAleatoria(Conjunto_Letras &c){
	vector<char>aux = c.devuelveConsonantes();
	int i,pos; 

	while( !aux.empty()){
		i = aux.size();

		pos = rand() % i;

		consonantes.push_back(aux.at(pos));
		aux.erase(aux.begin()+pos);

	}
}