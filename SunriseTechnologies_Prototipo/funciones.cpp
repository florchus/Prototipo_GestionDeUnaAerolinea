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
#include "Asiento.h"
#include <stdlib.h> //new y delete
#include <conio.h> //login para mostrar asteriscos
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

void leerPasw(char frase[]){
    int i=0;
    cout.flush();
    do{
        frase[i] = (unsigned char)getch();

        if(frase[i]!=8){ // no es retroceso
            cout << '*';  // muestra por pantalla
            i++;
        }
        else if(i>0){    // es retroceso y hay caracteres
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();
    }while(frase[i-1]!=13);  // si presiona ENTER
    frase[i-1] = NULL;
    cout << endl;
}

int login(){
    cls();
    char usu[10];
    char contra[5];
    cout << endl;
    cout << "  USUARIO: " ;
    cin.getline(usu, 10);
    Usuario reg;
    int pos = 0, con=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(reg.getId(), usu)==0){
            cout << "  CONTRASEÑA:" ;
            leerPasw(contra);
            if(strcmp(contra, "0000") == 0 ){
                cout << "  INGRESE LA NUEVA CONTRASEÑA: ";
                leerPasw(contra);
                //cin.getline(contra, 5);
                reg.setContrasenia(contra);
                reg.grabarEnDisco(pos-1);
                if(strcmp(reg.getContrasenia(), contra)==0){
                    return reg.getPermiso();
                }
            }
            else{
                if(strcmp(reg.getContrasenia(), contra)==0){
                    return reg.getPermiso();
                }
                else{
                    cout << "  CONTRASEÑA INCORRECTA." << endl;
                    while(con<2){
                        cout << "  REINGRESE CONTRASEÑA: ";
                        leerPasw(contra);
                        //cin.getline(contra, 5);
                        if(strcmp(reg.getContrasenia(), contra)==0){
                            return reg.getPermiso();
                        }
                        else{
                            con++;
                        }
                        if(con == 2 ){
                            setColor(RED);
                            cout << "  SE HA BLOQUEADO EL SISTEMA.";
                            resetColor();
                            anykey();
                            return -1;
                        }
                    }
                }
            }
        }
    }

    cout << "  USUARIO NO REGISTRADO. " << endl;
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
    int i = 0;
    gotoxy(2, 2);
    cout << "MATRICULA";
    gotoxy(14, 2);
    cout << "ID VUELO";
    gotoxy(26, 2);
    cout << "DESTINO";
    gotoxy(38, 2);
    cout << "FECHA DE EMBARQUE" ;
    gotoxy(60, 2);
    cout << "HORA ESTIMADA DE EMBARQUE ";
    gotoxy(95, 2);
    cout << "STD";
    gotoxy(105, 2);
    cout << "STA";
    gotoxy(115, 2);
    cout << "FECHA DE ATERRIZAJE";
    gotoxy(140, 2);
    cout << "ETD";
    gotoxy(150, 2);
    cout << "ETA";
    gotoxy(2, 3);
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------";

    while(reg.leerDeDisco(pos++)){
        gotoxy(2, 4 + i);
        cout << reg.getMatriculaAvion();
        gotoxy(14, 4 + i);
        cout << reg.getidVuelo();
        gotoxy(26, 4 + i);
        cout << reg.getCodigoDestino();
        gotoxy(38, 4 + i);
        reg.getFechaEmbarque().mostrar();
        gotoxy(60, 4 + i);
        reg.getHoraEmb().mostrar();
        gotoxy(95, 4 + i);
        reg.getStd().mostrar();
        gotoxy(105, 4 + i);
        reg.getSta().mostrar();
        gotoxy(115, 4 + i);
        reg.getFechaAterrizaje().mostrar();
        gotoxy(140, 4 + i);
        reg.getEtd().mostrar();
        gotoxy(150, 4 + i);
        reg.getEta().mostrar();
        i++;
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
    gotoxy(2, 2);
    cout << "CODIGO DESTINO";
    gotoxy(25, 2);
    cout << "PAIS";
    gotoxy(50, 2);
    cout << "CIUDAD";
    gotoxy(2, 3);
    cout << "-------------------------------------------------------------------";
    int i = 0;
    gotoxy(2, 4);
    cout << "BUE";
    gotoxy(25, 4);
    cout << "ARGENTINA";
    gotoxy(50, 4);
    cout << "BUENOS AIRES";
    while(reg.leerDeDisco(pos++)){
        if(reg.getEstado()==1){
            gotoxy(2, 5 + i);
            cout << reg.getCodigoDestino();
            gotoxy(25, 5 + i);
            cout << reg.getPais();
            gotoxy(50, 5 + i);
            cout << reg.getDestino();
            i++;
        }
    }
    cout << endl << endl;
}
void buscarVuelo(char * dest){
    Vuelo obj;
    int pos=0;
    gotoxy(2, 2);
    cout << "ID VUELO";
    gotoxy(25, 2);
    cout << "FECHA DE EMBARQUE" ;
    gotoxy(50, 2);
    cout << "HORARIO DE EMBARQUE" ;
    gotoxy(2, 3);
    cout << "-------------------------------------------------------------------";
    int i = 0;
    while(obj.leerDeDisco(pos++)){
        if(strcmp(dest,obj.getCodigoDestino())==0){
            gotoxy(2, 4 + i);
            cout << obj.getidVuelo();
            gotoxy(25, 4 + i);
            obj.getFechaEmbarque().mostrar();
            gotoxy(50, 4 + i);
            obj.getHoraEmb().mostrar();
            i++;
        }
    }
    cout << endl << endl;
}
void buscarVueloBue(char *partida){
    Vuelo obj;
    int pos=0;
    gotoxy(2, 2);
    cout << "ID VUELO";
    gotoxy(25, 2);
    cout << "FECHA DE EMBARQUE" ;
    gotoxy(50, 2);
    cout << "HORARIO DE EMBARQUE" ;
    gotoxy(2, 3);
    cout << "-------------------------------------------------------------------";
    int i = 0;
    while(obj.leerDeDisco(pos++)){
        if(strcmp(partida, obj.getCodigoPartida())==0 ){
            gotoxy(2, 4 + i);
            cout << obj.getidVuelo();
            gotoxy(25, 4 + i);
            obj.getFechaEmbarque().mostrar();
            gotoxy(50, 4 + i);
            obj.getHoraEmb().mostrar();
            i++;
        }
    }
}
void crearFlota(){
    Avion reg;
    reg.cargar();
    reg.grabarEnDisco();
}
void mostrarFlota(){
    Avion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
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
    reg.setDni(dni);
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
            reg.setClase(clase);
            auxPax.setDni(dni);
            auxPax.setIdPnr(pnr);
            auxPax.setEmbarco(0);
            auxPax.setKilos(0);
            auxPax.setFila(-1);
            auxPax.setColumna(-1);
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
                reservarAsiento(vuelo, clase); //DESCUENTA ASIENTO
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
    int pos=0, i=0;
    Reserva reg;
    gotoxy(2, 2);
    cout << "PNR";
    gotoxy(10, 2);
    cout << "FECHA DE COMPRA";
    gotoxy(28, 2);
    cout << "FECHA DE EMBARQUE";
    gotoxy(48, 2);
    cout << "IMPORTE" ;
    gotoxy(60, 2);
    cout << "ID VUELO";
    gotoxy(80, 2);
    cout << "ESTADO";
    gotoxy(2, 3);
    cout << "-------------------------------------------------------------------------------------------------";
    while(reg.leerDeDisco(pos++)){
        gotoxy(2, 4 + i);
        cout << reg.getIdPnr();
        gotoxy(10, 4 + i);
        reg.getFechaCompra().mostrar();
        gotoxy(28, 4 + i);
        reg.getFechaEmbarque().mostrar();
        gotoxy(48, 4 + i);
        cout << reg.getImporte();
        gotoxy(60, 4+i);
        cout << reg.getIdVuelo();
        gotoxy(80, 4 + i);
        reg.mostrarEstado();
        i++;
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
void mostrarPax2(char *dni){
    Pasajero reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(dni, reg.getDni()) == 0){
            reg.mostrar();
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
bool existePnr(int pnr){
    int pos=0;
    Reserva reg;
    while(reg.leerDeDisco(pos++)){
        if(pnr == reg.getIdPnr() ){
            return true;
        }
    }
    return false;
}
void listarReservasConfirmadas(){
    int pos=0, i=0;
    Reserva reg;
    gotoxy(2, 2);
    cout << "PNR";
    gotoxy(10, 2);
    cout << "FECHA DE COMPRA";
    gotoxy(28, 2);
    cout << "FECHA DE EMBARQUE";
    gotoxy(48, 2);
    cout << "IMPORTE" ;
    gotoxy(60, 2);
    cout << "ID VUELO";
    gotoxy(2, 3);
    cout << "----------------------------------------------------------------------------------------";
    while(reg.leerDeDisco(pos++)){
        if(reg.getEstado()==1){
            gotoxy(2, 4 + i);
            cout << reg.getIdPnr();
            gotoxy(10, 4 + i);
            reg.getFechaCompra().mostrar();
            gotoxy(28, 4 + i);
            reg.getFechaEmbarque().mostrar();
            gotoxy(48, 4 + i);
            cout << reg.getImporte();
            gotoxy(60, 4+i);
            cout << reg.getIdVuelo();
            i++;
        }
    }
}

//CHECKIN
bool tieneEquipaje(char *dni,int pnr){
    AuxiliarPasajero pax;
    int pos = 0;
    while(pax.leerDeDisco(pos++)){
        if(strcmp(pax.getDni(),dni)==0){
            if(pax.getIdPnr()==pnr){
                if(pax.getKilos()>0){
                    return true;
                }
            }
        }

    }
    return false;
}
void despacharValija(){
    AuxiliarPasajero aux;
    int pnr, pos = 0;
    float kilos;
    bool existe,valija;
    char dni[9];
    cout << "INGRESE PNR: ";
    cin >> pnr;
    existe = existePnr(pnr);
    while(existe == false){
        cout << "PNR INCORRECTO" << endl;
        cout << "REINGRESE PNR: ";
        cin >> pnr;
        existe = existePnr(pnr);
    }
    cin.ignore();
    cout << "INGRESE DNI: ";
    cin.getline(dni,9);
    existe = existePasajero(dni);
    while(existe == false){
        cin.ignore();
        cout << "DNI INCORRECTO" << endl;
        cout << "REINGRESE DNI: ";
        cin.getline(dni,9);
        existe = existePasajero(dni);
    }
    valija = tieneEquipaje(dni,pnr);
    if(valija == true){
        cout << "ESTE PASAJERO YA DESPACHO EQUIPAJE" << endl;
        return;
    }
    cout << "INGRESE LOS KILOS A DESPACHAR: ";
    cin >> kilos;
    while(aux.leerDeDisco(pos)){
        if(aux.getIdPnr()==pnr){
            if(strcmp(dni,aux.getDni())==0){
                aux.setKilos(kilos);
                aux.grabarEnDisco(pos);
                cout << kilos << endl;
            }
        }
        pos++;
    }
}
bool pnrConfirmada(int pnr){
    int pos=0;
    Reserva reg;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdPnr() == pnr){
            if(reg.getEstado()==1){
                return true;
        }
        }
    }
    return false;
}
int buscarVuelo(int pnr){
    Reserva reg;
    int idvuelo;
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        if(reg.getIdPnr()== pnr){
            return reg.getIdVuelo();
        }
        pos++;
    }
    return -1;
}
int capacidadMatriz(int vuelo ,char clase){
    Avion reg;
    Vuelo aux;
    char matricula[6];
    char claseAvion;
    int pos = 0;
    while(aux.leerDeDisco(pos)){
        if(aux.getidVuelo()== vuelo){
            strcpy(matricula,aux.getMatriculaAvion());
        }
        pos++;
    }
    pos = 0;
    while(reg.leerDeDisco(pos)){
        if(strcmp(matricula,reg.getMatricula())==0){
            switch (clase){
            case 'W':
                return reg.getCapacidadAsientosW();
                break;
            case 'J':
                return reg.getCapacidadAsientosJ();
                break;
            }

        }
        pos++;
    }
    return -1;

}
void mostrarMatriz(int **matriz, int filas, int columnas){
    for(int j=0;j<columnas;j++){
        cout <<"\t" << j+1;
    }
    cout << endl;
    for(int i=0;i<filas;i++){
        cout << i+1<< "\t";
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]==1){
                cout << "X" << "\t";
            }
            else{
                cout << "*" << "\t";
            }
        }
        cout << endl;
    }
}

