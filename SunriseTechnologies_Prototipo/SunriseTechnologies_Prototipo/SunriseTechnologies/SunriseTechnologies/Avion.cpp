#include "Avion.h"

void Avion::cargar() {
}
void Avion::mostrar() {
}
int Avion::getCapacidadAsientosW() {
    return _capacidadAsientosW;
}
int Avion::getCapacidadAsientosJ() {
    return _capacidadAsientosJ;
}
float Avion::getCapacidadCombustible() {
    return _capacidadCombustible;
}
char* Avion::getModelo() {
    return _modelo;
}
void Avion::setCapacidadAsientosW(int asientosW) {
    if (asientosW >= 0) {
        _capacidadAsientosW = asientosW;
    }
    else {
        _capacidadAsientosW = 0;
    }
}
void Avion::setCapacidadAsientosJ(int asientosJ) {
    if (asientosJ >= 0) {
        _capacidadAsientosJ = asientosJ;
    }
    else {
        _capacidadAsientosJ = 0;
    }
}
void Avion::setCapacidadCombustible(float combustible) {
    if (combustible >= 0) {
        _capacidadCombustible = combustible;
    }
    else {
        _capacidadCombustible = 0;
    }
}
void Avion::setModelo(char* modelo) {
    strcpy(_modelo, modelo);
}
bool Avion::grabarEnDisco(int pos) {
    bool guardo;
    FILE* p;
    p = fopen("aviones.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(Avion) * pos, SEEK_SET);
    guardo = fwrite(this, sizeof * this, 1, p);
    fclose(p);
    return guardo;
}
bool Avion::leerDeDisco(int pos) {
    bool lectura;
    FILE* p;
    p = fopen("aviones.dat", "rb");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(Avion) * pos, SEEK_SET);
    lectura = fread(this, sizeof * this, 1, p);
    fclose(p);
    return lectura;
}