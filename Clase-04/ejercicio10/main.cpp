#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Jugador
class Jugador {
public:
    // Constructor
    Jugador() : velocidad_(0), fuerza_(0), nombre_("sin nombre") {}

    // Constructor con parámetros
    Jugador(int velocidad, int fuerza, const string& nombre)
        : velocidad_(velocidad), fuerza_(fuerza), nombre_(nombre) {}

    // Destructor
    ~Jugador() {}

    // Métodos setter y getter
    void setVelocidad(int velocidad) { velocidad_ = velocidad; }
    void setFuerza(int fuerza) { fuerza_ = fuerza; }
    void setNombre(const string& nombre) { nombre_ = nombre; }

    int getVelocidad() const { return velocidad_; }
    int getFuerza() const { return fuerza_; }
    string getNombre() const { return nombre_; }

private:
    int velocidad_;
    int fuerza_;
    string nombre_;
};

int main() {
    // Crear un vector de Jugador
    vector<Jugador> jugadores;

    // Insertar 10 jugadores distintos
    for (int i = 0; i < 10; ++i) {
        Jugador jugador(i * 10, i * 5, "Jugador" + to_string(i + 1));
        jugadores.push_back(jugador);
    }

    // Mostrar los datos de cada jugador
    cout << "Nombre:          Velocidad:          Fuerza:           \n";
    for (const Jugador& jugador : jugadores) {
        cout << jugador.getNombre() << "          " << jugador.getVelocidad() << "                    " << jugador.getFuerza() << "\n";
    }

    return 0;
}