int mapaDeAsientos(int vuelo, char clase){
    Asiento seat;
    Reserva reg;
    Vuelo aux;
    int cant;
    int pos = 0;
    //pasarlo a constante global, declaracion como puntero de puntero
    cant = capacidadMatriz(vuelo,clase);
    if(cant == -1){
        cout << "DATOS INCORRECTOS" << endl;
        return -1;
    }
    int filas, columnas;
    switch (cant){
    case 8:
        filas = 2;
        columnas = 4;
        break;
    case 88:
        filas = 22;
        columnas = 4;
        break;
    case 24:
        filas = 6;
        columnas = 4;
        break;
    case 248:
        filas = 62;
        columnas = 4;
        break;
    }
    //RESERVA DE MEMORIA
    int **matriz = new int*[filas];//reservo memoria para las filas
    for(int i=0;i<filas;i++){
        matriz[i]=new int[columnas];//reservando memoria para las columnas
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j] = 0;
        }

    }

    int fila,columna;
    while(seat.leerDeDisco(pos)){
        if(seat.getIdVuelo()==vuelo){
                if(seat.getClase()== clase){
                    fila = seat.getFila();
                    columna = seat.getColumna();
                    matriz[fila][columna]=1; //Te lee el archivo de asientos y te pone los ocupados en 1
                }
        }
        pos ++;
    }
    mostrarMatriz(matriz,filas,columnas);
    //Liberar Espacio
    for(int i=0;i<filas;i++){ //Borro por columnas
       delete[] matriz[i];
    }
    delete[]matriz;
    return filas;
}
char buscarClase(int pnr){
    Reserva reg;
    int pos = 0;
    cout << pnr << endl;
    while(reg.leerDeDisco(pos)){
        if(reg.getIdPnr()== pnr){
            return reg.getClase();
        }
        pos++;
    }
    return 'N';
}
void guardarAsientoenAux(char *dni,int pnr,int fila ,int columna){
    AuxiliarPasajero auxpax;
    int pos= 0;
    while(auxpax.leerDeDisco(pos)){
        if(auxpax.getIdPnr()== pnr){
            if(strcmp(dni,auxpax.getDni())==0){
                auxpax.setFila(fila-1);
                auxpax.setColumna(columna-1);
                auxpax.grabarEnDisco(pos);
            }
        }
        pos++;
    }
}
void guardarAsientoenAsiento(int vuelo ,char clase,int fila,int columna){
    Asiento seat;
    seat.setIdVuelo(vuelo);
    seat.setClase(clase);
    seat.setFila(fila-1);
    seat.setColumna(columna-1);
    seat.grabarEnDisco();
}
bool asientoDisponible(int vuelo,char clase,int fila,int columna,int cantFilas){
    Asiento seat;
    int pos = 0;
    while(seat.leerDeDisco(pos)){
        if(seat.getIdVuelo()== vuelo){
            if(seat.getClase()== clase){
                if(seat.getFila()==fila-1 && fila-1<cantFilas){
                    if(seat.getColumna()==columna-1 && columna-1<4){
                            return false; //asiento ocupado
                    }
                }
            }
        }
        pos++;
    }
    if(fila-1<cantFilas && columna-1<4){
        return true;//asiento disponible
    }
    else{
        return false; //matriz fuera de rango
    }
}
bool pasajeroYaIngresado(int pnr){
    AuxiliarPasajero reg;
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        if(pnr == reg.getIdPnr()){
            if(reg.getFila()==-1){
                if(reg.getColumna()==-1){
                    return true;
                }
            }
        }
        pos++;
    }
    return false;
}
void seleccionarAsiento(){
    AuxiliarPasajero auxpax;
    char dni[9];
    int pnr, vuelo,cantFilas;
    char clase;
    int pos = 0;
    bool existe,confirmada,disponible,asiento;
    cout << "INGRESE PNR: ";
    cin >> pnr;
    existe = existePnr(pnr);
    while(existe == false){
        cout << "PNR INCORRECTO" << endl;
        cout << "REINGRESE PNR: ";
        cin >> pnr;
        existe = existePnr(pnr);
    }
    cls();
    confirmada = pnrConfirmada(pnr);
    if(confirmada == true){
        mostrarPaxPorPnr(pnr);
    }
    else{
        cout << "RESERVA NO CONFIRMADA"<< endl;
        return;
    }
    cin.ignore();
    cout << "INGRESE EL DNI DEL PASAJERO: ";
    cin.getline(dni,9);
    existe = existePasajero(dni);
    while(existe == false){
        cout << "DNI INCORRECTO" << endl;
        cout << "REINGRESE DNI: ";
        cin.getline(dni,9);
        existe = existePasajero(dni);
    }
    asiento = pasajeroYaIngresado(pnr);
    if(asiento == false){
        cout << "ESTE PASAJERO YA TIENE ASIENTO ASIGNADO" << endl;
        return;
    }
    anykey();
    vuelo = buscarVuelo(pnr);
    clase = buscarClase(pnr);
    if(vuelo == -1){
        cout << "DATOS INCORRECTOS DE VUELO" << endl;
        return;
    }
    if(clase == 'N'){
        cout << "DATOS INCORRECTOS DE CLASE" << endl;
        return;
    }
    int fila,columna;
    cantFilas = mapaDeAsientos(vuelo,clase);
    cout << "INGRESAR FILA: ";
    cin >> fila;
    cout << "INGRESAR COLUMNA: ";
    cin >> columna;
    disponible = asientoDisponible(vuelo,clase,fila,columna,cantFilas);
    while(disponible == false){
        cout << "ASIENTO YA OCUPADO O FUERA DE RANGO" << endl;
        cout << "REINGRESAR FILA: ";
        cin >> fila;
        cout << "REINGRESAR COLUMNA: ";
        cin >> columna;
        disponible = asientoDisponible(vuelo,clase,fila,columna,cantFilas);
    }
    guardarAsientoenAux(dni,pnr,fila,columna);
    guardarAsientoenAsiento(vuelo,clase,fila,columna);
}
void mostrarInfoPnr(){
    AuxiliarPasajero auxPax;
    Reserva reg;
    int pos=0, pnr, opc;
    cls();
    cout << "INGRESE PNR: ";
    cin >> pnr;
    while(!existePnr(pnr)){
        cout << "PNR INEXISTENTE. DESEA CONTINUAR (SI = 1, NO = 0)?: ";
        cin >> opc;
        if(opc == 0){
            return;
        }
        cout << "REINGRESE PNR: ";
        cin >> pnr;
    }
    cls();

    cout << endl;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdPnr() == pnr ){
            reg.mostrar();
        }
    }
    pos = 0;
    while(auxPax.leerDeDisco(pos++)){
        if(auxPax.getIdPnr() == pnr){
            mostrarPax2(auxPax.getDni());
            auxPax.mostrar2();
        }
    }
}

