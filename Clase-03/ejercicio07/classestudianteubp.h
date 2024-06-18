#ifndef CLASSESTUDIANTEUBP_H
#define CLASSESTUDIANTEUBP_H

#include <iostream>
#include <vector>
using namespace std;

class estudianteUBP
{
private:
    string nombre;
    int edad;
    float promedio;
    vector<int> notas;
    bool matriculado;

public:
    estudianteUBP();
    estudianteUBP(string nomb,int ed);
    estudianteUBP(string nomb, int ed, bool matricula);

    string getNombre() const {return nombre;}
    int getEdad() const {return edad;}
    float getPromedio() const {return promedio;}
    vector<int> getNotas() const {return notas;}
    bool getMatricula() const {return matriculado;}

    void setNombre(string nomb) {nombre = nomb;}
    void setEdad(int ed) {edad = ed;}
    void agregarNota(int nota) {notas.push_back(nota);}
    void setMatricula(bool est) {matriculado = est;}

    void calcularPromedio();

    ~estudianteUBP(){};
};

//a basic car class
class Car
{

};


#endif // CLASSESTUDIANTEUBP_H
