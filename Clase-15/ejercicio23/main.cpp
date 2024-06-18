#include <iostream>
#include <vector>
#include "guitarra.h"
#include "teclado.h"
#include "bateria.h"
#include "afinador.h"

int main()
{
    std::vector<Instrumento *> instrumentos;
    instrumentos.push_back(new Guitarra);
    instrumentos.push_back(new Teclado);
    instrumentos.push_back(new Bateria);
    instrumentos.push_back(new Guitarra(7));
    instrumentos.push_back(new Teclado(76));

    for (Instrumento *instrumento : instrumentos)
    {
        instrumento->verlo();
        instrumento->sonar();
        std::cout << std::endl;
    }

    Bateria *bateria = new Bateria();
    Afinador afinador;
    afinador.afinar(*bateria);
    bateria->verlo();
    bateria->sonar();
    delete bateria;

    for (Instrumento *instrumento : instrumentos)
    {
        delete instrumento;
    }

    return 0;
}