void buscarNyA(char *nombre, char *apellido, char *dni){
    Pasajero pax;
    int pos=0;
    while(pax.leerDeDisco(pos++)){
        if(strcmp(dni, pax.getDni())==0){
            strcpy(nombre, pax.getNombre());
            strcpy(apellido, pax.getApellido());
        }
    }
}

bool existeCheckin(int pnr){
    AuxiliarPasajero reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(pnr  == reg.getIdPnr()){
            if(reg.getFila() == -1){
                return false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}
void imprimirBP(){
    int pnr, pos=0;
    char dni[9], nombre[50], apellido[50];
    bool existe;
    Reserva reg;
    AuxiliarPasajero aux;
    cout << "INGRESE RESERVA: ";
    cin >> pnr;
    existe = existePnr(pnr);
    while(existe == false){
        cout << "PNR INCORRECTO" << endl;
        cout << "REINGRESE PNR: ";
        cin >> pnr;
        existe = existePnr(pnr);
    }
    existe = existeCheckin(pnr);
    while(existe == false){
        cout << "  CHECKIN NO REALIZADO" << endl;
        return;
    }
    cin.ignore();
    cout << "INGRESE DNI: ";
    cin.getline(dni, 9);
    existe = existePasajero(dni);
    while(existe == false){
        cout << "DNI INCORRECTO" << endl;
        cout << "REINGRESE DNI: ";
        cin.getline(dni,9);
        existe = existePasajero(dni);
    }
    buscarNyA(nombre, apellido, dni);


    cls();
    gotoxy(50, 3);
    cout << "___  ____ ____ ____ ___  _ _  _ ____    ___  ____ ____ ____ ";
    gotoxy(50, 4);
    cout << "|__] |  | |__| |__/ |  \\ | |\\ | | __    |__] |__| [__  [__ ";
    gotoxy(50, 5);
    cout << "|__] |__| |  | |  \\ |__/ | | \\| |__]    |    |  | ___] ___] ";
    for(int i=0; i<80; i++){
        gotoxy(38+i, 2);
        cout << "*";
        gotoxy(38+i, 20);
        cout << "*";
    }
    for(int i=1; i<20; i++){
        gotoxy(38, i+1);
        cout << "*";
        gotoxy(118, i+1);
        cout << "*";
	}
	gotoxy(52, 10);
	cout << "NOMBRE: " << nombre << " " << apellido;
	gotoxy(52, 14);
	cout << "PNR: " << pnr;
	while(aux.leerDeDisco(pos++)){
        if(pnr == aux.getIdPnr()){
            if(strcmp(dni, aux.getDni())==0){
               gotoxy(80, 14);
               aux.mostrar3();
            }
        }
	}
	pos=0;
	int vuelo;
	while(reg.leerDeDisco(pos++)){
        if(pnr == reg.getIdPnr()){
            gotoxy(80, 10);
            cout << "FECHA: ";
            reg.getFechaEmbarque().mostrar();
            gotoxy(52, 18);
            setColor(RED);
            cout << "Nº VUELO: " << reg.getIdVuelo();
            vuelo = reg.getIdVuelo();
        }
	}
	Vuelo aux2;
	pos=0;
	while(aux2.leerDeDisco(pos++)){
        if(vuelo == aux2.getidVuelo()){
            gotoxy(80, 18);
            cout << "HORA DE EMBARQUE: ";
            aux2.getHoraEmb().mostrar();
        }
	}

}
// MENU REPORTES
int contPaxenAuxiliarPasajero(int pnr){
    AuxiliarPasajero auxPax;
    int cont=0, pos=0;
    while(auxPax.leerDeDisco(pos++)){
        if(auxPax.getIdPnr()==pnr){
            cont++;
        }
    }
    return cont;
}
int cantVueloPorDestino(char * codDestino){
    Vuelo reg;
    int pos=0, c=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(codDestino,reg.getCodigoDestino())== 0){
                c++;

        }
    }
    return c;


}
int contarPax(char *codDestino){
    Vuelo reg;
    Reserva aux;
    AuxiliarPasajero auxPax;
    int pos=0,i=0, cont=0;
    int *vecIdvuelo= NULL ;
    int cant=cantVueloPorDestino(codDestino);
    vecIdvuelo = new int [cant];
    if(vecIdvuelo==NULL){
        cout << "No hay memoria " << endl ;
        return -1;
    }
    while(reg.leerDeDisco(pos++)){
        if(strcmp(codDestino,reg.getCodigoDestino())== 0){
                vecIdvuelo[i]=reg.getidVuelo();
                i++;
        }
    }
    pos=0;
    while(aux.leerDeDisco(pos++)){
        int x;
        for(x=0;x<cant;x++){
            if(vecIdvuelo[x]==aux.getIdVuelo()){
                cont+=contPaxenAuxiliarPasajero(aux.getIdPnr());
            }
        }
    }
    delete vecIdvuelo;
    return cont;
}
void listarCantPaxPorDestino(){
    Destino reg;
    int pos=0, cantPax;
    while(reg.leerDeDisco(pos++)){
            cout << "DESTINO : " << reg.getDestino() << endl ;
                cantPax=contarPax(reg.getCodigoDestino());
                cout << "LA CANTIDAD DE PASAJEROS ES DE :" << cantPax << endl;
                cout << "--------------------------------" << endl ;
    }
}
bool existeVuelo(int numVuelo){
    Vuelo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(numVuelo==reg.getidVuelo()){
            return true;
        }
    }
    return false;
}
void listarCantPaxPorVuelo(){
    int numVuelo, pos=0, cont=0;
    Reserva reg;
    bool existe;
    cout << "INGRESE EL NUMERO DE VUELO : " ;
    cin >> numVuelo;
    existe=existeVuelo(numVuelo);
    if(existe==false){
        cout << "VUELO INEXISTENTE " << endl ;
        return;
    }
    while(reg.leerDeDisco(pos++)){
        if(numVuelo==reg.getIdVuelo()){
              cont+=contPaxenAuxiliarPasajero(reg.getIdPnr());
        }
    }
    cout << "EN EL VUELO " << numVuelo << " HAY : " << cont << " PASAJEROS " << endl ;

}
void mostrarVector(float *vec,int tam){
    int x;
    for(x=0;x<tam;x++){
        if(vec[x]>0){
            cout << "MES " << x+1 << ": $ " << vec[x] << endl ;
        }
    }
}
void balanceMensual(){
    int anio, pos=0 ;
    float vec[12] = {};
    Reserva reg;
    cout << "INGRESE EL AÑO : " ;
    cin >> anio;
    while(reg.leerDeDisco(pos++)){
        if(anio==reg.getFechaCompra().getAnio()){
            vec[reg.getFechaCompra().getMes()-1]+=reg.getImporte();
        }
    }
    mostrarVector(vec,12);
}

