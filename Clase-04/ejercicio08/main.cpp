#include <iostream>
#include <string>

using namespace std;

// Clase Persona
class Persona {
public:
    Persona(const string& nombre) : nombre_(nombre) {}
    string obtenerNombre() const { return nombre_; }

private:
    string nombre_;
};

// Clase Poste
class Poste {
public:
    Poste(double altura, double diametro) : altura_(altura), diametro_(diametro) {}
    double getAltura() const { return altura_; }
    double getDiametro() const { return diametro_; }

private:
    double altura_;
    double diametro_;
};

// Sobrecarga del operador de inserción para la clase Persona
ostream& operator<<(ostream& os, const Persona& persona) {
    os << persona.obtenerNombre();
    return os;
}

// Sobrecarga del operador de inserción para la clase Poste
ostream& operator<<(ostream& os, const Poste& poste) {
    os << "altura: " << poste.getAltura() << " metros, diametro: " << poste.getDiametro() << " cm";
    return os;
}

// Función genérica para imprimir descripción de cualquier objeto
template<typename T>
void imprimirDescripcion(const T& objeto, const string& mensaje) {
    cout << mensaje << ": " << objeto << endl;
}

int main() {
    // Crear objetos Persona
    Persona persona1("Oscar");
    Persona persona2("Maria");

    // Crear objetos Poste
    Poste poste1(16.0, 32.0);
    Poste poste2(4.0, 24.0);

    // Imprimir descripción de los objetos
    imprimirDescripcion(persona1, "Persona con nombre");
    imprimirDescripcion(persona2, "Persona con nombre");
    imprimirDescripcion(poste1, "Poste con");
    imprimirDescripcion(poste2, "Poste con");

    return 0;
}
