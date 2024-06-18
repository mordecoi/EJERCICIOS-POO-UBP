#include <iostream>
#include <vector>
#include <string>

class Instrumento
{
public:
    Instrumento(std::string marca = "Yamaha") : marca_(marca) {}
    virtual ~Instrumento() {}
    virtual void sonar() = 0;
    virtual void verlo() { std::cout << "Marca: " << marca_ << std::endl; }
    std::string getMarca() { return marca_; }
    void setMarca(std::string marca) { marca_ = marca; }

protected:
    std::string marca_;
};

class Electrico
{
public:
    Electrico(int voltaje = 220) : voltaje_(voltaje) {}
    ~Electrico() { std::cout << "Desenchufado" << std::endl; }
    int getVoltaje() { return voltaje_; }
    void setVoltaje(int voltaje) { voltaje_ = voltaje; }

protected:
    int voltaje_;
};

class Guitarra : public Instrumento
{
public:
    Guitarra(int cuerdas = 6) : cuerdas_(cuerdas) {}
    void sonar() { std::cout << "Guitarra suena..." << std::endl; }
    int getCuerdas() { return cuerdas_; }
    void setCuerdas(int cuerdas) { cuerdas_ = cuerdas; }

private:
    int cuerdas_;
};

class Teclado : public Instrumento, public Electrico
{
public:
    Teclado(int teclas = 61) : teclas_(teclas) {}
    void sonar() { std::cout << "Teclado suena..." << std::endl; }
    int getTeclas() { return teclas_; }
    void setTeclas(int teclas) { teclas_ = teclas; }

private:
    int teclas_;
};

class Bateria : public Instrumento
{
public:
    Bateria(int tambores = 5) : tambores_(tambores) {}
    void sonar() { std::cout << "Bateria suena..." << std::endl; }
    int getTambores() { return tambores_; }
    void setTambores(int tambores) { tambores_ = tambores; }

private:
    int tambores_;
};

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

    for (Instrumento *instrumento : instrumentos)
    {
        delete instrumento;
    }

    return 0;
}
