#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>
#include <string>

class Instrumento
{
public:
    inline Instrumento(std::string marca = "Yamaha") : marca_(marca) {}
    virtual ~Instrumento() {}
    virtual void sonar() = 0;
    inline virtual void verlo() { std::cout << "Marca: " << marca_ << std::endl; }
    inline std::string getMarca() { return marca_; }
    inline void setMarca(std::string marca) { marca_ = marca; }

protected:
    std::string marca_;
};

#endif // INSTRUMENTO_H
