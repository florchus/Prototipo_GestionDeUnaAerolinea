#include "rlutil.h"
#include <iostream>
#include <clocale>
#include "Usuario.h"
#include "Destino.h"
#include "Vuelo.h"
#include "Reserva.h"
#include "Pasajero.h"
#include "AuxiliarPasajero.h"
#include <cstring>
#include <ctime>
#include "AuxiliarAvion.h"
using namespace std;
using namespace rlutil;
void cargarUsuarios(){
    cls();
    Usuario reg;
    bool opc=1;
    while(opc){
        reg.cargar();
        reg.grabarEnDisco();
        cout << "DESEA CREAR UN NUEVO USUARIO(1:SI, 0:NO): ";
        cin >> opc;
        cin.ignore();
    }
}

int login(){
    cls();
    char usu[10];
    char contra[5];
    cout << "USUARIO: " ;
    cin.getline(usu, 10);
    Usuario reg;
    int pos = 0, con=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(reg.getId(), usu)==0){
            if(strcmp(reg.getContrasenia(), "0000") == 0 ){
                cout << "INGRESE LA NUEVA CONTRASEÑA: ";
                cin.getline(contra, 5);
                reg.setContrasenia(contra);
                reg.grabarEnDisco(pos-1);
                if(strcmp(reg.getContrasenia(), contra)==0){
                    return reg.getPermiso();
                }
            }
            else{
                cout << "CONTRASEÑA:" ;
                cin.getline(contra, 5);
                if(strcmp(reg.getContrasenia(), contra)==0){
                    return reg.getPermiso();
                }
                else{
                    cout << "CONTRASEÑA INCORRECTA." << endl;
                    while(con<2){
                        cout << "REINGRESE CONTRASEÑA: ";
                        cin.getline(contra, 5);
                        if(strcmp(reg.getContrasenia(), contra)==0){
                            return reg.getPermiso();
                        }
                        else{
                            con++;
                        }
                        if(con == 2 ){
                            setColor(RED);
                            cout << "SE HA BLOQUEADO EL SISTEMA.";
                            resetColor();
                            anykey();
                            return -1;
                        }
                    }
                }
            }
        }
    }

    cout << "USUARIO NO REGISTRADO. " << endl;
    anykey();

    return -1;
}

void altaDestinos(){
    cls();
    Destino des;
    cin.ignore();
    des.cargar();
    des.grabarEnDisco();
}

void bajaDestinos(){
    Destino reg;
    int pos=0;
    char dest[4];
    cin.ignore();
    cout << "INGRESE EL CODIGO DE DESTINO QUE QUIERA DAR DE BAJA : " ;
    cin.getline(dest,4);
    while(reg.leerDeDisco(pos)){
        if(strcmp(dest,reg.getCodigoDestino())==0){
            reg.setEstado(0);
            reg.grabarEnDisco(pos);
            return;
        }
        pos++;
    }
}
void altaLogicaDestino(){
    Destino reg;
    int pos=0;
    char dest[4];
    cin.ignore();
    cout << "INGRESE EL CODIGO DE DESTINO QUE QUIERA DAR DE ALTA : " ;
    cin.getline(dest,4);
    while(reg.leerDeDisco(pos)){
        if(strcmp(dest,reg.getCodigoDestino())==0){
            reg.setEstado(1);
            reg.grabarEnDisco(pos);
            return;
        }
        pos++;
    }
}

void modificarDestinos(){
    cls();
    int pos = 0;
    float precio;
    Destino reg;
    char nombre[4];
    cin.ignore();
    cout << "INGRESE CODIGO DESTINO A MODIFICAR: ";
    cin.getline(nombre, 4);
    cout << "INGRESE NUEVO PRECIO: ";
    cin >> precio;
    while(reg.leerDeDisco(pos)){
        if(strcmp(nombre, reg.getCodigoDestino()) == 0){
            reg.setPrecio(precio);
            reg.grabarEnDisco(pos);
            return;
        }
        pos++;
    }
}

void listadoDestinos(){
    cls();
    int pos=0;
    Destino reg;
    while(reg.leerDeDisco(pos++)){
        if(reg.getEstado() == 1){
            reg.mostrar();
        }
    }
    anykey();
}

void listadoVuelos(){
    cls();
    int pos=0;
    Vuelo reg;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
    }
    anykey();
}

void modificarVuelos(){}

void mostrarCapacidadAsientos(int vuelo){
    AuxiliarAvion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(vuelo == reg.getIdVuelo()){
            reg.mostrar();
        }
    }
}

