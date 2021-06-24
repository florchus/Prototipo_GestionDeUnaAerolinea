#include <iostream>
#include <cstring>
#include <clocale>
#include "Usuario.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;


void Usuario::cargar(){
    cls();
    cout << "INGRESE EL NOMBRE DE USUARIO: ";
    cin.getline(_id, 10);
    cout << "INGRESE CONTRASEÑA: ";
    cin.getline(_contrasenia, 5);
    cout << "INGRESE EL TIPO DE PERMISO(1:SISTEMAS, 2:RESERVA, 3:CHECK-IN):";
    cin >> _permiso;
    while(_permiso!=1 && _permiso!=2 && _permiso!=3){
        cout << "PERMISO ERRONEO " << endl;
        cout << "REINGRESE EL TIPO DE PERMISO(1:SISTEMAS, 2:RESERVA, 3:CHECK-IN):";
        cin >> _permiso;
        cin.ignore();
    }
}

void Usuario::mostrar(){
    cout << "USUARIO   : " << _id << endl;
    cout << "CONTRASEÑA: " << _contrasenia<< endl;
    cout << "PERMISO   : " << _permiso << endl;
}
char *Usuario::getId(){
    return _id;
}
char *Usuario::getContrasenia(){
    return _contrasenia;
}
void Usuario::setId(char *id){
    strcpy(_id, id);
}
void Usuario::setContrasenia(char *contrasenia){
    strcpy(_contrasenia, contrasenia);
}
int Usuario::getPermiso(){
    return _permiso;
}
void  Usuario::setPermiso(int permiso){
    _permiso=permiso;
}

bool Usuario::grabarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("usuarios.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Usuario)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}

void Usuario::grabarEnDisco(){
    bool guardo;
    FILE *p;
    p = fopen("usuarios.dat", "ab");
    if( p == NULL ){
        return;
    }
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

bool Usuario::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("usuarios.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Usuario)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