void balanceAnual(){
   int anio, pos=0 ;
    float acum = 0;
    Reserva reg;
    cout << "  INGRESE EL AÑO : " ;
    cin >> anio;
    while(reg.leerDeDisco(pos++)){
        if(anio==reg.getFechaCompra().getAnio()){
            acum+=reg.getImporte();
        }
    }
    cout << "  BALANCE TOTAL: $" << acum << endl;
}

float acuDestinoPorVuelo(int mes, int anio, int idvuelo){
    Reserva reg;
    int pos=0;
    float acu=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdVuelo()==idvuelo){
            if(reg.getFechaCompra().getAnio()==anio){
                if(reg.getFechaCompra().getMes()==mes){
                    acu+=reg.getImporte();
                }
            }
        }
    }
    return acu;
}

float acumRentabilidad(int mes,int anio, char *CodigoDestino){
    float acu=0;
    int pos=0;
    Vuelo aux;
    while(aux.leerDeDisco(pos++)){
           if(strcmp(aux.getCodigoDestino(),CodigoDestino)==0){
                acu+=acuDestinoPorVuelo(mes, anio, aux.getidVuelo());
           }
    }
    return acu;
}

void destinosMenosRentables(){
    int mes, anio;
    cout << "INGRESE AÑO: ";
    cin >> anio;
    while(anio<0){
        cout << "AÑO INCORRECTO. REINGRESE EL AÑO: ";
        cin >> anio;
    }
    cout << "INGRESE MES: ";
    cin >> mes;
    while(mes<1 && mes>12){
        cout << "MES INCORRECTO. REINGRESE EL MES: ";
        cin >> mes;
    }
    char codDestinoMin[4];
    float minimo, acum;
    Destino reg;
    char nombreDestino[50];
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        acum = acumRentabilidad(mes, anio, reg.getCodigoDestino()); //armar esta funcion
        if(pos == 0){
            minimo = acum;
            strcpy(codDestinoMin, reg.getCodigoDestino());
            strcpy(nombreDestino, reg.getDestino());
        }
        if(acum < minimo){
            minimo = acum;
            strcpy(codDestinoMin, reg.getCodigoDestino());
            strcpy(nombreDestino, reg.getDestino());
        }
        pos++;
    }
    cout << "EL DESTINO MENOS RENTABLE PARA EL MES " << mes << " ES: " << nombreDestino << endl;
    //VER DE AGREGAR EL NOMBRE COMPLETO DE DESTINO
}
int totalCapacidad(char *matricula){
    Avion reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        if(strcmp(reg.getMatricula(),matricula)==0){
            return reg.getCapacidadAsientosJ()+reg.getCapacidadAsientosW();
        }
    }
    return -1;
}
void porcentajeOcupaciondeVuelo(){
    AuxiliarAvion reg;
    Vuelo aux;
    int pos=0, idvuelo, cantTotalAsientos, cantAsientosLibres;
    float porcentaje;
    cout << "  INGRESE EL NÚMERO DE VUELO: " ;
    cin >> idvuelo;
    while(aux.leerDeDisco(pos++)){
        if(idvuelo==aux.getidVuelo()){
            cantTotalAsientos=totalCapacidad(aux.getMatriculaAvion());
        }
    }
    pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdVuelo()==idvuelo){
            cantAsientosLibres=reg.getCapacidadAsientosJ()+reg.getCapacidadAsientosW();
        }
    }
    porcentaje=(float)(cantTotalAsientos-cantAsientosLibres)*100/cantTotalAsientos;
    cout << "  EL PORCENTAJE DE OCUPACION PARA EL VUELO " << idvuelo << " ES : " << porcentaje << "%" << endl;
}

