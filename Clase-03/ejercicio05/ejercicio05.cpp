#include <iostream>
#include "namespace.h"
#include <algorithm>

void funcNehuen::funcEjercicio05()
{
    std::vector<std::string> listaExpr;
    listaExpr.push_back("Tomar el pelo");
    listaExpr.push_back("Estar jodiendo");
    listaExpr.push_back("Cada muerte de obispo");
    listaExpr.push_back("Dar pelota");
    listaExpr.push_back("No da");

    std::cout << "Lista sin ordenar: \n";
    for (int i = 0; i < 5; ++i) {
        std::cout << listaExpr.at(i) << "\n";
    }
    std::sort(listaExpr.begin(), listaExpr.end());
    std::cout << "\nLista ordenada: \n";
    for (int i = 0; i < 5; ++i) {
        std::cout << listaExpr.at(i) << "\n";
    }
}
