#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>  

/* criterio =1   suma
criterio =2      resta
criterio = 3      division
criterio =4    multiplicacion 
*/
int tam;
double n=0;
int columna =0;
int ind=1;
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

bool verificar_columna(double **p,int col){

bool flag=false;

for (int i = 1; i < tam; i++)
{     if(abs(p[i][col]) !=0)
        flag=true;
}

return flag;
}


reduccion_inferior(double **p, double **identidad){

for (int k = 1; k < tam; k++)
{
    

for (int i = 0; i < tam; i++)
{
    for (int j = 0; j < tam; j++)
    {
             if(verificar_columna(p,columna)==false && columna <tam){
               columna++;
               printf("la columna tiene el indice : %d \n",columna);
            }

       if(i==j){         
         reduccion_fila(*(p+i),i,p,*(identidad+i),3,p[i][i]);
          print_arreglo(p);
          print_arreglo(identidad);
    }
    else{
        if(i>=j)
        {
           if(columna!=0 ){
               ind=columna++;
               if(ind>=tam){
                   ind=tam-1;
               }
           }  
           
            if(p[i][j]!=0 && p[i][j]>0)
            {
                                 
                reduccion_fila(*(p+i),ind,p,*(identidad+i),2,p[i][j]);
                
            }if(p[i][j]<0){
                reduccion_fila(*(p+i),ind,p,*(identidad+i),1,p[i][j]);
            }
            print_arreglo(p);
            print_arreglo(identidad);

        }
        
    }


    }
    
    
   
}
}

}
reduccion_fila(double *p, int indice,double **matriz ,double *identidad,int criterio,double numero){
          
         
         
         printf("el criterio es : %d \n \n",criterio);
    for (int i = 0; i < tam; i++)
    {  
       
        if(criterio==1){
              printf(" n es : %.2f \n",n);  
            double n= matriz[indice-1][i];
         *(p)= *(p)+abs(numero)*n;
          *(identidad)=*(identidad)+abs(numero)*n;
          p++;
          identidad++;
        }
         if(criterio==2){     
                double n= matriz[indice-1][i];
             
            printf(" n es : %.2f \n",n);  
        *(p)= *(p)-(numero*n);
          *(identidad)=*(identidad)-numero*n;        
            identidad++;
          p++;
           
        }
         if(criterio==3){
          *(p)= *(p)/numero;         
            *(identidad)=*(identidad)/numero;
              identidad++;
          p++;
          
        }
         if(criterio==4){
                  *(p)= *(p)*numero;
                    *(identidad)=*(identidad)*numero;
                      identidad++;
          p++;
        }
       
       }
    

}


void main(){




printf("ingrese el tamano de la matriz :");
scanf("%d",&tam);

double **p =(double **) malloc(tam*sizeof(double));
double **identidad =(double **) malloc(tam*sizeof(double));
for (int i = 0; i < tam; i++)
{
    p[i]=(double *)malloc(tam*sizeof(double));
    identidad[i]=(double *)malloc(tam*sizeof(double));
}

for (int i = 0; i < tam; i++)
{
    for (int j = 0; j < tam; j++)
{
   
    if(i==j){
        identidad[i][j]=1;
    }
    else{
    identidad[i][j]=0;
    }
}
  
}
p[0][0]=3.0;
p[0][1]=2.0;
p[0][2]=5.0;
p[1][0]=2.0;
p[1][1]=-1.0;
p[1][2]=4.0;
p[2][0]=-1.0;
p[2][1]=2.0;
p[2][2]=1.0;




printf("antes de llamar a la funcion \n \n");
print_arreglo(p);
print_arreglo(identidad);
reduccion_inferior(p,identidad);
printf("depues de llamar a la funcion \n \n");
print_arreglo(p);
print_arreglo(identidad);





free(p);
free(identidad);

  
}