void destinoMasRentables(){
    int mes, anio;
    cout << "INGRESE AÑO: ";
    cin >> anio;
    while(anio<0){
        cout << "AÑO INCORRECTO. REINGRESE EL AÑO: ";
        cin >> anio;
    }
    cout << "INGRESE MES: ";
    cin >> mes;
    while(mes<1 && mes>12){
        cout << "MES INCORRECTO. REINGRESE EL MES: ";
        cin >> mes;
    }
    char codDestinoMaximo[4];
    float maximo, acum;
    Destino reg;
    char nombreDestino[50];
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        acum = acumRentabilidad(mes, anio, reg.getCodigoDestino()); //armar esta funcion
        if(pos == 0){
            maximo = acum;
            strcpy(codDestinoMaximo, reg.getCodigoDestino());
            strcpy(nombreDestino, reg.getDestino());
        }
        if(acum > maximo){
            maximo = acum;
            strcpy(codDestinoMaximo, reg.getCodigoDestino());
            strcpy(nombreDestino, reg.getDestino());
        }
        pos++;
    }
    cout << "EL DESTINO MÁS RENTABLE PARA EL MES " << mes << " ES: " << nombreDestino << endl;
}
int cantidadDestinos(){
    Destino reg;
    int pos = 0, cont=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getEstado()==1){
            cont++;
        }
    }
    return cont;
}
void leerDestino(Destino *codigoDest, int tam){
    Destino reg;
    int pos = 0, i = 0;
    while(i<tam){
        if(reg.leerDeDisco(i)){
            if(reg.getEstado() == 1){
                codigoDest[i].leerDeDisco(i);
            }
            i++;
        }
    }
}
void ponerEnCero(int *ocupa,int tam){
    for(int i=0;i<tam;i++){
        ocupa[i] = 0;
    }
}
int totLibres(int idvuelo){
    AuxiliarAvion reg;
    int pos = 0, cantAsientosLibres;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdVuelo()==idvuelo){
            cantAsientosLibres = reg.getCapacidadAsientosJ()+reg.getCapacidadAsientosW();
            return cantAsientosLibres;
        }
    }
}
int ocupDestinoPorVuelo(int idvuelo){
    Vuelo reg;
    int pos=0, capacidad, ocupacion;
    while(reg.leerDeDisco(pos++)){
        if(reg.getidVuelo() == idvuelo){
            capacidad = totalCapacidad(reg.getMatriculaAvion());
            ocupacion = capacidad - totLibres(idvuelo);
        }
    }
    return ocupacion;
}

