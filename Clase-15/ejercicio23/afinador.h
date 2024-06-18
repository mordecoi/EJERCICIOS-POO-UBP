#ifndef AFINADOR_H
#define AFINADOR_H

#include "bateria.h"

class Afinador
{
public:
    void afinar(Bateria &bateria) {
        std::cout << "Afinando bateria con " << bateria.tambores_ << " tambores." << std::endl;
        bateria.tambores_ += 1; // Simple example of modifying private member
    }
};

#endif // AFINADOR_H
