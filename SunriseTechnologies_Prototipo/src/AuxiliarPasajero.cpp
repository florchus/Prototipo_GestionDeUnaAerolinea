
#include <iostream>
using namespace std;

#include <clocale>
#include "AuxiliarPasajero.h"
#include <cstring>


void AuxiliarPasajero::mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "PNR: " << _idPnr << endl;
}
char *AuxiliarPasajero::getDni(){
    return _dni;
}
int AuxiliarPasajero::getIdPnr(){
    return _idPnr;
}
float AuxiliarPasajero::getKilos(){
    return _kilos;
}
bool AuxiliarPasajero::getEmbarco(){
    return _embarco;
}
void AuxiliarPasajero::setDni(char* dni){
    strcpy(_dni,dni);
}
void AuxiliarPasajero::setIdPnr(int id){
    _idPnr = id;
}
void AuxiliarPasajero::setKilos(float kg){
    _kilos=kg;
}
void AuxiliarPasajero::setEmbarco(bool embarco){
    _embarco=embarco;
}
bool AuxiliarPasajero::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("auxiliarPax.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(AuxiliarPasajero)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

void AuxiliarPasajero::grabarEnDisco(){
    FILE *p;
    p = fopen("auxiliarPax.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