void cargarOcupacion(int *ocupa,int tam, Destino *codigoDest, int anio){
    Vuelo aux;
    int pos = 0;
    int i;
    for(i=0; i<tam; i++){
        while(aux.leerDeDisco(pos++)){
            if(aux.getFechaEmbarque().getAnio() == anio){
                if(strcmp(codigoDest[i].getCodigoDestino(), aux.getCodigoDestino())==0){
                    ocupa[i]+= ocupDestinoPorVuelo(aux.getidVuelo());
                }
            }
        }
        pos = 0;
    }
}

void ordenarVector(Destino *codDestino,int tam ,int *ocupa){
    int i,j,posMax,aux2;
    for(i=0;i<tam;i++){
        posMax=i;
        for (j=i+1;j<tam;j++){
            if(ocupa[j]>ocupa[posMax]){
                posMax = j;
            }
        }
        Destino aux = codDestino[i];
        codDestino[i] = codDestino[posMax];
        codDestino[posMax] = aux;
        aux2 = ocupa[i];
        ocupa[i] = ocupa[posMax];
        ocupa[posMax] = aux2;
    }
}
void rankingMayorOcupa(){
    Destino *codigoDest;//guardo el codigo de destino
    int *ocupa;//guardo la ocupacion
    int anio,i;
    cout << "  INGRESE EL AÑO: ";
    cin >> anio;
    int cantreg = cantidadDestinos();
    codigoDest = new Destino[cantreg];
    ocupa = new int[cantreg];
    if(codigoDest == NULL){
        return;
    }
    if(ocupa == NULL){
        return;
    }
    leerDestino(codigoDest,cantreg);
    ponerEnCero(ocupa,cantreg);
    cargarOcupacion(ocupa,cantreg,codigoDest, anio);
    ordenarVector(codigoDest,cantreg,ocupa);
    for(i=0;i<5;i++){
        cout << "  " << i+1 << "  PUESTO: " << codigoDest[i].getCodigoDestino() << endl;
        cout << "  OCUPACION: " << ocupa[i] << endl;
        cout << "  ---------------------------------" << endl;
    }

    anykey();
    delete codigoDest;
    delete ocupa;
}

