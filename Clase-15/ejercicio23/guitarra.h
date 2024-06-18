#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento
{
public:
    inline Guitarra(int cuerdas = 6) : cuerdas_(cuerdas) {}
    inline void sonar() override { std::cout << "Guitarra suena..." << std::endl; }
    inline int getCuerdas() { return cuerdas_; }
    inline void setCuerdas(int cuerdas) { cuerdas_ = cuerdas; }

private:
    int cuerdas_;
};

#endif // GUITARRA_H
