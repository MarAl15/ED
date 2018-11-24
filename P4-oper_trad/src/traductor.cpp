#include <string>
#include <map>
#include <vector>
#include <iostream>

#include "palabra.h"
#include "traductor.h"

/* Constructor por defecto */
Traductor::Traductor(){
}

/* Constructor por parámetros */
Traductor::Traductor(multimap <Palabra,Palabra> palabras){

	diccionario.insert(palabras.begin(), palabras.end());
}

/* Constructor de copia */
Traductor::Traductor(const Traductor &t){
	
	diccionario.insert(t.diccionario.begin(), t.diccionario.end());
}

/* Traducciones de una palabra */
vector<string> Traductor::GetTraducciones(const string & palabra) const{
	vector <string> traducciones;

	multimap<Palabra,Palabra>::const_iterator it, itlow = diccionario.lower_bound(palabra);//el primero que tiene dicha palabra
	multimap<Palabra,Palabra>::const_iterator itupper = diccionario.upper_bound(palabra);//el primero que ya no tiene dicha palabra

	// Se comprueba si se encuentra en el diccionario
	if (itlow != diccionario.end()){ 
		for (it=itlow; it!=itupper; ++it)
			traducciones.push_back(it->second.GetPalabra());
	}
	else{
		string ninguna = " No se encuentra en el diccionario";
		traducciones.push_back(ninguna);
	}

	return traducciones;	
}

/* Inserción de una palabra en el idioma origen y su traducción en el idioma destino */
pair<multimap<Palabra,Palabra>::iterator,bool> Traductor::insert(Palabra origen, Palabra destino){
	pair <Palabra,Palabra> p (origen,destino);
	pair <multimap<Palabra,Palabra> ::iterator,bool> ret;
	bool insertado = false;

	multimap<Palabra,Palabra>::iterator it, itlow = diccionario.lower_bound(origen);//el primero que tiene dicha palabra
	multimap<Palabra,Palabra>::iterator itupper = diccionario.upper_bound(origen);//el primero que ya no tiene dicha palabra
	
	// Se comprueba si las palabras ya fueron insertadas para que no haya repeticiones	
	for(it = itlow; it != itupper; ++it){
		if((*it).second == destino)
			insertado = true;
	}
	
	// Si no se encuentra en el diccionario se insertan
	if(!insertado)		
		ret.first = diccionario.insert(p);
	ret.second = true;

	return ret;     
					
}

/* Inserción de una pareja de Palabras */
pair<multimap<Palabra,Palabra>::iterator,bool> Traductor::insert(pair<Palabra,Palabra> p){
	pair<multimap<Palabra,Palabra> ::iterator,bool> ret;

	bool insertado = false;

	multimap<Palabra,Palabra>::iterator it, itlow = diccionario.lower_bound(p.first);//el primero que tiene dicha palabra
	multimap<Palabra,Palabra>::iterator itupper = diccionario.upper_bound(p.first);//el primero que ya no tiene dicha palabra

	// Se comprueba si las Palabras ya fueron insertadas
	for(it = itlow; it != itupper; ++it){
		if((*it).second == p.second)
			insertado = true;
	}
	
	// Si no se encuentran en el diccionario se insertan
	if(!insertado)	
		ret.first = diccionario.insert(p);
	ret.second = true;

	return ret;     
					
}

/* Función de borrado de una palabra y todas sus traducciones*/
void Traductor::borrar(const string &origen){
	multimap<Palabra,Palabra>::iterator itlow = diccionario.lower_bound(origen);//el primero que tiene dicha palabra
	multimap<Palabra,Palabra>::iterator itupper = diccionario.upper_bound(origen);//el primero que ya no tiene dicha palabra
	
	//Se borra todas aquellas que tiene dicha palabra en el idioma origen	
	diccionario.erase(itlow,itupper);

}

/* Función para borrar una palabra con una de sus traducciones */
void Traductor::borrar(const Palabra &origen,const Palabra &destino){
	multimap<Palabra,Palabra>::iterator itlow = diccionario.lower_bound(origen);//el primero que tiene dicho nombre
	multimap<Palabra,Palabra>::iterator itupper = diccionario.upper_bound(origen);//el primero que ya no tiene dicho nombre
	multimap<Palabra,Palabra>::iterator it;

	bool salir =false;

	// Se borra solo aquella que la traducción sea destino
	for (it=itlow; it!=itupper && !salir;++it){
		if (it->second==destino){
			diccionario.erase(it);
			salir =true;
		}		
	}	
}	

/* Operador de asignación */
Traductor Traductor::operator=(const Traductor & d){
	//Se evita la autoasignación
    if(&d != this){
        diccionario = d.diccionario;
    }

    //Se devuelve este objeto
    return *this;
}

/* Función que muestra las palabras y sus traducciones previas a la pasada como argumento */
Traductor Traductor::previos(const Palabra &origen,const Palabra &destino){
	multimap<Palabra,Palabra>::value_compare vc=diccionario.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
	Traductor aux;
	pair<Palabra,Palabra>p(origen,destino);
	multimap<Palabra, Palabra>::iterator it=diccionario.begin();

	while (vc(*it,p)){
		aux.insert(*it++);
	}

	return aux;
}	

/* Lectura del diccionario */
istream & operator>>(istream & is, Traductor & d){
	pair <Palabra,Palabra> p;
	Traductor aux;
	Palabra pal;

	int posicion_primera;
    string lectura;
	string lugar;

    while(getline(is, lectura)){   // Lee una linea
		/* Leemos la palabra en el idioma origen*/
			//Buscamos el primer ";"
		posicion_primera = lectura.find(';');
			//Escribimos la palabra que se encuentra antes del ";" en p.first.palabra
		p.first.insert(lectura.substr(0,posicion_primera));
		
		/* Leemos la/s palabra/s en el idioma destino */ 
		int tope = lectura.size();
		for(int i=posicion_primera+1; i<tope; i++){	
			if(lectura.at(i) != ';'){
				lugar.push_back(lectura.at(i));
			}else{
				p.second.insert(lugar);
				aux.insert(p);
				lugar.clear();
			}
		}
	}

	d=aux;

	return is;
}



