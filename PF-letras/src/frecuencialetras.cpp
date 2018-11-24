#include <iostream>
#include <fstream>
#include "Letras.h"
#include "Diccionario.h"
#include "Conjunto_Letras.h"
#include<vector>

using namespace std;


int main(int argc, char *argv[]){
	if(argc < 4){
		cout << "\nLos parametros son" 
			<<"\n1: Fichero con diccionario"
			<< "\n2: Fichero con letras"
			<< "\n3:Fichero de salida";
		return 0 ;
	}
	
	Diccionario D;
	ifstream f(argv[1]);
	f >> D;

	Conjunto_Letras C;
	ifstream g(argv[2]);
	g >> C;

	ofstream fsalida(argv[3]);

	int VTAMANIO = 26;
	int frec[VTAMANIO] ;
    
	for(int i=0; i<VTAMANIO; i++){
		frec[i] = 0;
	}
    
	Diccionario::iterator it;


	for(it=D.begin(); it!=D.end(); ++it){
		frec[(*it).at((*it).size()-1)-'a'] = frec[(*it).at((*it).size()-1)-'a'] +1;
	}
    
    cout << "\nLetra  Frecuencia\n";
	for(int i = 0 ; i < VTAMANIO; i++){
        char l = 'A'+i;
		fsalida << l << "  " << frec[i] << endl;
		if( i == VTAMANIO-1)
			fsalida << endl;
	}


}
