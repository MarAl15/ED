#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
  * @brief Obtener el traductor que surge del idioma de origen del primer traductor
  *  al idioma destino del segundo traductor.
  * @param t_origen: Traductor del cual se coge el idioma de origen y el idioma destino
  *  es común al idioma origen de otro_t_origen.
  * @param otro_t_origen: Traductor del cual se coge el idioma de destino y el idioma origen
  *  es común al idioma destino de t_origen.
  * @param t_destino: Traductor resultado de la concatenación.
  */
void GetTraductorConcatenado(const Traductor & t_origen,const Traductor & otro_t_origen, Traductor & t_destino){
	Traductor::const_iterator it;
	string palabra;
	vector <string> trads;
	int tope;

	for (it=t_origen.begin(); it!=t_origen.end();++it){
		palabra = (*it).second.GetPalabra();
   		trads = otro_t_origen.GetTraducciones(palabra);
		tope = trads.size();

		for(int i=0; i<tope; i++){
			t_destino.insert((*it).first, trads.at(i));
		}
	}
}

/**
  * @brief Escritura del diccionario.
  * @param T: Diccionario que se escribe.
  * @param os: Flujo de salida. Es modificado.
  */
void ImprimeTraductor(const Traductor &T,ostream &os){
	Traductor::const_iterator it;
	Palabra palabra;
	vector <string> trads;
	int tope;

	for(it = T.begin(); it != T.end(); ++it){
		palabra = (*it).first;
		os << palabra << ";";

		trads = T.GetTraducciones(palabra.GetPalabra());
		tope = trads.size();

		for(int i=0; i<tope; i++, ++it)
			os << trads.at(i) << ";";

		--it;

		os << endl;
	} 
}


int main(int argc, char * argv[]){

	if (argc!=4){
		cout<<".-Dime el nombre del fichero con el primer traductor a concatenar"<<endl;
		cout<<".-Dime el nombre del fichero con el segundo traductor a concatenar"<<endl;
		cout<<".-El nombre de fichero del traductor destino"<<endl;
		return 0;
	}

	ifstream f (argv[1]);
	ifstream g(argv[2]);

	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}
	if (!g){
		cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
		return 0;
	}
   
	Traductor primer_t_ori, segundo_t_ori;
	f>>primer_t_ori; //Cargamos en memoria, en el traductor.
	g>>segundo_t_ori;
	Traductor t_des;
	GetTraductorConcatenado(primer_t_ori, segundo_t_ori, t_des);

   
	ofstream fout(argv[3]);
	if (!fout){
		cout<<"No puedo crear el fichero "<<argv[3]<<endl;
		return 0;
	}
	ImprimeTraductor(t_des,fout);
      
}
