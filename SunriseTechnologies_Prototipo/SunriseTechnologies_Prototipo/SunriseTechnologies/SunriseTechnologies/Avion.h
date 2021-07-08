#pragma once
class Avion{
private:
    int _capacidadAsientosW;
    int _capacidadAsientosJ;
    float _capacidadCombustible;
    char _modelo[11];
public:
    Avion();
    void cargar();
    void mostrar();
    int getCapacidadAsientosW();
    int getCapacidadAsientosJ();
    float getCapacidadCombustible();
    char* getModelo();
    void setCapacidadAsientosW(int);
    void setCapacidadAsientosJ(int);
    void setCapacidadCombustible(float);
    void setModelo(char*);
    bool grabarEnDisco(int);
    bool leerDeDisco(int);

};

