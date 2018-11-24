#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con las traducciones"<<endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
   }
   
   Traductor T;
   f>>T; //Cargamos en memoria, en el traductor.
   
   string a;
   cout<<"Dime una palabra en el idioma origen:";
   getline(cin,a);

   cout << endl;   
   cout << T.GetTraducciones(a).size() << endl;

   vector<string> trads=T.GetTraducciones(a);
   
   /* Escribimos*/
   cout<<a<<"-->";
   for (int i=0;i<trads.size(); ++i)
     cout<<trads[i]<<';';
   cout<<endl;

	char respuesta;

	while(respuesta != 'S' && respuesta !='N'){
		cout << "\n¿Quiere que se le muestre las palabras que contiene el diccionario?[S/N]";
		cin >> respuesta;

		if(respuesta == 'S'){
			T.Ordenar();
			cout << T;
		}else if(respuesta != 'N')
			cout << "\nIntroduzca S, si quiere verlo y N, en caso contrario";
	}

}