void ordenarVectorMenorAMayor(Destino *codDestino,int tam ,int *ocupa){
    int i,j,posMin,aux2;
    for(i=0;i<tam;i++){
        posMin=i;
        for (j=i+1;j<tam;j++){
            if(ocupa[j]<ocupa[posMin]){
                posMin = j;
            }
        }
        Destino aux = codDestino[i];
        codDestino[i] = codDestino[posMin];
        codDestino[posMin] = aux;
        aux2 = ocupa[i];
        ocupa[i] = ocupa[posMin];
        ocupa[posMin] = aux2;
    }
}


void rankingMenorOcupa(){
    Destino *codigoDest;//guardo el codigo de destino
    int *ocupa;//guardo la ocupacion
    int anio,i;
    cout << "  INGRESE EL AÑO: ";
    cin >> anio;
    int cantreg = cantidadDestinos();
    codigoDest = new Destino[cantreg];
    ocupa = new int[cantreg];
    if(codigoDest == NULL){
        return;
    }
    if(ocupa == NULL){
        return;
    }
    leerDestino(codigoDest,cantreg);
    ponerEnCero(ocupa,cantreg);
    cargarOcupacion(ocupa,cantreg,codigoDest, anio);
    ordenarVectorMenorAMayor(codigoDest,cantreg,ocupa);
    for(i=0;i<5;i++){
        cout << "  " << i+1 << "  PUESTO: " << codigoDest[i].getCodigoDestino() << endl;
        cout << "  OCUPACION: " << ocupa[i] << endl;
        cout << "  ---------------------------------" << endl;
    }

    anykey();
    delete codigoDest;
    delete ocupa;
}

