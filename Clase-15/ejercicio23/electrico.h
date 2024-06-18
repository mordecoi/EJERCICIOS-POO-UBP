#ifndef ELECTRICO_H
#define ELECTRICO_H
#include <iostream>

class Electrico
{
public:
    inline Electrico(int voltaje = 220) : voltaje_(voltaje) {}
    inline ~Electrico() { std::cout << "Desenchufado" << std::endl; }
    inline int getVoltaje() { return voltaje_; }
    inline void setVoltaje(int voltaje) { voltaje_ = voltaje; }

protected:
    int voltaje_;
};

#endif // ELECTRICO_H
