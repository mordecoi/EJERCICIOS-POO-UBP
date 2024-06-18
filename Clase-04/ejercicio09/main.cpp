#include <iostream>

using namespace std;

// Función genérica para imprimir valores ordenados
template <class T>
void imprimirValoresOrdenados(T* arreglo, int cantidad, bool ordenDescendente) {
    // Ordenar el array utilizando el método de ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T valorActual = arreglo[i];
        int j = i - 1;
        if (ordenDescendente) {
            while (j >= 0 && arreglo[j] < valorActual) {
                arreglo[j + 1] = arreglo[j];
                j--;
            }
        } else {
            while (j >= 0 && arreglo[j] > valorActual) {
                arreglo[j + 1] = arreglo[j];
                j--;
            }
        }
        arreglo[j + 1] = valorActual;
    }

    // Imprimir los valores ordenados
    if (ordenDescendente) {
        cout << "Valores ordenados en orden descendente: ";
        for (int i = 0; i < cantidad; ++i) {
            cout << arreglo[i] << " ";
        }
    } else {
        cout << "Valores ordenados en orden ascendente: ";
        for (int i = 0; i < cantidad; ++i) {
            cout << arreglo[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Array de enteros
    int enteros[] = {1, 4, 7, 8, 2, 3, 0};
    int cantidadEnteros = sizeof(enteros) / sizeof(enteros[0]);

    // Array de flotantes
    float flotantes[] = {3.4, 2.7, 1.9, 5.5, 6.3, 7.5, 3.6};
    int cantidadFlotantes = sizeof(flotantes) / sizeof(flotantes[0]);

    // Ordenar y imprimir los valores de mayor a menor
    imprimirValoresOrdenados(enteros, cantidadEnteros, true);
    imprimirValoresOrdenados(flotantes, cantidadFlotantes, true);

    // Ordenar y imprimir los valores de menor a mayor
    imprimirValoresOrdenados(enteros, cantidadEnteros, false);
    imprimirValoresOrdenados(flotantes, cantidadFlotantes, false);

    return 0;
}
