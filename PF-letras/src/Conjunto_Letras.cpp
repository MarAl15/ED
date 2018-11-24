#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "Conjunto_Letras.h"
#include "Letras.h"

using namespace std;


vector<char> Conjunto_Letras::devuelveVocales()	{
    vector<char> vocales;
    
    multiset <Letras>::iterator i;
    
    for(i=letras.begin(); i!=letras.end(); ++i){
        if(vocal((*i).Letra()))
            vocales.push_back((*i).Letra());
        
    }
    return vocales;
}



vector<char> Conjunto_Letras::devuelveConsonantes(){
    vector<char> consonantes;
    
    multiset <Letras>::iterator i;
    
    for(i=letras.begin(); i!=letras.end(); ++i){
        if(!vocal((*i).Letra()))
            consonantes.push_back((*i).Letra());
    }
    
    return consonantes;
    
}

int Conjunto_Letras::getPuntuacion(string palabra){
    multiset<Letras>::iterator it;
    
    bool encontrada;
    int puntuacion = 0 ;
    for(unsigned int i = 0 ; i < palabra.size() ;i++){
        encontrada = false;
        for(it= letras.begin() ; it != letras.end() && !encontrada ; ++it){
            if(palabra.at(i) == (*it).Letra()){
                encontrada = true;
                puntuacion += (*it).Puntuacion();
            }
        }
    }
    
    return puntuacion;
}

istream & operator >>(std::istream &is, Conjunto_Letras &C){
    Letras nueva;
    string aux;
    vector<string> n;
    
    if(!is.eof())
        getline(is,aux);
    
    char l;
    int c,p;
    while(!is.eof()){
        is>>l;
        is>>c;
        is>>p;
        
        nueva.asignaLetra(l);
        nueva.asignaNum(c);
        nueva.asignaPuntos(p);
        
        for(int i = 0 ; i < c; i++){
            C.letras.insert(nueva);
        }
        
    }
    
    return is;
}

