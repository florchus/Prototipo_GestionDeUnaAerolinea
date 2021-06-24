#include <iostream>
#include <cstring>
#include "Asiento.h"
using namespace std;

void Asiento::cargar(){
    cout << "CLASE (1 PARA W - 0 PARA J):  ";
    cin >> _clase;
    cout << "FILA: ";
    cin >> _fila;
    cout << "COLUMNA: ";
    cin >> _columna;
    // preguntar si hay que pedir la matricula en esta instancia
}
void Asiento::mostrar(){
    cout << "CLASE:  " << _clase << endl;
    cout << "FILA: " << _fila << endl;
    cout << "COLUMNA: " << _columna << endl;
}
bool Asiento::getClase(){
    return _clase;
}

int Asiento::getFila(){
    return _fila;
}
int Asiento::getColumna(){
    return _columna;
}

void Asiento::setClase(bool clase){
    _clase = clase;
}
void Asiento::setFila(int fila){
    _fila = fila;
}
void Asiento::setColumna(int columna){
    _columna = columna;
}

void Asiento::setMatriculaAvion(char *matricula){
    strcpy(_matriculaAvion, matricula);
}

bool Asiento::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("asientos.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Asiento)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Asiento::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("asientos.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Asiento)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}

void Asiento::grabarEnDisco(){
    FILE *p;
    p = fopen("asientos.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
