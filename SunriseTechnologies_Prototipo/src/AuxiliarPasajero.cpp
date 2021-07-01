
#include <iostream>
using namespace std;

#include <clocale>
#include "AuxiliarPasajero.h"
#include <cstring>
#include "rlutil.h"

void AuxiliarPasajero::mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "PNR: " << _idPnr << endl;
}
void AuxiliarPasajero::mostrar2(){
    for(int i=0; i<45; i++){
        gotoxy(38+i, 26);
        cout << "*";
        if(i<14){
            gotoxy(38, 7+i);
            cout << "*";
            gotoxy(83, 7+i);
            cout << "*";
        }
    }
    gotoxy(40, 22);
    cout << "KILOS DESPACHADOS: " << _kilos << "KG" << endl;
    gotoxy(40, 24);
    cout << "ASIENTO: ";
    gotoxy(50, 24);
    switch (_columna){
        case 0:
            cout << _fila+1 << "A" <<endl;
            break;
        case 1:
            cout << _fila+1 << "B" <<endl;
            break;
        case 2:
            cout << _fila+1 << "C" <<endl;
            break;
        case 3:
            cout << _fila+1 << "D" <<endl;
            break;
    }
}
void AuxiliarPasajero::mostrar3(){
    cout << "ASIENTO: ";
    switch (_columna){
        case 0:
            cout << _fila+1 << "A" <<endl;
            break;
        case 1:
            cout << _fila+1 << "B" <<endl;
            break;
        case 2:
            cout << _fila+1 << "C" <<endl;
            break;
        case 3:
            cout << _fila+1 << "D" <<endl;
            break;
    }
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
bool AuxiliarPasajero::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("auxiliarPax.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(AuxiliarPasajero)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
