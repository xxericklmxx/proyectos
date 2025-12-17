#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#pragma comment(lib, "ws2_32")

int main(){
    int sock,sock2,tam,n;
    struct sockaddr_in servidor,cliente;
    char buffer[256];
   char puerto[256];
   puerto[255]='\0';
    WSADATA wsadata;
    char *serverip;
   
   
    if(WSAStartup(MAKEWORD(2,0),&wsadata)!=0){
        fprintf(stderr,"error en wsa");
        exit(1);
    }
    if((sock=socket(PF_INET,SOCK_STREAM, IPPROTO_TCP))<0){
        fprintf(stderr,"error en crear la estructura");
    }
    if((sock2=socket(PF_INET,SOCK_STREAM, IPPROTO_TCP))<0){
        fprintf(stderr,"error en crear la estructura");
    }
    tam=sizeof(servidor);
    memset(&servidor, 0, sizeof (servidor));
    memset(&cliente, 0, sizeof (cliente));
    servidor.sin_family=AF_INET;
    servidor.sin_addr.s_addr=inet_addr("192.168.0.9");
    servidor.sin_port=htons(8002);   
    printf("ingrese el puerto donde desea escuchar : ");
    fgets(puerto,256,stdin);
    cliente.sin_family=AF_INET;
    cliente.sin_addr.s_addr=inet_addr("192.168.0.9");
    cliente.sin_port=(unsigned short)atoi(puerto);
    printf("el puerto es %d",cliente.sin_port);
    printf("\n iniciando \n");      
     if(connect(sock, (struct sockaddr *)&servidor,sizeof(struct sockaddr))==-1){
 /* llamada a connect() */
 printf("connect() error\n");

 }
    
    send(sock,puerto,256,0);
    printf("se envio el numero de puerto %s",puerto);   
   
  

    if(bind(sock2,(struct sockaddr *)&cliente,tam)<0){
        fprintf(stderr,"error en bind");
    }
    if(connect(sock2, (struct sockaddr *)&servidor,sizeof(struct sockaddr))==-1){
 /* llamada a connect() */
 printf("connect() error\n");

 }
    recv(sock2,buffer,256,0);
    printf("el nombre de host del servidor es: %s y el nuevo puerto de recepcion es %d",buffer,cliente.sin_port);

    system("pause");
    
    closesocket(sock2);
    WSACleanup();
    return 0;
}