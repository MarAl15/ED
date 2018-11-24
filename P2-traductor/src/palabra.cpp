#include <iostream>
#include <vector>
#include <string>

#include "palabra.h"

/* Constructor por parámetros */
Palabra::Palabra(string origen, vector <string> destino){
    Asignar(origen, destino);
}

/* Constructor de copia */
Palabra::Palabra(const Palabra &p){
    Asignar(p.palabra_origen, p.palabras_destino);
    
}

/* Función para asignar a cada uno de los datos privados un valor */
void Palabra:: Asignar(string origen, vector <string> destino){
    palabra_origen = origen;

    int tope = destino.size();

	if(!palabras_destino.empty()){
		palabras_destino.clear();
	}

    for(int i=0; i<tope; i++)
        palabras_destino.push_back(destino.at(i));
}


/* Sobrecarga del operador >> */
istream& operator>> (istream& is, Palabra& pal){
    int posicion_primera;
    string lugar;
    string lectura;

    getline(is, lectura);   // Lee una línea

	/* Leemos la palabra en el idioma origen*/
		//Buscamos el primer ";"
    posicion_primera = lectura.find(';'); 
		//Escribimos la palabra que se encuentra antes del ";" en palabra_origen
    pal.palabra_origen = lectura.substr(0,posicion_primera); 

	/* Leemos la/s palabra/s en el idioma destino */ 
	int tope = lectura.size();
	for(int i=posicion_primera+1; i<tope; i++){
		//Llenamos lugar hasta que llegue a un ";"
		//	e introducimos la palabra en palabras_destino
		if(lectura.at(i) != ';'){
			lugar.push_back(lectura.at(i));
		}else{
			pal.palabras_destino.push_back(lugar);
			lugar.clear();
		}
	}
	
    return is;
}

/* Sobrecarga del operador == */
bool Palabra::operator==(const Palabra &p) const{
    bool igual=true;
    
    // Si el tamaño es diferente directamente decimos que igual es false
    if(p.palabra_origen.size() == palabra_origen.size() &&
        p.palabras_destino.size() == palabras_destino.size()){
        
        int tope_orig = palabra_origen.size();

        // Vemos si son iguales las palabras origenes
        for(int i=0; i< tope_orig && igual; i++){
            // Si una de las letras no coindice al recorrer la palabra 
            // igual es false
            if(p.palabra_origen.at(i) != palabra_origen.at(i))
                igual = false;
        }

        int tope_des1 = palabras_destino.size();
        int tope_des2;

        //	Vemos si son iguales cada una de las palabras destino y si
        // igual sigue siendo true
        for(int j=0; j<tope_des1; j++){
            
			if(palabras_destino.at(j).size() == p.palabras_destino.at(j).size()){
				tope_des2 = palabras_destino.at(j).size();            	
				for(int k=0; k<tope_des2 && igual; k++){
               		if(p.palabras_destino.at(j).at(k) != palabras_destino.at(j).at(k))
                    	igual = false;
            	}
			}else{
				igual = false;
			}
        }
    }
    else{
        igual = false;
    }

    return igual;
}

/* Sobrecarga del operador = */
const Palabra & Palabra:: operator=(const Palabra &p){
    //Se evita la autoasignación
    if(&p != this){
        //Vaciamos el vector de string vector palabras_destino.
        palabras_destino.clear();
        
        //Le asignamos los nuevos valores
        Asignar(p.palabra_origen, p.palabras_destino);
    }

    //Se devuelve este objeto
    return *this;
}

/* Sobrecarga del operador << */
ostream & operator<<(ostream &os, const Palabra &pal){
    os << "\nLa palabra en el idioma origen es: " << endl;
    os << " " << pal.palabra_origen;

    int tope = pal.palabras_destino.size();
    if(tope == 1){
        os << "\nLa palabra en el idioma destino es: " << endl;
        os << "1) " << pal.palabras_destino.at(0);
    }
    else{
        os << "\nLas palabras en el idioma destino son:\n"; 
        for(int i=0; i < tope; i++){
            os << i+1 << ") " << pal.palabras_destino.at(i);
            os << endl;
        }
    }

    return os;
}