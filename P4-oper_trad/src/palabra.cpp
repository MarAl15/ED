#include "palabra.h"
#include <string>
#include <cassert>

Palabra::Palabra(){
}

Palabra::Palabra(string nueva_palabra){
	insert(nueva_palabra);
}

Palabra::Palabra(const Palabra &p){
	insert(p.palabra);
}

void Palabra::insert(string nueva_palabra){
	palabra = nueva_palabra;
}

bool Palabra::operator==(const Palabra &p) const{
	return palabra == p.palabra;
}

Palabra & Palabra::operator=(const Palabra &p){
	//Se evita la autoasignación
    if(&p != this){
        //Le asignamos el nuevo valor
        insert(p.palabra);
    }

    //Se devuelve este objeto
    return *this;
}