float recaudaDestinoPorVuelo(int id){
    Reserva reg;
    int pos=0, recaudacion = 0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getIdVuelo() == id){
            recaudacion += reg.getImporte();
        }
    }
    return recaudacion;
}

void cargarRecaudacion(float *recauda, int tam, Destino *dest, int anio){
    Vuelo aux;
    int pos = 0;
    int i;
    for(i=0; i<tam; i++){
        while(aux.leerDeDisco(pos++)){
            if(aux.getFechaEmbarque().getAnio() == anio){
                if(strcmp(dest[i].getCodigoDestino(), aux.getCodigoDestino())==0){
                    recauda[i]+= recaudaDestinoPorVuelo(aux.getidVuelo());
                }
            }
        }
        pos = 0;
    }
}

void ponerEnCero(float *v,int tam){
    for(int i=0;i<tam;i++){
        v[i] = 0;
    }
}

void ordenarVector(Destino *codDestino,int tam ,float *recauda){
    int i,j,posMax,aux2;
    for(i=0;i<tam;i++){
        posMax=i;
        for (j=i+1;j<tam;j++){
            if(recauda[j]>recauda[posMax]){
                posMax = j;
            }
        }
        Destino aux = codDestino[i];
        codDestino[i] = codDestino[posMax];
        codDestino[posMax] = aux;
        aux2 = recauda[i];
        recauda[i] = recauda[posMax];
        recauda[posMax] = aux2;
    }
}

void rankingMayorRecaudacion(){
    Destino *codigoDest;//guardo el codigo de destino
    float *recauda;//guardo la ocupacion
    int anio,i;
    cout << "  INGRESE EL AÑO: ";
    cin >> anio;
    int cantreg = cantidadDestinos();
    codigoDest = new Destino[cantreg];
    recauda = new float[cantreg];
    if(codigoDest == NULL){
        return;
    }
    if(recauda == NULL){
        return;
    }
    leerDestino(codigoDest,cantreg);
    ponerEnCero(recauda,cantreg);
    cargarRecaudacion(recauda,cantreg,codigoDest, anio);
    ordenarVector(codigoDest,cantreg,recauda);
    for(i=0;i<5;i++){
        cout << "  " << i+1 << "  PUESTO: " << codigoDest[i].getCodigoDestino() << endl;
        cout << "  RECAUDACIÓN: " << recauda[i] << endl;
        cout << "  ---------------------------------" << endl;
    }

    anykey();
    delete codigoDest;
    delete recauda;
}
