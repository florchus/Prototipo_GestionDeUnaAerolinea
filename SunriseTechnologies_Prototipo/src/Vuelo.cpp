#include <iostream>
#include <cstring>
using namespace std;
#include <clocale>
#include "Vuelo.h"
#include "Avion.h"

void Vuelo::cargar(){
    cout << "MATRICULA DEL AVION: ";
    cin.getline(_matriculaAvion,6);
    cout << "ID VUELO: " ;
    cin >> _idVuelo;
    cin.ignore();
    cout << "CODIGO DE AEROPUERTO PARTIDA: ";
    cin.getline(_codigoPartida,4);
    cout << "CODIGO DE AEROPUERTO DESTINO: ";
    cin.getline(_codigoDestino,4);
    cout << "FECHA DE EMBARQUE: " << endl ;
    _fechaEmbarque.cargar();
    cout << "HORA ESTIMADA DE EMBARQUE " << endl;
    cout << "-------------------------" << endl;
    _horaEmb.cargar();
    cout << "HORA PROGRAMADA DE PARTIDA: " << endl;
    cout << "-------------------------" << endl;
    _std.cargar();
    cout << "HORA PROGRAMADA DE ARRIBO: " << endl;
    cout << "-------------------------" << endl;
    _sta.cargar();
    cout << "FECHA DE ATERRIZAJE: " << endl;
    cout << "-------------------------" << endl;
    _fechaAterrizaje.cargar();
    cout << "HORA ESTIMADA DE PARTIDA " << endl;
    cout << "-------------------------" << endl;
    _etd.cargar();
    cout << "HORA ESTIMADA DE ARRIBO: " << endl;
    cout << "-------------------------" << endl;
    _eta.cargar();
}
void Vuelo::mostrar(){
    cout << "MATRICULA DEL AVION: " << _matriculaAvion << endl;
    cout << "ID VUELO: " << _idVuelo << endl;
    cout << "CODIGO DE DESTINO: " << _codigoDestino << endl;
    cout << "FECHA DE EMBARQUE: " ;
    _fechaEmbarque.mostrar();
    cout << "HORA ESTIMADA DE EMBARQUE " << endl;
    cout << "-------------------------" << endl;
    _horaEmb.mostrar();
    cout << "HORA PROGRAMADA DE PARTIDA: " << endl;
    cout << "-------------------------" << endl;
    _std.mostrar();
    cout << "HORA PROGRAMADA DE ARRIBO: " << endl;
    cout << "-------------------------" << endl;
    _sta.mostrar();
    cout << "FECHA DE ATERRIZAJE: " << endl;
    cout << "-------------------------" << endl;
    _fechaAterrizaje.mostrar();
    cout << "HORA ESTIMADA DE PARTIDA " << endl;
    cout << "-------------------------" << endl;
    _etd.mostrar();
    cout << "HORA ESTIMADA DE ARRIBO: " << endl;
    cout << "-------------------------" << endl;
    _eta.mostrar();
}

char *Vuelo::getMatriculaAvion(){
    return _matriculaAvion;
}
int Vuelo::getidVuelo(){
    return _idVuelo;
}
char *Vuelo::getCodigoDestino(){
    return _codigoDestino;
}
char *Vuelo::getCodigoPartida(){
    return _codigoPartida;
}

Fecha Vuelo::getFechaEmbarque(){
    return _fechaEmbarque;
}
Horario Vuelo::getHoraEmb(){
    return _horaEmb;
}
Horario Vuelo::getStd(){
    return _std;
}
Horario Vuelo::getSta(){
    return _sta;
}
Fecha Vuelo::getFechaAterrizaje(){
    return _fechaAterrizaje;
}
Horario Vuelo::getEta(){
    return _eta;
}
Horario Vuelo::getEtd(){
    return _etd;
}
void Vuelo::setMatriculaAvion(char *matricula){
    strcpy(_matriculaAvion,matricula);
}
void Vuelo::setIdVuelo(int idVuelo){
    _idVuelo = idVuelo;
}
void Vuelo::setCodigoDestino(char *codigo){
    strcpy(_codigoDestino,codigo);
}
void Vuelo::setCodigoPartida(char *codigo){
    strcpy(_codigoPartida,codigo);
}
void Vuelo::setFechaEmbarque(Fecha fechaEmbarque){
    _fechaEmbarque = fechaEmbarque;
}

void Vuelo::setHoraEmb(Horario horaEmb){
    _horaEmb = horaEmb;
}
void Vuelo::setStd(Horario std_){
    _std = std_;
}
void Vuelo::setSta(Horario sta){
    _sta = sta;
}
void Vuelo::setFechaAterrizaje(Fecha fechaAterrizaje){
    _fechaAterrizaje = fechaAterrizaje;
}
void Vuelo::setEta(Horario eta){
    _eta = eta;
}
void Vuelo::setEtd(Horario etd){
    _etd = etd;
}

bool Vuelo::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("vuelos.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Vuelo)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Vuelo::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("vuelos.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Vuelo)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

void Vuelo::grabarEnDisco(){
    bool guardo;
    FILE *p;
    p = fopen("vuelos.dat", "ab");
    if( p == NULL ){
        return;
    }
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
