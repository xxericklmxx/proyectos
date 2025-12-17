
#pragma once
#include <iostream>
class algoritmos
{

public:
    algoritmos(float** matriz, float** identidad, int tam) {
        this->matriz = matriz;
        this->identidad = identidad;
        this->tam = tam;
    }
	~algoritmos();
    void matriz_inversa() {
        float pivote, aux;

        for (int i = 0; i <this->tam; i++)
        {
            pivote = this->matriz[i][i];
            for (int j = 0; j < this->tam; j++)
            {
                this->matriz[i][j] =this->matriz[i][j] / pivote;
                this->identidad[i][j] =this->identidad[i][j] / pivote;


            }
            for (int k = 0; k < this->tam; k++) {

                if (i != k) {
                    aux = this->matriz[k][i];
                    for (int j = 0; j < tam; j++)
                    {
                        matriz[k][j] = matriz[k][j] - aux * matriz[i][j];
                        identidad[k][j] = identidad[k][j] - aux * identidad[i][j];
                    }

                }

            }

        }



    }



    void imprimir_matriz(float **matriz) {

        for (int i = 0; i < this->tam; i++)
        {
            for (int j = 0; j <this->tam; j++)
            {
                std::cout << matriz[i][j] << " ";


            }
            std::cout << " " << std::endl;

        }

    }

    void limpiar_memoria() {
        for (int j = 0; j < tam; j++)
        {
            delete[] this->matriz[j];


        }
        delete[]this->matriz;
    }

private:
	float **matriz;
	float **identidad;
    int tam;

};

