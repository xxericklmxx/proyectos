#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#pragma comment(lib, "ws2_32")

int main(){
    int sock,tam,n,numero;
    struct sockaddr_in servidor,cliente;
    char buffer[256];
    
    WSADATA wsadata;
    char *serverip;
    unsigned short puerto;
    if(WSAStartup(MAKEWORD(2,0),&wsadata)!=0){
        fprintf(stderr,"error en wsa");
        exit(1);
    }
    if((sock=socket(PF_INET,SOCK_DGRAM, IPPROTO_UDP))<0){
        fprintf(stderr,"error en crear la estructura");
    }
    tam=sizeof(servidor);
    memset(&servidor, 0, sizeof (servidor));
    memset(&cliente, 0, sizeof (cliente));
    servidor.sin_family=AF_INET;
    servidor.sin_addr.s_addr=INADDR_ANY;
    servidor.sin_port=htons(4000);   
    
    if(bind(sock,(struct sockaddr *)&servidor,tam)<0){
        fprintf(stderr,"error en bind");
    }
    printf("\n iniciando \n");

    while(1){
        n=recvfrom(sock,buffer,256,0,(struct sockaddr *)&cliente,&tam);
        numero= atoi(buffer);
        if(numero !=0)
        {      printf("el numero %d ingresado por el cliente es:",numero);
        if(numero%2==0){
        printf("par\n");
           memcpy(buffer, "el numero es par", 16);
        }else{
            
            printf("impar \n");
           memcpy(buffer, "el numero es impar", 19);
        }

         n=sendto(sock,buffer,256,0,(struct sockaddr*)&cliente,tam);
         numero=0;
        }

    }


    
    closesocket(sock);
    WSACleanup();
    return 0;
}