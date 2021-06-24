#include "Avion.h"
#include <iostream>
using namespace std;

#include <clocale>
#include <cstring>

void Avion::cargar(){
    cout << "CAPACIDAD DE ASIENTOS CLASE EJECUTIVA: " ;
    cin >> _capacidadAsientosW;
    cout << "CAPACIDAD DE ASIENTOS CLASE TURISTA: " ;
    cin >> _capacidadAsientosJ;
    cout << "CAPACIDAD DE COMBUSTIBLE: " ;
    cin >> _capacidadCombustible;
    cin.ignore();
    cout << "MODELO: " ;
    cin.getline(_modelo, 11);
    cout << "MATRICULA: ";
    cin.getline(_matricula,6);
}

void Avion::mostrar(){
    cout << "CAPACIDAD DE ASIENTOS CLASE EJECUTIVA: " << _capacidadAsientosW << endl;
    cout << "CAPACIDAD DE ASIENTOS CLASE TURISTA: " << _capacidadAsientosJ << endl;
    cout << "CAPACIDAD DE COMBUSTIBLE: " << _capacidadCombustible << endl;
    cout << "MODELO: " << _modelo << endl;
    cout << "MATRICULA: " << _matricula << endl;
}
int Avion::getCapacidadAsientosW(){
    return _capacidadAsientosW;
}
int Avion::getCapacidadAsientosJ(){
    return _capacidadAsientosJ;
}
float Avion::getCapacidadCombustible(){
    return _capacidadCombustible;
}
char *Avion::getModelo(){
    return _modelo;
}
char *Avion::getMatricula(){
    return _matricula;
}
void Avion::setCapacidadAsientosW(int asientosW){
    if(asientosW >= 0){
        _capacidadAsientosW = asientosW;
    }
    else{
        _capacidadAsientosW = 0;
    }
}
void Avion::setCapacidadAsientosJ(int asientosJ){
    if(asientosJ >= 0){
        _capacidadAsientosJ = asientosJ;
    }
    else{
        _capacidadAsientosJ = 0;
    }
}
void Avion::setCapacidadCombustible(float combustible){
    if( combustible >= 0 ){
        _capacidadCombustible = combustible;
    }
    else{
        _capacidadCombustible = 0;
    }
}
void Avion::setModelo(char *modelo ){
    strcpy(_modelo, modelo);
}
void Avion::setMatricula(char *codigo){
    strcpy(_matricula, codigo);
}

bool Avion::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("aviones.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Avion)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Avion::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("aviones.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Avion)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

void Avion::grabarEnDisco(){
    FILE *p;
    p = fopen("aviones.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
