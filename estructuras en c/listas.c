#include <stdio.h>
#include <stdlib.h>

struct  nodo
{   
    int dato;
    struct nodo *siguiente;
    
};

struct nodo* inicio;
void insertar_nodo_final(int x){

   struct nodo* temporal = ( struct nodo*) malloc(sizeof(struct nodo));
    if(inicio!=NULL)
    {  struct nodo* tmp;
        tmp=inicio;      
        while(tmp->siguiente!=NULL){
            tmp=tmp->siguiente;
        }
        tmp->siguiente=temporal;
        temporal->dato=x;
        temporal->siguiente=NULL;
    }else{
        temporal->siguiente=NULL;
        inicio=temporal;
        temporal->dato=x;
    }


}

void insertar_nodo_inicio(int x){

      struct nodo* temporal = ( struct nodo*) malloc(sizeof(struct nodo));
      if(inicio!=NULL)
      {temporal->siguiente =inicio;
      inicio=temporal;
      temporal->dato=x;
      }else{
          inicio=temporal;
          temporal->siguiente=NULL;
          temporal->dato=x;
      }

}
int calcular_cantidad_nodo(){
      struct nodo* tmp =inicio;
         int i=1;
while(tmp->siguiente!=NULL){
        tmp=tmp->siguiente;
        i++;
    }

    return i;
}

void insertar_nodo_posicion(int x, int pos)
{
    if(pos<=calcular_cantidad_nodo() && pos >0)
    {
    struct nodo* temporal=  ( struct nodo*) malloc(sizeof(struct nodo));
   struct nodo* tmp=inicio;
    struct nodo* tmp2;
   for (int i = 1; i < (pos-1); i++)
   {
       tmp=tmp->siguiente;
   }
    tmp2=tmp->siguiente;
    tmp->siguiente=temporal;
    temporal->siguiente=tmp2;
    temporal->dato=x;

    }else{
        printf("ingrese un tamano entre 1 y %d \n",calcular_cantidad_nodo());
    }
   

    
 
 

}

void imprimir(){

    struct nodo *temporal;
    temporal=inicio;
     while(temporal!=NULL){
            
            printf(" - %d -  ",temporal->dato);
            temporal=temporal->siguiente;
        }
    printf("\n");

}

void borrar_nodo_posicion(int pos){

struct nodo* tmp=inicio;
if(pos==1)
{
    inicio=tmp->siguiente;
    free(tmp);
    return;
}


for (int i = 1; i < (pos-1); i++)
{
    tmp=tmp->siguiente;
}
struct nodo* tmp2=tmp->siguiente;

tmp->siguiente=tmp2->siguiente;
free(tmp2);

}



int main(){

    int x,i,tam,dato;
    inicio=NULL;
    printf("ingrese la cantidad de datos a insertar : \n");
    scanf("%d",&tam);
    for ( i = 0; i <tam ; i++)
    {       
    printf("ingrese el dato %d : ",i);
    scanf("%d",&dato);
        insertar_nodo_inicio(dato);
        imprimir();
    }
      printf(" \n ingrese la posicion  : \n");
    scanf("%d",&tam);
    insertar_nodo_posicion(10,tam);
    printf(" \n\n");
    imprimir();
    printf(" \n ingrese la posicion  : \n");
    scanf("%d",&tam);
    borrar_nodo_posicion(tam);
    imprimir();
   

}