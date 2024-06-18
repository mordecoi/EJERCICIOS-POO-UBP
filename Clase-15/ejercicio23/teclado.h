#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico
{
public:
    inline Teclado(int teclas = 61) : teclas_(teclas) {}
    inline void sonar() override { std::cout << "Teclado suena..." << std::endl; }
    inline int getTeclas() { return teclas_; }
    inline void setTeclas(int teclas) { teclas_ = teclas; }

private:
    int teclas_;
};

#endif // TECLADO_H
