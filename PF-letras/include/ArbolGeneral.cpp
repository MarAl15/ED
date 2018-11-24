#include <cassert>
#include <iostream>
#include "ArbolGeneral.h"
using namespace std;

/*_________________________________________________________________________________________________*/
// FUNCIONES PRIVADAS
/*_________________________________________________________________________________________________*/


/*_________________________________________________________________________________________________*/ 

/* Operador de comparación (igualdad) */
template <class Tbase>
bool ArbolGeneral<Tbase>::nodo::operator == (const nodo &n){
	bool iguales = false;
           
	if((n.padre == padre) && (izqda == n.izqda) && (drcha == n.drcha) && (etiqueta == n.etiqueta)){
		iguales = true;
	}

	return iguales;
}

/*_________________________________________________________________________________________________*/  

/* Destruir el subárbol */
template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo * n){
	if(n!=0){
		ArbolGeneral::iter_preorden i;
		
		for(i.it=n->izqda; i.it!=n->drcha; ++i)
			destruir(i.it);
		
		delete n;
	}
}
 
/*_________________________________________________________________________________________________*/
   
/* Copiar un subárbol */
template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
	if(orig == 0)
		dest = 0;
	else{
		ArbolGeneral<Tbase>::iter_preorden i, end;
	
		for(i.it = orig; i.it!=orig->drcha; ++i){
			dest = new nodo;

			dest->etiqueta = *i;
			dest->izqda = i.it->izqda;

			if(i.it != orig)
				dest->drcha = i.it->drcha;
			else
				dest->drcha = 0;

			if(dest->izqda != 0)
				dest->izqda->padre = dest;
			if(dest->drcha != 0 )
				dest->drcha->padre = dest;
		}
               
	}
}
 
/*_________________________________________________________________________________________________*/
    
/* Contar el número de nodos */
template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
	int contador = 0;
        
	ArbolGeneral<Tbase>::const_iter_preorden i;
     
	for(i.it =n; i.it != n->drcha; ++i){
		contador++;
	}

	return contador;
  //return 1+contar(n->drcha)+contar(n->izqda);
}
    
/*_________________________________________________________________________________________________*/

    /* Comprobar la igualdad de dos subárboles */
template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
	//bool distintos = false;
	//ArbolGeneral<Tbase>::iter_preorden i,j;

  if(n1 == 0 && n2 == 0)
    return true;

  if(contar(n1) == contar(n2)){
    if(n1->etiqueta == n2->etiqueta){
      return (soniguales(n1->izqda, n2->izqda) && soniguales(n1->drcha, n2->drcha));
    }
    else
      return false;
  }
  else
    return false;

  /*i.it = n1;
	j.it = n2;

	if (contar(*n1) == contar(*n2)){
		distintos = false;
            
		while (i.it != 0 && !distintos){
			if (!(i.it == j.it)){
				distintos = true;
			}
			i++;
			j++;
		}
	}
	else
		distintos = true;*/
   
	//return !distintos;
}
   
/*_________________________________________________________________________________________________*/
 
/* Escribir un subárbol */
template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
  
	if(nod == 0)
		out << "x ";
	else{
		out << "n " << nod->etiqueta << " ";
		escribe_arbol(out, nod->izqda);
		escribe_arbol(out, nod->drcha);
	}
}
/*_________________________________________________________________________________________________*/
    
/* Leer un subárbol */
template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod){
	char c;
	in >> c;

	if(c == 'n'){
		nod = new nodo;
		in >> nod->etiqueta;
		lee_arbol(in, nod->izqda);
		lee_arbol(in, nod->drcha);

		if(nod->izqda != 0)
			nod->izqda->padre = nod;
		if(nod->drcha != 0)
			nod->drcha->padre = nod;
	}
	else
		nod = 0;
}
			 

/*_________________________________________________________________________________________________*/
// FUNCIONES PÚBLICAS
/*_________________________________________________________________________________________________*/


/*_________________________________________________________________________________________________*/
    
/*  Constructor de raíz */
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
	laraiz = new nodo;

    laraiz->etiqueta = e;
    laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
}

/*_________________________________________________________________________________________________*/
    
/* Constructor de copias */
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){
	copiar(laraiz, v.laraiz);
	
	if(laraiz != 0)
		laraiz->padre = 0;
    
}

/*_________________________________________________________________________________________________*/
    
/* Operador de asignación */
template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){
	if(this != &v){
		destruir(laraiz);
		
		copiar(laraiz, v.laraiz);
	
		if(laraiz != 0)
			laraiz->padre = 0;
	}

	return *this;
    
}

/*_________________________________________________________________________________________________*/
    
/* Asignar nodo raíz */
template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){

	destruir(laraiz);
	laraiz = new nodo;
	laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
	laraiz->etiqueta = e;
}

/*_________________________________________________________________________________________________*/
    
/* Copiar subárbol */
template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
	destruir(laraiz);

	copiar(laraiz, nod);

	if(laraiz != 0)
		laraiz->padre = 0;
}

/*_________________________________________________________________________________________________*/
    
/* Podar subárbol hijo más a la izquierda */
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n != 0);

	/*if(n->izqda != 0){
		copiar(n->izqda, dest.laraiz)
		//n->izqda = dest.raiz()->drcha;
		n->izqda = dest.laraiz->drcha;
		//dest.raiz()->padre = dest.raiz()->drcha = 0;
		dest.laraiz->padre = dest.laraiz->drcha = 0;
	}*/

	destruir(dest.laraiz);
	dest.laraiz = n->izqda;

	if(dest.laraiz != 0){
		n->izqda = dest.laraiz->drcha;
		dest.laraiz->padre = dest.laraiz->drcha = 0;
	}
}

