
#include <iostream>
using namespace std;

#include <clocale>
#include "Horario.h"

int Horario::getHora(){
    return _hora;
}
int Horario::getMinuto(){
    return _minuto;
}
void Horario::setHora(int hora){
    _hora = hora;
}
void Horario::setMinuto(int minuto){
    _minuto = minuto;
}
void Horario::mostrar(){
    cout << "  " << _hora << ":";
    if(_minuto == 0){
        cout << "0" << _minuto << endl;
    }
    else{
        cout <<_minuto << endl;
    }
}
void Horario::cargar(){
    cout << "  HORA: ";
    cin >> _hora;
    cout << "  MINUTOS: ";
    cin >> _minuto;
}
