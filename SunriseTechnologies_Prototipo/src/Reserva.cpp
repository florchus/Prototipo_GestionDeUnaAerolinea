
#include <iostream>
using namespace std;

#include <clocale>
#include <cstring>
#include "Reserva.h"
#include "Fecha.h"

Reserva::Reserva()
{

}

void Reserva::mostrar(){
    cout << "  PNR: " << _idPnr << endl;
    cout << "  FECHA DE COMPRA: ";
     _fechaCompra.mostrar();
    cout << "  FECHA DE EMBARQUE: ";
    _fechaEmbarque.mostrar();
    cout << "  IMPORTE: $" << _importe << endl;
    cout << "  ID VUELO: " << _idVuelo << endl;
    if(_estado == true){
        cout << "  RESERVA CONFIRMADA" << endl;
    }
    else{
        if(_estado == -1){
            cout << "  RESERVA CANCELADA" << endl;
        }
        else{
            cout << "  RESERVA SIN CONFIRMAR" << endl;
        }
    }
}

void Reserva::mostrarEstado(){
    if(_estado == true){
        cout << "RESERVA CONFIRMADA" << endl;
    }
    else{
        if(_estado == -1){
            cout << "RESERVA CANCELADA" << endl;
        }
        else{
            cout << "RESERVA SIN CONFIRMAR" << endl;
        }
    }
}

int Reserva::getIdPnr(){
    return _idPnr;
}
Fecha Reserva::getFechaCompra(){
    return _fechaCompra;
}
Fecha Reserva::getFechaEmbarque(){
    return _fechaEmbarque;
}
float Reserva::getImporte(){
    return _importe;
}
int Reserva::getEstado(){
    return _estado;
}
int Reserva::getIdVuelo(){
    return _idVuelo;
}
char Reserva::getClase(){
    return _clase;
}
void Reserva::setIdPnr(int pnr){
    _idPnr = pnr;
}
void Reserva::setClase(char clase){
    _clase = clase;
}
void Reserva::setFechaCompra(Fecha fecha){
    _fechaCompra = fecha;
}
void Reserva::setFechaEmbarque(Fecha fecha){
    _fechaEmbarque = fecha;
}

void Reserva::setImporte(float importe){
    if(importe >= 0){
        _importe = importe;
    }
    else{
        _importe = 0;
    }
}

void Reserva::setIdVuelo(int vuelo){
    _idVuelo = vuelo;
}
void Reserva::setEstado(int estado){
    _estado = estado;
}
bool Reserva::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("reservas.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Reserva)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
void Reserva::grabarEnDisco(){
    FILE *p;
    p = fopen("reservas.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Reserva::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("reservas.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Reserva)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
