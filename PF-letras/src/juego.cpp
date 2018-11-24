#include <iostream> 
#include <string>
#include <cstring>
#include <fstream>
#include "Diccionario.h"
#include "Conjunto_Letras.h"
#include "Bolsa_Letras.h"
using namespace std;

bool comprueba(string palabra, vector<char>letras){
	bool bien;
	for (unsigned int i = 0 ; i < palabra.size(); i++){ //Todo
		bien = false;
		for(unsigned int j = 0 ; j< letras.size(); j++){  //letras
			if(palabra.at(i) == letras.at(j))
				bien = true;
		}
		if(!bien)
			return false;

	}
	return true;
} 

vector<string> getSoluciones(int n, Diccionario &D,vector<char>letras){
    vector<string> aux, soluciones;
    for (int i = 1; i < n ; i++)
        aux = D.PalabrasLongitud(i);


    for (unsigned int i = 0 ; i < aux.size() ;i++)
        soluciones.push_back(aux.at(i));


    for(unsigned int i = 0 ; i < soluciones.size() ;i++){
        if( !comprueba(soluciones.at(i),letras))
            soluciones.erase(soluciones.begin()+i);
    }
    return soluciones;
}



vector<char> letrasJuego(int n , vector<char> consonantes, vector<char> vocales){
    vector<char> letras;
	char l;
    for(int i = 0 ; i < n ; i++){
        cout << "\n¿Quieres consonante(C) o vocal(V)?\n" ;
        cin >> l;
        
        if(l == 'C'){
            letras.push_back(consonantes.at(0));
            consonantes.erase(consonantes.begin());
            cout << letras.at(letras.size()-1);
		}
		else{
			letras.push_back(vocales.at(0));
			vocales.erase(vocales.begin());
			cout << letras.at(letras.size()-1);
		}	
    }
    return letras;
}


int main(int argc, char *argv[]){
	if(argc < 4){
		cout << "\nLos parametros son:\n";
		cout << "1: fichero con diccionario "<< endl;
		cout<< "2: fichero con letras " << endl;
		cout << "3: L o P" << endl;
		return(0);
	}

	string param;

	if(!strcmp(argv[3],"L") || !strcmp(argv[3],"P")){
		param = argv[3];
	}
	else{
		cout << "\nIntroduzca la modalidad adecuadamente.\n";
		return(0);
	}

	ifstream f(argv[1]);
	Diccionario D;
	f >> D;
    
	Conjunto_Letras C;
	ifstream g(argv[2]);
	g >> C;
    
	Bolsa_Letras B;
	B.vocalAleatoria(C);
	B.consonanteAleatoria(C);

	vector<char>vocales = B.getVocales();
    vector<char>consonantes = B.getConsonantes();


	int n;

	cout << "\nIntroduzca el numero de letras con las que quiere jugar.\n";
	cin >> n;	
	vector<char>letras;

    letras = letrasJuego(n, consonantes,vocales);
    
    cout << "\nJugaremos con las siguientes letras: \n";
    for(unsigned int i = 0 ; i < letras.size() ; i++)
        cout << letras.at(i)<< " ";
    cout << endl;

	vector<string> soluciones;
	
    
    soluciones = getSoluciones(n,D,letras);
   
    string sol;
    cout << "\nDe su solucion\n";
    cin >> sol;
	
    if(D.Esta(sol)){
        if(param == "L"){
            if(sol.size() == soluciones.at(soluciones.size()-1).size())
                cout << "\nFelicidades!!!\n";
            
            else
                cout << "\nEs mejor la nuestra, lo siento... \n" << soluciones.at(soluciones.size()-1);
        }
        else{
            string mejor = soluciones.at(0);
    		int puntuacion = C.getPuntuacion(mejor);

   			 for(unsigned int i = 1; i < soluciones.size(); i++){
    		    if(C.getPuntuacion(soluciones.at(i)) > puntuacion){
        		    mejor = soluciones.at(i);
            		puntuacion = C.getPuntuacion(mejor);
        		}
    		}
            
            if(C.getPuntuacion(sol) >= puntuacion)
                cout << "\nFelicidades!!!\n";
            else
                cout <<"\nEs mejor la nuestra, lo siento... \n" << mejor;
        }
    }
    else
        cout << "\nTramposo! Esa palabra no está en el diccionario!\n";
}
