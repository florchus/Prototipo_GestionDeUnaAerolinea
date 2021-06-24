#include <iostream>
using namespace std;
#include <clocale>
#include "Persona.h"
#include "Fecha.h"
#include <cstring>
#include "rlutil.h"

Persona::Persona(){
    //ctor
}

void Persona::cargar(){
    cin.ignore();
    cout << "INGRESE EL DNI : " ;
    cin.getline(_dni,9);
    cout << "INGRESE EL NOMBRE : " ;
    cin.getline(_nombre,50);
    cout << "INGRESE EL APELLIDO : "  ;
    cin.getline(_apellido,50);
    cout << "INGRESE TELEFONO DE CONTACTO : " ;
    cin.getline(_telefono,11);
    cout << "INGRESE UN EMAIL DE CONTACTO : ";
    cin.getline(_email,20);
}
void Persona::mostrar(){
    for(int i=0; i<45; i++){
        gotoxy(38+i, 7);
        cout << "*";
        gotoxy(38+i, 20);
        cout << "*";
        if(i<14){
            gotoxy(38, 7+i);
            cout << "*";
            gotoxy(83, 7+i);
            cout << "*";
        }
    }

    gotoxy(40, 8); //(x,y)
    cout << "DNI : " << _dni << endl;
    gotoxy(40, 10);
    cout << "NOMBRE : " << _nombre << endl;
    gotoxy(40, 12);
    cout << "APELLIDO : " << _apellido << endl;
    gotoxy(40, 14);
    cout << "TELEFONO DE CONTACTO : " << _telefono << endl;
    gotoxy(40, 16);
    cout << "EMAIL DE CONTACTO : " << _email << endl;

}
char *Persona::getDni(){
    return _dni;
}
char *Persona::getNombre(){
    return _nombre;
}
char *Persona::getApellido(){
    return _apellido;
}
char *Persona::getTelefono(){
    return _telefono;
}
char *Persona::getEmail(){
    return _email;
}
void Persona::setDni(char *dni){
    strcpy(_dni, dni);
}
void Persona::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}
void Persona::setApellido(char *apellido){
    strcpy(_apellido, apellido);
}
void Persona::setTelefono(char *telefono){
    strcpy(_telefono, telefono);
}
void Persona::setEmail(char *email){
    strcpy(_email, email);
}