/*_________________________________________________________________________________________________*/
    
/* Podar subárbol hermano derecha */
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){		
	assert(n != 0);

	/*if(n->drcha != 0){
		copiar(n->drcha, dest.laraiz);
		n->drcha = dest.laraiz->drcha;
		dest.laraiz->padre = dest.laraiz->drcha = 0;
	}*/

	destruir(dest.laraiz);
	dest.laraiz = n->drcha;

	if(dest.laraiz != 0){
		n->drcha = dest.laraiz->drcha;
		dest.laraiz->padre = dest.laraiz->drcha = 0;
	}
}

/*_________________________________________________________________________________________________*/
    
/* Insertar subárbol hijo más a la izquierda */
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n != 0);

	/*if(rama != 0){
		rama.laraiz->drcha = n->izq;
		rama.laraiz->padre = n;
		n->izq = rama.laraiz;
		rama.laraiz = 0;
	}*/

	rama.laraiz->drcha = n->izqda;
	//destruir(n->izqda);
	n->izqda = rama.laraiz;
	
	if(n->izqda != 0){
		n->izqda->padre = n;
		rama.laraiz = 0;
	} 
}
			
/*_________________________________________________________________________________________________*/

/* Insertar subárbol hermano derecha */
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n != 0);

  //ArbolGeneral<Tbase> nulo;
	//if(rama != nulo){
	/*	rama.laraiz->drcha = n->drcha;
		rama.laraiz->padre = n->padre;
		n->drcha = rama.laraiz;
		rama.laraiz = 0;
	}*/

	rama.laraiz->drcha = n->drcha;
	//destruir(n->drcha);
	n->drcha = rama.laraiz;
	
	
	if(n->drcha != 0){
		//n->drcha = rama.laraiz;
		n->drcha->padre = n->padre;
		rama.laraiz = 0;
	}
}

/*_________________________________________________________________________________________________*/
//  Iterador del ArbolGeneral en preorden
/*_________________________________________________________________________________________________*/ 

/*_________________________________________________________________________________________________*/
	   
	 /* Iterador al siguiente nodo segun el recorrido en preorden */
template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden & ArbolGeneral<Tbase>::iter_preorden::operator ++(){
  assert(it != 0);

  if(it->izqda != 0){
    it = it->izqda;
    level++;
  }else if(it->drcha != 0)
    it = it->drcha;
  else{
    bool subir = true;
    Nodo padre;

    while(subir){
      padre = it->padre;
      if(padre == 0){ // La raíz
        it = 0; // final
        subir = false;
        //level = 0;
        level = -1;
      }
      else if(padre->drcha != 0){
        subir = false;
        it = padre->drcha;
        level--;
      }
      else{  // Seguir iterando
        it = padre;
        level--;
      }
    }
  }

	return *this;
}
	   
/*_________________________________________________________________________________________________*/
 
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el  que se compara
	  * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
	  * */
/*template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator == (const iter_preorden &i){
  bool iguales = false;
  if( (i.it == it) && (i.raiz == raiz) && (level == i.level)){
    iguales = true;
  }

  return iguales;
}*/	 	  

/*_________________________________________________________________________________________________*/
 
	 /* Comparar dos iteradores */
/*template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator != (const iter_preorden &i){
  //return !(i == *this);
  bool distintos = true;
  if( (i.it == it) && (i.raiz == raiz) && (level == i.level)){
    distintos = false;
  }

  return distintos;
}*/


/*_________________________________________________________________________________________________*/
//  Iterador constante del ArbolGeneral en preorden
/*_________________________________________________________________________________________________*/

	   
	 /* Iterador al siguiente nodo segun el recorrido en preorden */
template <class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden & ArbolGeneral<Tbase>::const_iter_preorden::operator ++(){
  assert(it != 0);

  if(it->izqda != 0){
    it = it->izqda;
    level++;
  }else if(it->drcha != 0)
    it = it->drcha;
  else{
    bool subir = true;
    Nodo padre;

    while(subir){
      padre = it->padre;
      if(padre == 0){ // La raíz
        it = 0; // final
        subir = false;
        level = -1;
        //level = 0;
      }
      else if(padre->drcha != 0){
        subir = false;
        it = padre->drcha;
        level--;
      }
      else{  // Seguir iterando
        it = padre;
        level--;
      }
    }
  }

  return *this;
}

/*_________________________________________________________________________________________________*/
	    
	 /* Comparar dos iteradores */
/*template <class Tbase>
bool ArbolGeneral<Tbase>::const_iter_preorden::operator == (const const_iter_preorden &i){
  bool iguales = false;
  if( (i.it == it) && (i.raiz == raiz) && (level == i.level)){
    iguales = true;
  }

  return iguales;
}*/

/*_________________________________________________________________________________________________*/
	 	    
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el con que se comparación
	  * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
	  * */
/*template <class Tbase>
bool ArbolGeneral<Tbase>::const_iter_preorden::operator != (const const_iter_preorden &i){
  //return !(i == *this);
  bool distintos = true;
  if( (i.it == it) && (i.raiz == raiz) && (level == i.level)){
    distintos = false;
  }

  return distintos;
}*/