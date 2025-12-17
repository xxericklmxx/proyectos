#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#pragma comment(lib, "ws2_32")

int main(){
    int sock,tam,n,numero;

    struct sockaddr_in servidor,cliente;
    char buffer[256];
    char hostname[256];
    hostname[255]='\0';
    
    WSADATA wsadata;
    char *serverip;
    unsigned short puerto,*p;
    if(WSAStartup(MAKEWORD(2,0),&wsadata)!=0){
        fprintf(stderr,"error en wsa");
        exit(1);
    }
    if((sock=socket(PF_INET,SOCK_STREAM, IPPROTO_TCP))<0){
        fprintf(stderr,"error en crear la estructura");
    }
    tam=sizeof(servidor);
    memset(&servidor, 0, sizeof (servidor));
    memset(&cliente, 0, sizeof (cliente));
    gethostname(hostname,255);
    servidor.sin_family=AF_INET;
    servidor.sin_addr.s_addr=INADDR_ANY;
    servidor.sin_port=htons(8002);   
    
    if(bind(sock,(struct sockaddr *)&servidor,tam)<0){
        fprintf(stderr,"error en bind");
    }
    if(listen(sock,5) == -1) {
 printf("error en listen()\n");
 
    }

    printf("\n iniciando \n");

    while(1){
         tam = sizeof(cliente);
         if ((n = accept(sock,(struct sockaddr *)&cliente,&tam))==-1) {
 printf("error en accept()\n");
  }
  if(numero==0){
      recv(n,buffer,256,0);
  puerto=atoi(buffer);
  printf("el mensaje se recibio del puerto %d ",cliente.sin_port);
 
  printf("el nuevo puerto es %d ",puerto,cliente.sin_port);
  cliente.sin_port=(unsigned short)puerto;   
  printf("se enviara la respuesta al puerto %d",cliente.sin_port);  
numero=1;
  }
  
  send(n,hostname,256,0);


    }


    
    closesocket(sock);
    WSACleanup();
    return 0;
}