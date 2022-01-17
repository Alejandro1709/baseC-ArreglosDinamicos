#include "pch.h"
#include "conio.h"
#include <iostream>
 
using namespace System;
using namespace std;
 
void mostrarArreglo(const int* arreglo, const int& N) {
    for (int i = 0; i < N; i++) {
        cout << "Arreglo [" << i << "] = " << arreglo[i] << endl;
    }
}
 
int* agregarAlFinal(int* vector_anterior, int* tamanho, int Numero) {
    int* Aux = new int[*tamanho + 1]; // definir arreglo temporal
    for (int i = 0; i < *tamanho; i++) {// copia de los valores anteriores
        Aux[i] = vector_anterior[i];
    }
    if (vector_anterior != NULL)
        delete[] vector_anterior;
    Aux[*tamanho] = Numero;
    *tamanho = *tamanho + 1;
    return Aux;
}
 
int* insertarEnPosicion(int* V, int* N, int pos, int num) {
    if (pos >= 0 && pos <= *N) { //validando que mi posicion esta dentro del arreglo
        int* Aux = new int[*N + 1];
        for (int i = 0; i < *N + 1; i++) {
            if (i < pos) Aux[i] = V[i];
            if (i == pos) Aux[i] = num;
            if (i > pos) Aux[i] = V[i - 1];
        }
        delete[] V;
        *N = *N + 1;
        return Aux;
    }
    else
        return V;
}
 
int* agregarAlInicio(int* V, int* N, int num) {
    return insertarEnPosicion(V, N, 0, num);
}
 
void modificarEnPosicion(int* V, int* N, int posicion, int num) {
    if (posicion > 0 && posicion < *N) { //validando que mi posicion esta dentro del arreglo
        V[posicion] = num;
    }
}
 
int* eliminarEnPosicion(int* vector_anterior, int* N, int posicion) {
    if (posicion > 0 && posicion < *N) { //validando que mi posicion esta dentro del arreglo
        int* Aux = new int[*N - 1];
        //copiar los elementos que no queremos eliminar
        for (int i = 0; i < *N - 1; i++) {
            if (i < posicion)
                Aux[i] = vector_anterior[i];
            else
                Aux[i] = vector_anterior[i + 1];
        }
        //liberar la memoria de vector_anterior
        delete[] vector_anterior;
        *N = *N - 1;
        return Aux;
    }
    else {
        cout << "Posicion incorrecta: Debe estar entre 0 y " << (*N - 1);
        return vector_anterior;
    }
}
 
void ordenarDescendente(int* V, int* N) {
    int v;
    for (int i = 0; i < *N - 1; i++)
        for (int j = i + 1; j < *N; j++)
            if (V[i] < V[j]) {
                v = V[i];
                V[i] = V[j];
                V[j] = v;
            }
}