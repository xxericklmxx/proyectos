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
    // printf("ip %s , mascara %d, gateway %s , interface %s\n",tmp->entrada.destination,tmp->entrada.mask,tmp->entrada.gateway,tmp->entrada.interface);
     
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

static void enviardatos(struct mensaje msj){

    for(int i=2;i<MAX_CLIENT_SUPPORTED;i++){

        if(monitor_fd_set[i]!=-1){
            send(monitor_fd_set[i],&msj,sizeof(struct mensaje),0);
        }

    }

}
void enviar_tablal3_completa(int socket){

    struct nodo* tmp = raiz;
    struct mensaje msj;
    msj.op_cod=CREAR;
    if(tmp==NULL){
        printf("la lista esta vacia\n");
    }else{
    while(tmp!=NULL){
        msj.msg_l3=tmp->entrada;
         msj.op_cod=CREAR;
        send(socket,&msj,sizeof(struct mensaje),0);
        memset(&msj,0,sizeof(struct mensaje));
        tmp=tmp->siguiente;
    }
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

int
main(int argc, char *argv[]){

struct sockaddr_un nombre; 


int ret;
int socket_master;
int cliente_socket,con;
int result,op;
int data;
char buffer[Buffer];
int maxfd;
fd_set readfds;


socket_master=socket(AF_UNIX,SOCK_STREAM,0);
if(socket_master ==-1)
{
    perror("socket");
    exit(EXIT_FAILURE);
    
}
printf("master socket creado\n ");

memset(&nombre,0,sizeof(struct sockaddr_un));
//configurando el credenciales para el proceso
nombre.sun_family= AF_UNIX;
strncpy(nombre.sun_path,Nombre_socket,sizeof(nombre.sun_path)-1);

//bind socket con nombre_socket
unlink(Nombre_socket); //por si hay otro proceso con el nombre lo elimina

ret=bind(socket_master,(const struct sockaddr *)&nombre,sizeof(struct sockaddr_un));

if(ret ==-1){
    perror("bind");
    exit(EXIT_FAILURE);
}

printf("bind completado \n");

ret=listen(socket_master,20);

if(ret ==-1){
    perror("listen");
    exit(EXIT_FAILURE);
}
inicializar_fd();
agregar_fd(0);
agregar_fd(socket_master);


for(;;){

     refresh_fd(&readfds);

    ret = select(get_max_fd()+1,&readfds,NULL,NULL,NULL);    
    printf("esperando accept \n");

    if(FD_ISSET(0,&readfds))
    {
        printf("\n ingrese la operacion que desea realizar \n");
        printf("1.- Crear  \n");
        printf("2.-Actualizar \n");
        printf("3.-Eliminar\n");
        scanf("%d",&op);
        struct  lista_L3 l3_nuevo;
        struct mensaje msj_nuevo;
        if(op==1){
            printf("ingrese ip destino\n");
            scanf("%s",&l3_nuevo.destination);
            printf("ingrese mascara\n");
            scanf("%d",&l3_nuevo.mask);
            printf("ingrese ip gateway\n");
            scanf("%s",&l3_nuevo.gateway);
            printf("ingrese interface de salida\n");
            scanf("%s",&l3_nuevo.interface);
            msj_nuevo.op_cod=CREAR;
            msj_nuevo.msg_l3=l3_nuevo;            
            agregar_entrada(l3_nuevo);
            enviardatos(msj_nuevo);            
            imprimir_nodo();
        }
        if(op==2){
            printf("ingrese ip destino\n");
            scanf("%s",&l3_nuevo.destination);
            printf("ingrese mascara\n");
            scanf("%d",&l3_nuevo.mask);
            printf("ingrese ip gateway\n");
            scanf("%s",&l3_nuevo.gateway);
            printf("ingrese interface de salida\n");
            scanf("%s",&l3_nuevo.interface);
            msj_nuevo.op_cod=ACTUALIZAR;
            msj_nuevo.msg_l3=l3_nuevo;
            actualizar(l3_nuevo);
            enviardatos(msj_nuevo); 
              imprimir_nodo();

        }
        if(op==3){
            printf("ingrese ip destino\n");
            scanf("%s",&l3_nuevo.destination);
            printf("ingrese mascara\n");
            scanf("%d",&l3_nuevo.mask);
            msj_nuevo.op_cod=BORRAR;
            msj_nuevo.msg_l3=l3_nuevo;
            eliminar(l3_nuevo);
            enviardatos(msj_nuevo); 
             imprimir_nodo();
        }
    }
    if(FD_ISSET(socket_master,&readfds))
   {
    cliente_socket=accept(socket_master,NULL,NULL);
    agregar_fd(cliente_socket);
    

    if(cliente_socket ==-1){
    perror("accept");
    exit(EXIT_FAILURE);
    }
    printf("conexion aceptada \n");
    printf("enviando tabla l3");
    enviar_tablal3_completa(cliente_socket);

   }    
    else{
    
      

    for(int i=0;i<MAX_CLIENT_SUPPORTED;i++){
        if(FD_ISSET(monitor_fd_set[i],&readfds))
        {  int done;
           int comm_socket_fd = monitored_fd_set[i];
                    
           ret = read(comm_socket_fd, &done, sizeof(int));
            if (done == 1) { 
               close(comm_socket_fd);
               remove_from_monitored_fd_set(comm_socket_fd);
                    }

    }
    } 
    }    
    }
    
    
  


    close(socket_master);
    printf("conexion cerrada.. \n");
    unlink(Nombre_socket);
    exit(EXIT_SUCCESS);









}

