#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
  * @brief Obtención del traducto inverso de t_origen.
  * @param t_origen: traductor el cual se quiere obtener su traductor inverso.
  * @param t_destino: traductor el cual se utilizará para guarda el inverso de t_origen.
  */
void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino){
	Traductor::const_iterator it;

	for (it=t_origen.begin(); it!=t_origen.end();++it)
		t_destino.insert((*it).second, (*it).first);

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

	if (argc!=2 && argc!=3){
		cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
		cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
		return 0;
	}

	ifstream f (argv[1]);
	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}
   
	Traductor t_ori;
	f>>t_ori; //Cargamos en memoria, en el traductor.
	Traductor t_des;
	GetTraductorInverso(t_ori,t_des);
   
	if (argc==2)
		ImprimeTraductor(t_des,cout);
	else{
		ofstream fout(argv[2]);
		if (!fout){
			cout<<"No puedo crear el fichero "<<argv[2]<<endl;
			return 0;
		}
	 	ImprimeTraductor(t_des,fout);
	}
}
