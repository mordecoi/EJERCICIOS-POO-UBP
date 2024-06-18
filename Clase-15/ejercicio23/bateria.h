#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento
{
public:
    inline Bateria(int tambores = 5) : tambores_(tambores) {}
    inline void sonar() override { std::cout << "Bateria suena..." << std::endl; }
    inline int getTambores() { return tambores_; }
    inline void setTambores(int tambores) { tambores_ = tambores; }

private:
    int tambores_;
    friend class Afinador;
};

#endif // BATERIA_H
