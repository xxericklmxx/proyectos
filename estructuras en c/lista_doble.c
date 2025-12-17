#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int dato;
  struct nodo* siguiente;
  struct nodo* anterior;
}nodo_t;

struct nodo*  crear_nodo(int dato){
    struct nodo* nodo =(struct nodo*)(malloc(sizeof(struct nodo)));
    nodo->dato=dato;
    nodo->anterior=NULL;
    nodo->siguiente=NULL;
    return nodo;

}
struct nodo* inicio;
void insertar(struct nodo* nodo ){


if(inicio==NULL){
inicio=nodo;
}else{
struct nodo* tmp=inicio;


}



}


int main(){
inicio=NULL;
}

