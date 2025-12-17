#include <stdio.h>
int tam;


print_arreglo( double **p){


for (int i = 0; i < tam; i++)
{
    for (int j = 0; j < tam; j++)
{
   printf("%.2f  ",p[i][j]);
}
printf("\n");
  
}

}


int main()
{

    printf("ingrese el tamano de la matriz :");
scanf("%d",&tam);

double **p =(double **) malloc(tam*sizeof(double));




for (int i = 0; i < tam; i++)
{
    p[i]=(double *)malloc(tam*sizeof(double));
    
}

for (int i = 0; i < tam; i++)
{
    for (int j = 0; j < tam; j++)
{
    p[i][j]=i+j+1.0;
 
}
  
}
double *q=*p;
print_arreglo(p);

printf("el tamaño de la estructura es  : %d \n \n ",(tam*(sizeof(double))));

printf("la direccion de memoria de q es : %d \n \n ",&q);
printf("la direccion de memoria  QUE almacena  q es : %d \n \n ",q);
printf("el valor que almacena **p es : %.2f \n \n ",*q);


printf("la direccion de memoria de p es : %d \n \n ",&p);
printf("la direccion de memoria  QUE almacena  p es : %d \n \n ",p);
printf("la direccion de memoria que apunta  : %d \n \n ",*(p));
printf("la direccion de memoria que apunta p+1  : %d \n \n ",*(p+1));
printf("la direccion de memoria que apunta  p+2 : %d \n \n ",*(p+2));
printf("el valor que almacena **p es : %d \n \n ",*(*(p)));

free(p);



}