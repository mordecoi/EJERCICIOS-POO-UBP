#include "classestudianteubp.h"

estudianteUBP::estudianteUBP()
{
    nombre = "";
    edad = 0;
    promedio = 0;
    matriculado = false;
}
estudianteUBP::estudianteUBP(string nomb, int ed)
{
    nombre = nomb;
    edad = ed;
    promedio = 0;
    matriculado = false;
}
estudianteUBP::estudianteUBP(string nomb, int ed, bool matricula)
{
    nombre = nomb;
    edad = ed;
    promedio = 0;
    matriculado = matricula;
}

void estudianteUBP::calcularPromedio()
{
    if(notas.size() == 0){
        vector<int> notas = getNotas();
        int acum = 0;
        for (int i = 0; i < notas.size(); ++i) {
            acum += notas.at(i);
        }
        promedio = acum / notas.size();
    }
    else cout << "No se puede calcular el promedio porque no hay notas cargadas.\n";
}
