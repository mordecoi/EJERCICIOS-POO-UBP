#include <iostream>
#include <vector>
#include <algorithm>
#include "namespace.h"
#include "classEstudianteUBP.h"
using namespace std;

void funcNehuen::funcEjercicio07()
{
    estudianteUBP estu1, estu2("Alma", 22), estu3("Pepe", 23, true);

    estu1.setNombre("Mariano");
    estu1.setEdad(21);
    estu1.setMatricula(true);

    estu2.setMatricula(false);

    vector<estudianteUBP> estudiantes = {estu1, estu2, estu3};
    cout << "Vector sin ordenar: \n";
    cout << "Nombres: " << estu1.getNombre() << " | " << estu2.getNombre() << " | " << estu3.getNombre() << " |\nEdades: " << estu1.getEdad() << " | " << estu2.getEdad() << " | " << estu3.getEdad() << " |\nEstado matricula: " << estu1.getMatricula() << " | " << estu2.getMatricula() << " | " << estu3.getMatricula() << " |\n";

    ordenarEstudiantes(estudiantes);

    cout << "\nVector ordenado: \n";
    cout << "Nombres: " << estu1.getNombre() << " | " << estu2.getNombre() << " | " << estu3.getNombre() << " |\nEdades: " << estu1.getEdad() << " | " << estu2.getEdad() << " | " << estu3.getEdad() << " |\nEstado matricula: " << estu1.getMatricula() << " | " << estu2.getMatricula() << " | " << estu3.getMatricula() << " |\n";
}
