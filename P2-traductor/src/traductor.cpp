#include <string>
#include <iostream>
#include <vector>

#include "palabra.h"
#include "diccionario.h"
#include "traductor.h"

/* Constructor por defecto */
Traductor::Traductor(){
	// Inicializamos las letras de la A hasta la Z
	Inicializar();
}

/* Constructor por parámetros */
Traductor::Traductor(vector <Palabra> palabras){
	// Inicializamos las letras de la A hasta la Z
	Inicializar();

	// Asignamos
	int tope = palabras.size();
	for (int i=0; i<tope; i++)
    	Asignar(palabras);
}

/* Constructor de copia */
Traductor::Traductor(const Traductor &t){
    // Inicializamos las letras de la A hasta la Z
	Inicializar();
	
	// Asignamos
	for(int i=0; i<tamAlfabeto; i++)
		diccionarioLetras[i] = t.diccionarioLetras[i];
}

/* Función para inicializar las letras de la A hasta la Z */
void Traductor::Inicializar(){
	int contador = 0;

	diccionarioLetras[tamAlfabeto-2].SetLetra('.');

	for(char i='A'; i<='Z'; i++){
		diccionarioLetras[contador].SetLetra(i);
		contador++;
	}
}

/* Función asignar en el vector de Palabra diccionario */
void Traductor:: Asignar(vector <Palabra> palabras){
    int tope = palabras.size();
    for(int i=0; i<tope; i++)
        IncluirEnDiccionario(palabras.at(i));
}

/* Sobrecarga del operador >> */
istream& operator>> (istream& is,Traductor &traductor){
    Palabra p;
	int i = 0; 
	vector <Palabra> palabras;
	palabras.push_back(p);

	// Inicializamos las letras de la A hasta la Z
	traductor.Inicializar();

	//Leemos los datos
	while(is >> palabras.at(i)){
		palabras.push_back(p);		
		// Insertamos según la primera letra de la palabra en el idioma origen,
		// 	ordenado por orden alfabético diccionarioLetras.letra
		traductor.IncluirEnDiccionario(palabras.at(i));		
		i++;
	}

    return is;
}



/* Pasar a mayuscula */
string Traductor::CambiarMayuscula(const string palabra){
	string cambiada;
	char mayus;

	cambiada = palabra;

	if(palabra.at(0) != '.'){
		mayus = toupper(cambiada.at(0));
		cambiada.at(0) = mayus;
	}

	return cambiada;
}

/* Función para ordenar el diccionario */
void Traductor::Ordenar(){
	for(int i=0; i<tamAlfabeto; i++)
		diccionarioLetras[i].Ordenar();
}

/* Función para separar el diccionario de la A-Z */
void Traductor::IncluirEnDiccionario(Palabra palabra){

	Palabra aux;
	string cad;

	aux = palabra;
	cad = CambiarMayuscula(aux.GetPalabraOrigen());
	palabra.Asignar(cad,aux.GetPalabraDestino());

	int indice;

	//Hallamos la posición en que se encuentra la primera letra 
	//	de la palabra origen en diccionarioLetras
	if(palabra.GetPalabraOrigen().at(0) != '.'){
	indice = palabra.GetPalabraOrigen().at(0) - 'A'; 
	// Introducimos los elementos de la clase Palabra en dicLetra
	diccionarioLetras[indice].AumentarDicLetra(palabra);
	}else
		diccionarioLetras[tamAlfabeto-2].AumentarDicLetra(palabra);
}

/* Función para localizar una palabra en el diccionario */
int Traductor::Localizar(string palabra_buscada, int indice){
    bool encontrado = false;
    int posicion = -1;
    int tope = diccionarioLetras[indice].GetTamanio();


    for(int i=0; i<tope && !encontrado; i++){
        // Comprobamos si la palabra es alguna palabra del diccionario 
        // 	en el idioma origen
        if(palabra_buscada == diccionarioLetras[indice].GetDicLetra().at(i).GetPalabraOrigen()){
            posicion = i;
            encontrado = true;
        }
    }

    return posicion;
}

/* Función de traducción de una sola palabra */
vector <string> Traductor::GetTraducciones(string palabra_origen){
	string palabra = CambiarMayuscula(palabra_origen);
    vector <string> traduccion;
    string p_traducida;
    int posicion, tope;
	int indice;

	if(palabra.at(0) != '.'){
    	indice = palabra.at(0) - 'A';
	}else
		indice = tamAlfabeto-2;

	// Hallamos la posición en que se encuentra la palabra en diccionarioLetras[indice].dicLetra
    posicion = Localizar(palabra, indice);

    if(posicion >= 0){
		// Hallamos el número de traducciones que tiene la palabra buscada en el idioma origen
		tope = diccionarioLetras[indice].GetDicLetra().at(posicion).GetPalabraDestino().size();
        for(int i=0; i<tope; i++){
			// Introducimos las palabras en el idioma destino en traduccion
			p_traducida = diccionarioLetras[indice].GetDicLetra().at(posicion).GetPalabraDestino().at(i);
            traduccion.push_back(p_traducida);
        }
    }
	else{
		p_traducida = "No se encuentra en el diccionario";
		traduccion.push_back(p_traducida);
	}

    return traduccion;
}

/* Sobrecarga del operador << */
ostream & operator<<(ostream& os, const Traductor &traductor){
	for(int j=0; j<traductor.tamAlfabeto-1; j++)
		os << traductor.diccionarioLetras[j];

    return os;
}