void altaVuelos(){
    cls();
    Vuelo reg;
    cin.ignore();
    reg.cargar();
    reg.grabarEnDisco();
}
void listaCiudades(){
    Destino reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
            if(reg.getEstado()==1){
        cout << "CODIGO DESTINO : " << reg.getCodigoDestino() << endl ;
        cout << "PAIS : " << reg.getPais() << endl;
        cout << "CIUDAD : " << reg.getDestino() << endl;
        cout << "----------" << endl ;
        }
    }
}
void buscarVuelo(char * dest){
    Vuelo obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(strcmp(dest,obj.getCodigoDestino())==0){
            cout << "ID DE VUELO : " << obj.getidVuelo()<< endl ;
            cout << "FECHA DE EMBARQUE : " ;
            obj.getFechaEmbarque().mostrar();
            cout << "HORARIO DE EMBARQUE : " ;
            obj.getHoraEmb().mostrar();
            cout << "----------------------" << endl ;
        }
    }
}
void buscarVueloBue(char *partida){
    Vuelo obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(strcmp(partida, obj.getCodigoPartida())==0 ){
            cout << "ID DE VUELO : " << obj.getidVuelo()<< endl ;
            cout << "FECHA DE EMBARQUE : " ;
            obj.getFechaEmbarque().mostrar();
            cout << "HORARIO DE EMBARQUE : " ;
            obj.getHoraEmb().mostrar();
            cout << "----------------------" << endl ;
        }
    }
}
float buscarprecio(char * dest){
    Destino obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
       if(strcmp(dest,obj.getCodigoDestino())==0){
            return obj.getPrecio();
       }
    }
    return -1; //agrego por si no devuelve nada
}
int generarPnr(){
    Reserva reg;
    int pnr;
    FILE *p;
    p = fopen("reservas.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, -sizeof(Reserva), SEEK_END);
    if(fread(&reg, sizeof(Reserva), 1, p) == 0){
        pnr = 0;
    }
    else{
        pnr = reg.getIdPnr();
    }
    fclose(p);
    return pnr;
}
bool existePasajero(char *dni){
    int pos=0;
    Pasajero reg;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(dni, reg.getDni())==0){
            return true;
        }
    }
    return false;
}
void cargarPasajero(char *dni){
    Pasajero reg;
    reg.cargar();
    reg.grabarEnDisco();
}
int calcularEdad(char *dni, Fecha fechaSis){
    Pasajero reg;
    int pos=0, edad;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(dni,reg.getDni())==0){
            edad=fechaSis.getAnio()-reg.getNacimiento().getAnio();
            if(fechaSis.getMes()>reg.getNacimiento().getMes()){
                return edad;
            }
            else{
                if(fechaSis.getMes()<reg.getNacimiento().getMes()){
                    return edad-1;
                }
                else{
                    if(fechaSis.getDia()>=reg.getNacimiento().getDia()){
                        return edad;
                    }
                    else{
                        return edad-1;
                    }
                }
            }
           }
    }
}

bool checkSeat(int vuelo, char clase){
    AuxiliarAvion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(vuelo == reg.getIdVuelo()){
            switch (clase){
            case 'W':
                if( reg.getCapacidadAsientosW() > 0){
                    return true;
                }
                else{
                    return false;
                }
                break;
            case 'J':
                if( reg.getCapacidadAsientosJ() > 0){
                    return true;
                }
                else{
                    return false;
                }
                break;
            default:
                cout << "NO EXISTE LA CLASE INGRESADA" << endl;
                break;
            }

        }
    }
    return false;
}

void reservarAsiento(int vuelo, char clase){
    AuxiliarAvion reg;
    int pos=0, capacidad;
    while(reg.leerDeDisco(pos)){
        if(vuelo == reg.getIdVuelo()){
            switch (clase){
                case 'W':
                    capacidad = reg.getCapacidadAsientosW() - 1;
                    reg.setCapacidadAsientosW(capacidad);
                    reg.grabarEnDisco(pos);
                    break;
                case 'J':
                    capacidad = reg.getCapacidadAsientosJ() - 1;
                    reg.setCapacidadAsientosJ(capacidad);
                    reg.grabarEnDisco(pos);
                    break;
                default:
                    cout << "NO EXISTE LA CLASE INGRESADA" << endl;
                    break;

            }
        }
        pos++;
    }
}

