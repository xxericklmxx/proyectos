


from numpy import arange
import numpy as np
class algoritmos():   
    def max_heapify(self,arreglo,n,i):
        largo=i
        l=2*i
        r=2*i+1
        if(l<n and arreglo[largo]<arreglo[l]):
            largo=l
        if(r<n and arreglo[largo]<arreglo[r]):
            largo=r
        if largo !=i:
            arreglo[i],arreglo[largo]=arreglo[largo],arreglo[i]
            #print(arreglo)
            self.max_heapify(arreglo,n,largo)

    def heapsort(self,arreglo):       
        n=len(arreglo)

        for i in range(n//2,-1,-1):
            self.max_heapify(arreglo,n,i)

        for i in range(n-1,0,-1):
            #print("antes de cambiar")
            #print(arreglo)
            arreglo[i],arreglo[0]=arreglo[0],arreglo[i]
            #print("despues de cambiar")
            #print(arreglo)
            self.max_heapify(arreglo,i,0)
            
   
    def particion(self,arreglo,bajo,alto):
        i= (bajo-1)
        
        pivot= arreglo[alto]
        for j in range(bajo,alto):
            
            if arreglo[j]<=pivot:
                i=i+1
                arreglo[i],arreglo[j]=arreglo[j],arreglo[i]
        
        arreglo[i+1],arreglo[alto]=arreglo[alto],arreglo[i+1]
        
        return (i+1)

   
    
    def quicksort(self,arreglo,bajo,alto):
               
        if len(arreglo) == 1:
            return arreglo
        if bajo <alto:
            p=self.particion(arreglo,bajo,alto)
            self.quicksort(arreglo,bajo,p-1)
            self.quicksort(arreglo,p+1,alto)

    def merger(self,arreglo,p,q,r):
        n1=q-p+1
        n2=r-q
        l=np.zeros(n1+1)
        d=np.zeros(n2+1)
       
       
        for i in range(1,n1,1):
            l[i]=arreglo[p+i]
        for j in range(1,n2,1):
            d[i]=arreglo[q+j]       
       
        
        i=1
        j=1
        
        
        for k in range(p,r,1):
            print(l[i])
            print(d[j])            
            if(l[i]<=d[j]):
                arreglo[k]=l[i]
                i+=1
            else:
                arreglo[k]=d[j]
                j+=1
            print(arreglo)          
    def mergersort2(self,arreglo,p,r):
        print("merger")
        if(p<r):
            q=(p+r)//2           
            self.mergersort2(arreglo,p,q)
            self.mergersort2(arreglo,q+1,r)
            print("q es :"+str(q))
            print("p es :"+str(p))
            print("r es :"+str(r))
            self.merger(arreglo,p,q,r)


    def mergesort(self,arreglo):        
        if(len(arreglo))>1:
            mid = len(arreglo)//2
            izquierda= arreglo[:mid]
            derecha= arreglo[mid:]
            self.mergesort(izquierda)
            self.mergesort(derecha)

            i=0
            j=0
            k=0

            while(i<len(izquierda) and j<len(derecha)):
                if izquierda[i] < derecha[j]:
                    
                    arreglo[k] = izquierda[i]
                    i+=1
                else:
                    arreglo[k]= derecha[j]
                    j +=1
                k +=1
            while(i<len(izquierda)):
                arreglo[k]=izquierda[i]
                i+=1
                k+=1
            
            while(j<len(derecha)):
                arreglo[k]= derecha[j]
                j+=1
                k+=1


    def bubblesort(self,arreglo):        
        n=len(arreglo)
        for i in range(n):
            for j in range(0,n-i-1):
                if(arreglo[j]>arreglo[j+1]):
                    arreglo[j],arreglo[j+1]= arreglo[j+1],arreglo[j]

                

    def selectionsort(self,arreglo):
        for i in range(len(arreglo)):

            min=i

            for j in range(i+1,len(arreglo)):

                if(arreglo[j]< arreglo[min]):
                    min =j


            arreglo[i],arreglo[min]=arreglo[min],arreglo[i]
        
    def insertionsort(self,arreglo):
        for i in range(1,len(arreglo)):
            k=arreglo[i]

            j=i-1

            while(j>= 0 and arreglo[j] > k):
                arreglo[j+1]= arreglo[j]

                j-=1
            
            arreglo[j+1]=k

    def countingsort(self,arreglo):
        contador=[0 for i in range(max(arreglo)+1)]
        #print(contador)

        for v in arreglo:
            contador[v] +=1
        #print(contador)

        for i in range(1,len(contador)):
            contador[i]= contador[i-1]+contador[i]
        #print(contador)

        res= [0 for i in range(len(arreglo))]

        for j in range(len(arreglo)-1,-1,-1):
            valor=arreglo[j]
            i=contador[valor]-1
            res[i]= valor
            contador[valor] -=1

        return res

    def conteo(self,arreglo,lugar):
        tam= len(arreglo)
        res=[0]*tam
        contador=[0]*10

        for i in range(0,tam):
            indice=arreglo[i]//lugar
            contador[indice%10]+=1
        
        for i in range(1,10):
            contador[i] +=contador[i-1]
                
        i=tam-1
        while(i >=0):
            indice=arreglo[i]//lugar
            res[contador[indice %10]-1]= arreglo[i]
            contador[indice %10] -=1
            i -=1
        for i in range(0,tam):
            arreglo[i]=res[i]

    def radixsort(self,arreglo):
        mayor=max(arreglo)

        lugar=1
        while(mayor//lugar >0):
            self.conteo(arreglo,lugar)
            lugar *=10

    def convertir_numero(self,arreglo):
        mayor= max(arreglo)
        menor=min(arreglo)    
        for i in range(len(arreglo)):
            arreglo[i]=abs(round((arreglo[i]-menor)/(mayor-menor),6))
        return arreglo    

    def bucketsort(self,arreglo):          
        mayor= max(arreglo)
        n= len(arreglo)
        tam= mayor/n    
        
        buckets= [[]for i in range(n)]

        for i in range(n):
            indice= int(arreglo[i]/tam)
            if indice !=n:
                buckets[indice].append(arreglo[i])
            else:
                buckets[n-1].append(arreglo[i])
            
        for i in range(len(arreglo)):            
             buckets[i]=sorted(buckets[i],key=float)

        resultado=[]
        for i in range(n):
            resultado= resultado+buckets[i]        
        arreglo=resultado
        self.convertir_numero(arreglo)
        return arreglo       
        


    def shellsort(self,arreglo):
        tam= len(arreglo)
        salto=tam//2
        while(salto > 0):
            for i in range(salto,tam):
                aux=arreglo[i]
                j=i
                while j>= salto and arreglo[j-salto]>aux:
                    arreglo[j]=arreglo[j-salto]
                    j -= salto
                arreglo[j]=aux
            salto= salto//2
        
    def stoogesort(self,arreglo, l, h):
        if l >= h:
            return   
        if arreglo[l]>arreglo[h]:
            t = arreglo[l]
            arreglo[l] = arreglo[h]
            arreglo[h] = t   
        
        if h-l+1 > 2:
            t = (int)((h-l+1)//3)         
            self.stoogesort(arreglo, l, (h-t))        
            self.stoogesort(arreglo, l+t, (h))        
            self.stoogesort(arreglo, l, (h-t))
        
            


                

        
#arr=[4,2,1,3,1,1]
#arr=[0.25,0.2,0.0,0.85,0.4,0.65,1.0]

#arr=[15,423,983,600,0,0]
#n=len(arr)
#p=algoritmos()
#p.stoogesort(arr,0,n-1)
#p.heapsort(arr)
#p.bubblesort(arr)
#p.quicksort(arr,0,n-1)
#print(arr)
#p.mergersort2(arr,0,5)
#bubblesort(arr)
#selectionsort(arr)
#insertionsort(arr)
#print(p.countingsort(arr))
#p.radixsort(arr)
#print(p.bucketsort(arr))
#shellsort(arr)
#stoogesort(arr,0,n-1)
#print(arr)



