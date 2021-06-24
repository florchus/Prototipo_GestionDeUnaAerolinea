
#include <iostream>
using namespace std;

#include <clocale>
#include "Destino.h"
#include <cstring>
#include "Persona.h"
Destino::Destino(){
    //ctor
}

void Destino::cargar(){
    cout << "CODIGO DE DESTINO: ";
    cin.getline(_codigoDestino,4);
    cout << "DESTINO: " ;
    cin.getline(_destino, 50);
    cout << "PAÍS: " ;
    cin.getline(_pais, 50);
    cout << "PRECIO: " ;
    cin >> _precio;
    _estado=1; // Estado=1 destino activo - Estado=0 destino no activo
}
void Destino::mostrar(){
    cout << "CODIGO DESTINO: " << _codigoDestino << endl;
    cout << "DESTINO: " << _destino << endl;
    cout << "PAÍS   : " << _pais << endl;
    cout << "PRECIO : " << _precio << endl;
    cout << "-------  " << endl;
}
char *Destino::getDestino(){
    return _destino;
}
float Destino::getPrecio(){
    return _precio;
}
char *Destino::getPais(){
    return _pais;
}
char *Destino::getCodigoDestino(){
    return _codigoDestino;
}
bool Destino::getEstado(){
    return _estado;
}
void Destino::setDestino(char *destino){
    strcpy(_destino, destino);
}
void Destino::setPrecio(float precio){
    if(precio >= 0){
        _precio = precio;
    }
    else{
        _precio = 0;
    }
}
void Destino::setPais(char *pais){
    strcpy(_pais, pais);
}
void Destino::setCodigoDestino(char *destino){
    strcpy(_codigoDestino, destino);
}
void Destino::setEstado(bool estado){
    _estado=estado;
}
bool Destino::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("destinos.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Destino)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Destino::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("destinos.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Destino)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void Destino::grabarEnDisco(){
    FILE *p;
    p = fopen("destinos.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
