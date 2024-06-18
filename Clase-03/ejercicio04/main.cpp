#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    vector<int> valores;

    // Cargar 30 valores pseudoaleatorios entre 1 y 15
    srand(static_cast<unsigned int>(time(nullptr))); // Inicializar la semilla del generador de números pseudoaleatorios
    for (int i = 0; i < 30; ++i) {
        valores.push_back(rand() % 15 + 1);
    }

    // Ordenar el vector para que los valores iguales estén juntos
    sort(valores.begin(), valores.end());

    // Encontrar la moda
    int moda = valores[0];
    int frecuenciaModa = 1;
    int frecuenciaActual = 1;

    for (size_t i = 1; i < valores.size(); ++i) {
        if (valores[i] == valores[i - 1]) {
            ++frecuenciaActual;
        } else {
            if (frecuenciaActual > frecuenciaModa) {
                moda = valores[i - 1];
                frecuenciaModa = frecuenciaActual;
            }
            frecuenciaActual = 1;
        }
    }

    // Comprobar la última secuencia
    if (frecuenciaActual > frecuenciaModa) {
        moda = valores.back();
        frecuenciaModa = frecuenciaActual;
    }

    // Mostrar datos del vector
    cout << "Los datos del vector son: ";
    for(int dato: valores)
        cout << dato << " | ";

    // Mostrar la moda
    cout << "\nLa moda es: " << moda << "\nAparece " << frecuenciaModa << " veces." << endl;

    return 0;
}
