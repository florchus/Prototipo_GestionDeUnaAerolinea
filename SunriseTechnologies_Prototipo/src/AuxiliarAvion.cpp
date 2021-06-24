#include <iostream>
#include <cstring>
#include "AuxiliarAvion.h"
using namespace std;
void AuxiliarAvion::cargar(){
    cout << "INGRESE EL ID DE VUELO:" << endl ;
    cin >> _idVuelo;
    cout << "INGRESE LA CAPACIDAD DE ASIENTOS EN W:" << endl ;
    cin >> _capacidadAsientosW ;
    cout << "INGRESE LA CAPACIDAD DE ASIENTOS EN J:" << endl ;
    cin >> _capacidadAsientosJ;
}
void AuxiliarAvion::mostrar(){
    cout << "ASIENTOS DISPONIBLES EN EJECUTIVA(W): " << _capacidadAsientosW << endl;
    cout << "ASIENTOS DISPONIBLES EN TURISTA(J)  : " << _capacidadAsientosJ << endl;
}
int AuxiliarAvion::getCapacidadAsientosW(){
    return _capacidadAsientosW;
}
int AuxiliarAvion::getCapacidadAsientosJ(){
    return _capacidadAsientosJ;
}
int AuxiliarAvion::getIdVuelo(){
    return _idVuelo;
}
void AuxiliarAvion::setCapacidadAsientosW(int cantW){
    _capacidadAsientosW=cantW;
}
void AuxiliarAvion::setCapacidadAsientosJ(int cantJ){
    _capacidadAsientosJ=cantJ;
}
bool AuxiliarAvion::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("auxiliaravion.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(AuxiliarAvion)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void AuxiliarAvion::grabarEnDisco(){
    FILE *p;
    p = fopen("auxiliaravion.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool AuxiliarAvion::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("auxiliaravion.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(AuxiliarAvion)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
