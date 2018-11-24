#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios

using namespace std;

void productoMatricial(int **solucion, int **a, int **b, int dimension){
    
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            solucion[i][j] = 0;
            for(int k=0; k<dimension; k++){ 
                solucion[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
//  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño de las filas y las columnas
  if (tam<=0)
    sintaxis();
  
  // Generación de matrices cuadradas aleatorias
  int **v, **w, **sol; 
  v = new int*[tam];
  for(int i=0; i<tam; i++)
    v[i] = new int[tam];

  w = new int*[tam];
  for(int i=0; i<tam; i++)
    w[i] = new int[tam];

  sol = new int*[tam];
  for(int i=0; i<tam; i++)
    sol[i] = new int[tam];
  
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++){ 
    for(int j=0; j<tam; j++){
        v[i][j] = rand();
        w[i][j] = rand();
    }
  }    
  
  clock_t tini;    // Anotamos el tiempo de inicio
  tini=clock();
  

  productoMatricial(sol,v,w,tam);
  
  clock_t tfin;    // Anotamos el tiempo de finalización
  tfin=clock();

  // Mostramos resultados
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

  for(int i=0; i<tam; i++){
    delete [] v[i];
    delete [] w[i];
    delete [] sol[i];
  }

    delete [] v;
    delete [] w;
    delete [] sol;
}