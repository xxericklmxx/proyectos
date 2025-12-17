#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define Nombre_socket "/home/erick/servidor"
#define Buffer 128

#define MAX_CLIENT_SUPPORTED 32
enum OP {
    CREAR,
    ACTUALIZAR,
    BORRAR
};

struct lista_L3
{
    char destination[16];
    char mask;
    char gateway[16];
    char interface[32];
};

struct mensaje{
    enum OP op_cod;
    struct lista_L3 msg_l3;
};

struct nodo{
    struct lista_L3 entrada;
    struct nodo *siguiente;
    };
struct nodo* raiz;
struct nodo_aux{
    struct nodo *anterior;
    struct nodo *sig;
};
struct nodo_aux aux;
void agregar_entrada(struct lista_L3 nuevo){
     struct nodo* tmp = (struct nodo*)malloc(sizeof(struct nodo));
     tmp->entrada=nuevo;
     //memccpy(&tmp,&nuevo,sizeof(nuevo));
     tmp->siguiente=NULL;
     if(raiz==NULL){
        raiz=tmp;
    }else{
        struct nodo* tmp2=raiz;
        while(tmp2->siguiente!=NULL){
            tmp2=tmp2->siguiente;
        }
        tmp2->siguiente=tmp;        
    }

}
struct nodo_aux buscar_lista(char *ipdestino, char mask){

struct nodo* tmp = raiz;
struct nodo* anterior = raiz;

if(tmp==NULL){
        printf("la lista esta vacia\n");
        return aux;
    }
else{
     while(tmp!=NULL){     
         
          if(!strcmp(ipdestino,tmp->entrada.destination) && mask==tmp->entrada.mask)
         { 
             aux.anterior=anterior;
             aux.sig=tmp->siguiente;
             return aux;
            break;
         }else{
           if(anterior!=tmp){
               anterior=anterior->siguiente;
           }
         tmp=tmp->siguiente;
         }
     }
    
}

}

void actualizar(struct lista_L3 nuevo){

   struct nodo_aux aux = buscar_lista(nuevo.destination,nuevo.mask);
    
    if(aux.anterior==NULL){
        printf("no se encontro esa ruta \n");
    }else{
        
        struct nodo* tmp = (struct nodo*)malloc(sizeof(struct nodo));
        tmp->entrada=nuevo;                
        aux.anterior->siguiente=tmp;
        tmp->siguiente=aux.sig;        
    }

}

void eliminar(struct lista_L3 nuevo){
   struct nodo_aux aux = buscar_lista(nuevo.destination,nuevo.mask);
    
    if(aux.anterior==NULL){
        printf("no se encontro esa ruta \n");
    }else{
        if(aux.anterior == raiz && aux.sig ==raiz->siguiente)
        {
            raiz=aux.sig;
        }else{
        aux.anterior->siguiente=aux.sig;
        }
    }
    
}

void imprimir_nodo(){
    struct nodo* tmp=raiz;
     while(tmp!=NULL){
           printf("ip %s , mascara %d, gateway %s , interface %s\n",tmp->entrada.destination,tmp->entrada.mask,tmp->entrada.gateway,tmp->entrada.interface);
           tmp=tmp->siguiente;
        }
}
int monitor_fd_set[MAX_CLIENT_SUPPORTED];
int cliente_resultado[MAX_CLIENT_SUPPORTED];

static void inicializar_fd(){
    
    for(int i=0;i<MAX_CLIENT_SUPPORTED;i++)
    {   
        monitor_fd_set[i]= -1;
        
    }
}
static void agregar_fd(int fd){

  for(int i=0;i<MAX_CLIENT_SUPPORTED;i++)
    {
        if(monitor_fd_set[i]!=-1)
            continue;
        monitor_fd_set[i]=fd;
        break;
    }
}

static void remover_fd(int fd){
      for(int i=0;i<MAX_CLIENT_SUPPORTED;i++)
    {
        if(monitor_fd_set[i]!=fd)
            continue;
        monitor_fd_set[i]= -1;
        break;
    }
}

static void refresh_fd(fd_set *fd_set_ptr){

    FD_ZERO(fd_set_ptr);
      for(int i=0;i<MAX_CLIENT_SUPPORTED;i++)
    {
            if(monitor_fd_set[i]!=-1)
            FD_SET(monitor_fd_set[i],fd_set_ptr);   
    }


}

static int get_max_fd(){
    int i =0;
    int max=-1;
    for(;i<MAX_CLIENT_SUPPORTED;i++){
        if(monitor_fd_set[i]>max)
        {
            max=monitor_fd_set[i];
        }
    }

    return max;

}

int
main(int argc, char *argv[]){
fd_set readfds;
struct sockaddr_un nombre; 
char buffer[Buffer];
int cliente_socket;
int ret,i;
cliente_socket=socket(AF_UNIX,SOCK_STREAM,0);
struct mensaje msj;
if(cliente_socket ==-1)
{
    perror("socket");
    exit(EXIT_FAILURE);
    
}
memset(&nombre,0,sizeof(struct sockaddr_un));
nombre.sun_family= AF_UNIX;
strncpy(nombre.sun_path,Nombre_socket,sizeof(nombre.sun_path)-1);

ret=connect(cliente_socket,(const struct sockaddr *)&nombre,sizeof(struct sockaddr_un));
inicializar_fd();
agregar_fd(0);
agregar_fd(cliente_socket);
  i=1;
do{

 refresh_fd(&readfds);
 printf("esperando datos del servidor\n");
select(get_max_fd()+1,&readfds,NULL,NULL,NULL);  
if(FD_ISSET(cliente_socket,&readfds))
{     
ret=recv(cliente_socket,&msj,sizeof(struct mensaje),0);
if(msj.op_cod==CREAR)
agregar_entrada(msj.msg_l3);
if(msj.op_cod==ACTUALIZAR){
    actualizar(msj.msg_l3);
}
if(msj.op_cod==BORRAR){
    eliminar(msj.msg_l3);
}



}
if(FD_ISSET(0,&readfds))
{
    printf("1.-imprimir nodo\n");
    printf("0.-Salir\n");
    scanf("%d",&i);

imprimir_nodo();
}

}while(i);
memset(buffer,0,Buffer);
ret =read(cliente_socket,buffer,Buffer);
 if(ret==-1){
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("respuesta del servidor : %s\n",buffer);
    close(cliente_socket);
    exit(EXIT_FAILURE);
}