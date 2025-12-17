#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{

    int sock,n;
    unsigned int tam;
    struct sockaddr_in servidor,cliente;
    struct hostent *hp;
    char buffer[256];

    sock = socket(AF_INET, SOCK_DGRAM,0);
    if(sock<0){
        fprintf(stderr,"error al crear socket");
    }
    servidor.sin_family=AF_INET;     
    servidor.sin_addr.s_addr=inet_addr("192.168.0.9"); //cambiar por la direccion ip del servidor  
     servidor.sin_port = htons(8000); //cambiar por el puerto del servidor    
    tam= sizeof(struct sockaddr_in);   
    bzero(buffer,256);    
     printf("\n iniciando \n");
    printf("\n ingrese el mensaje \n");
    fgets(buffer,256,stdin);
   n=sendto(sock,buffer,256,0,(struct sockaddr*)&servidor,tam);
        
     n=recvfrom(sock,buffer,256,0,(struct sockaddr*)&cliente,&tam);
        printf("\n %s \n",buffer);
    
    return 0;

}