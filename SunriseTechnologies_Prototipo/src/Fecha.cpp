
#include <iostream>
using namespace std;

#include <clocale>
#include "Fecha.h"

int Fecha::getDia() { return _dia; }
void Fecha::setDia(int val) {
    if( val >= 1 && val <= 31){
        _dia = val;
    }
    else{
        _dia = -1;
    }
}

int Fecha::getMes() { return _mes; }
void Fecha::setMes(int val) {
    if( val >= 1 && val <=12){
        _mes = val;
    }
    else{
        _mes = -1;
    }
}

int Fecha::getAnio() { return _anio; }
void Fecha::setAnio(int val) {
    if( val >= 1 ){
        _anio = val;
    }
}

void Fecha::mostrar(){
    cout << "  " << _dia << "/" << _mes << "/" << _anio << endl;
}

void Fecha::cargar(){
    cout << "  DIA: ";
    cin >> _dia;
    cout << "  MES: ";
    cin >> _mes;
    cout << "  AÑO: ";
    cin >> _anio;
}
