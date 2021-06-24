#include <iostream>
using namespace std;
#include <clocale>
#include "Pasajero.h"
#include "Persona.h"
#include "Fecha.h"
#include "rlutil.h"

void Pasajero::cargar(){
    Persona::cargar();
    cout << "INGRESE LA FECHA DE NACIMIENTO: " ;
    _nacimiento.cargar();
}
void Pasajero::mostrar(){
    Persona::mostrar();
    gotoxy(40, 18);
    cout << "FECHA DE NACIMIENTO: ";
    gotoxy(65, 18);
    _nacimiento.mostrar();
}
Fecha Pasajero::getNacimiento(){
    return _nacimiento;
}
void Pasajero::setNacimiento(Fecha nacimiento){
    _nacimiento=nacimiento;
}
bool Pasajero::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("pasajeros.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Pasajero)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void Pasajero::grabarEnDisco(){
    FILE *p;
    p = fopen("pasajeros.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Pasajero::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("pasajeros.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Pasajero)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
