#include <iostream>

#include "Cola_max.h"

using namespace std;

int main(){

 Cola_max p;
  int i;

  for ( i=10; i>=0 ; i--)
    p.poner(i);
  

  while (!p.vacia() ){
    elemento x = p.frente();
    cout << x << endl;
    p.quitar();
  }    
  
  return 0;
}