#include <iostream>
#include "namespace.h"
#include "classEstudianteUBP.h"
using namespace std;

void funcNehuen::funcEjercicio06()
{
    estudianteUBP estu1, estu2("Juan", 22), estu3("Pepe", 23, true);

    estu1.setNombre("Carlos");
    estu1.setEdad(21);
    estu1.setMatricula(true);

    estu2.setMatricula(false);

    cout << "Nombres: " << estu1.getNombre() << " | " << estu2.getNombre() << " | " << estu3.getNombre() << " |\nEdades: " << estu1.getEdad() << " | " << estu2.getEdad() << " | " << estu3.getEdad() << " |\nEstado matricula: " << estu1.getMatricula() << " | " << estu2.getMatricula() << " | " << estu3.getMatricula() << " |\n";
}
