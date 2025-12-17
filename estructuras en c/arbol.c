#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
struct  nodo
{
    int data;
    struct nodo *izquierda; 
    struct nodo *derecha; 
    
};
struct nodo*   crear_nodo(int data){

    struct nodo* nuevo_nodo=(struct nodo* )(malloc(sizeof(struct  nodo)));
    nuevo_nodo->data=data;
    nuevo_nodo->derecha=NULL;
    nuevo_nodo->izquierda=NULL;
    return nuevo_nodo;
}

struct nodo* insertar(struct nodo *root,int data)
{
     
 if(root==NULL){
    struct nodo* tmp=crear_nodo(data);
     (root)=tmp;

 }
 else if(data<= root->data){
  root->izquierda=insertar(root->izquierda,data);

 }   
    else {
  root->derecha=insertar(root->derecha,data);

 }   
 return root;
      

}

struct nodo  *imprimir_nodos(struct nodo* root){
  struct nodo *tmp=root;
   struct nodo *tmp_izquierda=root->izquierda;
    struct nodo *tmp_derecha=root->derecha;
    if(root == NULL)
    {
        printf("fin del arbol");
    }
    if(tmp->izquierda !=NULL)
    {      
        printf(" %d ",tmp_izquierda->data);        
        printf(" %d ",tmp_derecha->data);      
      return imprimir_nodos(tmp->izquierda);
       
    }
    else if(tmp->derecha !=NULL){
        printf(" %d ",tmp_izquierda->data);        
        printf(" %d ",tmp_derecha->data);      
        return imprimir_nodos(tmp->derecha);
          printf("\n \n");
    }  
    else{
            printf("fin del arbol");
    }
  return root;
   

}
bool buscar(struct nodo *root,int data){
  if(root==NULL)return false;
  else if((root->data) == data) return true;
  else if(data<=root->data) return buscar(root->izquierda,data);
  else return buscar(root->derecha,data);

}



int main(){
   
   struct nodo *root=NULL;
    
   root=insertar(root,20);  
   root=insertar(root,9);   
   root=insertar(root,25);     
   root=insertar(root,11); 
   root=insertar(root,7); 
    root=insertar(root,30); 
   root=insertar(root,19);  
     root=insertar(root,5); 
   root=insertar(root,8);  
     root=insertar(root,10); 
   root=insertar(root,12);  
     int numero ;
     printf("ingrese el numero a buscar");
     scanf("%d",&numero);
     if(buscar(root,numero)){
         printf("se encontro el numero");
     }
     else
     printf("no existe el numero en el arbol");

     root=imprimir_nodos(root);

}