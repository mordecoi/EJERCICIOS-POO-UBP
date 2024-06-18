#include "namespace.h"
#include <algorithm>

namespace funcNehuen
{
bool compararEstudiantes(const estudianteUBP& a, const estudianteUBP& b) {
    return a.getNombre() < b.getNombre();
}

void ordenarEstudiantes(vector<estudianteUBP>& estudiantes) {
    std::sort(estudiantes.begin(), estudiantes.end(), compararEstudiantes);
}

void funcEjercicio07() {
    // Implementación de la función funcEjercicio07
    estudianteUBP estu1, estu2("Alma", 22), estu3("Pepe", 23, true);

    estu1.setNombre("Mariano");
    estu1.setEdad(21);
    estu1.setMatricula(true);

    estu2.setMatricula(false);

    vector<estudianteUBP> estudiantes = {estu1, estu2, estu3};
    cout << "Vector sin ordenar: \n";
    for (const auto& estudiante : estudiantes) {
        cout << "Nombre: " << estudiante.getNombre() << " | Edad: " << estudiante.getEdad() << " | Estado matricula: " << estudiante.getMatricula() << " |\n";
    }

    ordenarEstudiantes(estudiantes);

    cout << "\nVector ordenado: \n";
    for (const auto& estudiante : estudiantes) {
        cout << "Nombre: " << estudiante.getNombre() << " | Edad: " << estudiante.getEdad() << " | Estado matricula: " << estudiante.getMatricula() << " |\n";
    }
}
}