void generarReserva(char *dni, int vuelo, float precio, char clase){
    Reserva reg;
    AuxiliarAvion auxAvion;
    Vuelo aux;
    Fecha fechaSis;
    AuxiliarPasajero auxPax; //auxPax = auxiliar pasajero--> PAX=Pasajero
    int pos=0, pnr;
    float con=0;
    int edad;
    bool pax, existe, asientoDisponible;
    char dniNuevo[9];
    Pasajero obj; //verificar si es mayor de edad con dni, y mirando fecha nacimiento. Crear variable aux para hacer un descuento si es menor de edad.
    time_t t;
    t = time(NULL);
    struct tm *f;
    f = localtime(&t);
    int _dia = f->tm_mday;
    int _mes = f->tm_mon + 1;
    int _anio = f->tm_year + 1900;
    fechaSis.setDia(_dia);
    fechaSis.setMes(_mes);
    fechaSis.setAnio(_anio);
    while(aux.leerDeDisco(pos++)){
        if(vuelo == aux.getidVuelo()){//verificar asientos disponibles
            reg.setFechaEmbarque(aux.getFechaEmbarque());
            pnr = generarPnr() + 1;
            reg.setIdVuelo(vuelo);
            reg.setIdPnr(pnr);
            reg.setEstado(0);
            reg.setFechaCompra(fechaSis);
            auxPax.setDni(dni);
            auxPax.setIdPnr(pnr);
            auxPax.setEmbarco(0);
            auxPax.setKilos(0);
            auxPax.grabarEnDisco();
            edad=calcularEdad(dni,fechaSis);
            if(edad>=12){
                con = precio;
            }
            else{
                con = precio*0.5;
            }
            if( clase == 'W'){
                con = con*1.5;
            }
            reservarAsiento(vuelo, clase);
            cout << "DESEA AGREGAR OTRO PASAJERO(Si=1/No=0)? ";
            cin >> pax;
            while( pax == 1 ){
                asientoDisponible = checkSeat(vuelo, clase);
                if(asientoDisponible == false ){
                    cout << "ASIENTOS INSUFICIENTES." << endl;
                    reg.setImporte(con);
                    reg.grabarEnDisco();
                    cout << "PNR CREADO CON EXITO" << endl;
                    cout << "PNR NUMERO: " << pnr << endl;
                    return;
                }
                cin.ignore();
                cout << "INGRESE DNI: ";
                cin.getline(dniNuevo, 9);
                existe = existePasajero(dniNuevo);
                if( existe == false ){
                    cout << "PASAJERO NO REGISTRADO " <<  endl;
                    cargarPasajero(dniNuevo);
                }
                auxPax.setDni(dniNuevo);
                auxPax.setIdPnr(pnr);
                auxPax.setEmbarco(0);
                auxPax.setKilos(0);
                edad=calcularEdad(dniNuevo,fechaSis);
                if(edad>=12){
                    if( clase == 'W'){
                        con += precio*1.5;
                    }
                    else{
                        con += precio;
                    }
                }
                else{
                    if( clase == 'W'){
                        con += precio;
                    }
                    else{
                        con += 0.5*precio;
                    }
                }
                reservarAsiento(vuelo, clase);
                auxPax.grabarEnDisco();
                cout << "DESEA AGREGAR OTRO PASAJERO(Si=1/No=0)? ";
                cin >> pax;
            }
            reg.setImporte(con);
            reg.grabarEnDisco();
            cout << "PNR CREADO CON EXITO" << endl;
            cout << "PNR NUMERO: " << pnr << endl;

        }
    }
}
bool confirmarReserva(int val){
    int pnr, pos=0;
    Reserva reg;
    cout << "INGRESE EL PNR : "  ;
    cin >> pnr;
    while(reg.leerDeDisco(pos)){
        if(pnr==reg.getIdPnr()){
            reg.setEstado(val);
            reg.grabarEnDisco(pos);
            return true;
        }
        pos++;
    }
    return false;
}
void listarReservas(){
    int pos=0;
    Reserva reg;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
    }
}
void mostrarPax(char *dni){
    Pasajero reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(dni, reg.getDni()) == 0){
            reg.mostrar();
            anykey();
            cls();
        }
    }
}
void mostrarPaxPorPnr(int pnr){
    AuxiliarPasajero reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(pnr == reg.getIdPnr()){
            mostrarPax(reg.getDni());
        }
    }
}
void buscarReserva(){
    int pnr, pos=0;
    Reserva reg;
    cout << "INGRESE EL PNR A BUSCAR: "  ;
    cin >> pnr;
    cls();
    while(reg.leerDeDisco(pos++)){
        if(pnr==reg.getIdPnr()){
            reg.mostrar();
            mostrarPaxPorPnr(pnr);
            return;
        }
    }
    cout << "PNR NO ENCONTRADO " << endl;
}
void listarUsuarios(){
    //borrar
    cls();
    Usuario reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
        cout <<  "--------"<< endl;
    }
    anykey();
}
void listarClientes(){
    Pasajero reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
        anykey();
        cls();
    }
}
