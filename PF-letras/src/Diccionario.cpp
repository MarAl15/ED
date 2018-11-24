#include <cassert>
#include <iostream>
#include "ArbolGeneral.h"
#include "Diccionario.h"

using namespace std;


/* Diccionario vacío. */
Diccionario::Diccionario(){
	info x;
	ArbolGeneral <info> aux(x);

	datos = aux;
}

/* Número de palabras en el diccionario. */
int Diccionario::size() const{
    int contador=0;

    typename ArbolGeneral<info>::const_iter_preorden i;

    for(i=datos.begin(); i!=datos.end(); ++i){
    	if((*i).final)
    		contador++;
    }

    return contador;

}

/* Palabras en el diccionario de una longitud dada.  */
vector<string> Diccionario::PalabrasLongitud(int longitud){
    vector<string> palabras;
    
    Diccionario::iterator i;
    typename ArbolGeneral<info>::iter_preorden j = datos.begin();
    int tamanio;
    ++j;

    for(i=begin(); j != datos.end() ; ++i, ++j){
        tamanio = (*i).size();
        if(i.FinPalabra() && longitud == tamanio)
        	palabras.push_back(*i);
    }

    return palabras;
}

/* Indicar si una palabra está en el diccionario o no. */
bool Diccionario::Esta(string palabra){
    Diccionario::iterator i;
    ArbolGeneral<info>::iter_preorden j = datos.begin();
    bool encontrada;
    ++j;

    for(i=begin(); j != datos.end() && !encontrada ;++i, ++j){
        encontrada = false;
        if (i.cad == palabra && i.FinPalabra()){
            encontrada = true;
        }
    }

    return encontrada;
}
		
/* Leer de un flujo de entrada un diccionario. */
istream & operator>>(istream & is, Diccionario &D){
    ArbolGeneral<info>::Nodo nodo = D.datos.raiz();
    //ArbolGeneral<info>::Nodo padre = NULL;
    ArbolGeneral<info> rama;
    string palabra;
    info inf;

    while( !is.eof()){
        getline(is,palabra);

        if(D.datos.hijomasizquierda(nodo) == NULL){
            inf = info(palabra.at(0), palabra.size()==1);
            rama = ArbolGeneral<info>(inf);
            D.datos.insertar_hijomasizquierda(nodo, rama);
        }

        nodo = D.datos.hijomasizquierda(nodo);
        
        while(palabra.at(0) > D.datos.etiqueta(nodo).c){
            if(D.datos.hermanoderecha(nodo) != NULL){
                nodo = D.datos.hermanoderecha(nodo);
            }
            else{
                inf = info(palabra.at(0), palabra.size()==1);
                rama = ArbolGeneral<info>(inf);
                D.datos.insertar_hermanoderecha(nodo, rama);
                nodo = D.datos.hermanoderecha(nodo);
            }
        }

        for(unsigned int i=1; i<palabra.size(); i++){
            if(D.datos.hijomasizquierda(nodo) != NULL){
                if(D.datos.etiqueta(D.datos.hijomasizquierda(nodo)).c == palabra.at(i))
                    nodo = D.datos.hijomasizquierda(nodo);
                else if(D.datos.hermanoderecha(nodo) != NULL && D.datos.etiqueta(D.datos.hermanoderecha(nodo)).c == palabra.at(i))
                    nodo = D.datos.hermanoderecha(nodo);
                else{
                    inf = info(palabra.at(i), palabra.size()==(i+1));
                    rama = ArbolGeneral<info>(inf);
                    D.datos.insertar_hermanoderecha(nodo, rama);
                    nodo = D.datos.hermanoderecha(nodo);
                }
            }
            else{
                inf = info(palabra.at(i), palabra.size()==(i+1));
                rama = ArbolGeneral<info>(inf);
                D.datos.insertar_hijomasizquierda(nodo, rama);
                nodo = D.datos.hijomasizquierda(nodo);
            }
        }
    }

    return is;
    
}

/* Escribr en un flujo de salida un diccionario. */
ostream & operator<<(ostream & os, const Diccionario &D){
	typename ArbolGeneral<info>::const_iter_preorden i;
	typename Diccionario::const_iterator j;

    i = D.datos.begin();
    ++i;

	for(j=D.begin(); i!=D.datos.end(); ++i, ++j){
		if(j.FinPalabra())
			os << (*j) << endl;
	}

	return os;
    
}
