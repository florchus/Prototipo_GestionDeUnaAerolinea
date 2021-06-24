#include <iostream>
using namespace std;
#include <cstring>
#include <clocale>
#include "Usuario.h"
#include "funciones.h"
#include "rlutil.h"
#include "Pasajero.h"

using namespace rlutil;

void menuOperador(){
    int opcion, pos=0;
    Usuario usu;
    char nombre[10];
    bool grabo;
    do{
        cls();
        cout << "MENÚ OPERADOR" << endl;
        cout << "-------------" << endl;
        cout << "1-ALTA USUARIO" << endl;
        cout << "2-BLANQUEO DE USUARIO" << endl; //SETEAR 0000 Y VERIFICAR QUE SEA ASI, ENTONCES EL USUARIO INGRESA NUEVA CONTRASEÑA CON UN SETCONTRASENIA
        cout << "3-LISTAR USUARIO " << endl ; //Menu secreto
        cout << "0-SALIR" << endl;
        cout << "--> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            cin.ignore();
            usu.cargar();
            usu.grabarEnDisco();
            break;
        case 2:
            cin.ignore();
            cout << "INGRESE NOMBRE DE USUARIO: ";
            cin.getline(nombre, 10);
            while(usu.leerDeDisco(pos)){
                if(strcmp(nombre, usu.getId()) == 0){
                    usu.setContrasenia("0000");
                    grabo = usu.grabarEnDisco(pos);
                    cout << "USUARIO BLANQUEADO CORRECTAMENTE." << endl;
                }
                pos++;
            }
            break;
        case 3:
            listarUsuarios();
            break;
        case 0:
            cout << endl << endl;
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();
    } while (opcion !=0);
}


void menuDestinos(){
    int opcion;
    do{
        cls();
        cout << "MENÚ DESTINOS" << endl;
        cout << "-------------" << endl;
        cout << "1-ALTA DE DESTINOS" << endl;
        cout << "2-BAJA DE DESTINOS" << endl;
        cout << "3-ALTA LOGICA DE DESTINO" << endl;
        cout << "4-MODIFICACIÓN DE DESTINOS" << endl;
        cout << "5-LISTADO DE DESTINOS" << endl;
        cout << "0-SALIR" << endl;
        cout << "--> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            altaDestinos();
            break;
        case 2:
            bajaDestinos();
            break;
        case 3:
            altaLogicaDestino();
            break;
        case 4:
            modificarDestinos();
            break;
        case 5:
            listadoDestinos();
            break;
        case 0:
            cout << endl << endl;
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();
    } while (opcion != 0);
}

void menuVuelos(){
    int opcion;
    do{
        cls();
        cout << "MENÚ VUELOS" << endl;
        cout << "-----------" << endl;
        cout << "1-REGISTRAR VUELOS" << endl;
        cout << "2-MODIFICACIÓN DE VUELOS" << endl;
        cout << "3-LISTADO DE VUELOS" << endl;
        cout << "0-SALIR" << endl;
        cout << "--> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            altaVuelos();
            break;
        case 2:
            modificarVuelos();
            break;
        case 3:
            listadoVuelos();
            break;
        case 0:
            cout << endl << endl;
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }

    } while (opcion != 0);
}

void menuSistemas(){
    int opcion;
    do{
        cls();
        cout << "MENÚ SISTEMAS" << endl;
        cout << "-------------" << endl;
        cout << "1-OPERADOR" << endl;
        cout << "2-DESTINOS" << endl;
        cout << "3-VUELOS" << endl;
        cout << "0-SALIR" << endl;
        cout << "--> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            menuOperador();
            break;
        case 2:
            menuDestinos();
            break;
        case 3:
            menuVuelos();
            break;
        case 0:
            cout << "GRACIAS POR VISITAR SUNRISE TECHNOLOGIES.";
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();

    } while (opcion !=0);
}

void menuReserva(){
    int opcion;
    int vuelo, cantidad;
    char dest[4], partida[4];
    char dni[9];
    Pasajero reg;
    float precio;
    bool existe, confirmacion, asientoDisponible;
    char asiento;
    do{
        cls();
        cout << "MENÚ RESERVA" << endl;
        cout << "-------------" << endl;
        cout << "1-RESERVAR" << endl;
        cout << "2-CONFIRMAR RESERVA" << endl;
        cout << "3-CANCELAR RESERVA" << endl;
        cout << "4-REGISTRAR PASAJERO" << endl;
        cout << "5-LISTAR RESERVAS" << endl;
        cout << "6-BUSCAR RESERVA POR PNR" << endl;
        cout << "7-LISTAR CLIENTES" << endl;
        cout << "0-SALIR" << endl;
        cout << "--> ";
        cin >> opcion;
        switch (opcion){
        case 1:
            listaCiudades();
            cout << "INGRESE EL CODIGO DE DESTINO: "  ;
            cin.ignore();
            cin.getline(dest,4);
            cls();
            if(strcmp(dest, "BUE")==0){
                cout << "INGRESAR AEROPUERTO DE PARTIDA: ";
                cin.getline(partida,4);
                buscarVueloBue(partida);
                precio=buscarprecio(partida);
                cout << "INGRESE ID DE VUELO: " ;
                cin >> vuelo;
                mostrarCapacidadAsientos(vuelo);
                cout << "INGRESE LA CLASE DE ASIENTO: ";
                cin >> asiento;
                asientoDisponible = checkSeat(vuelo, asiento);
                while(asientoDisponible == false){
                    cout << "ASIENTOS INSUFICIENTES" << endl;
                    cout << "REINGRESE LA CLASE DE ASIENTO: ";
                    cin >> asiento;
                    asientoDisponible = checkSeat(vuelo, asiento);
                }
                cin.ignore();
                cout << "INGRESE DNI: ";
                cin.getline(dni, 9);
                existe = existePasajero(dni);
                if( existe == false ){
                    cout << "PASAJERO NO REGISTRADO " <<  endl;
                    break;
                }
                else{
                    generarReserva(dni,vuelo,precio, asiento);
                }
            }
            else{
                buscarVuelo(dest);
                precio=buscarprecio(dest);
                cout << "INGRESE ID DE VUELO: " ;
                cin >> vuelo;
                cin.ignore();
                cout << "INGRESE DNI: ";
                cin.getline(dni, 9);
                existe = existePasajero(dni);
                if( existe == false ){
                    cout << "PASAJERO NO REGISTRADO " <<  endl;
                    break;
                }
                else{
                    mostrarCapacidadAsientos(vuelo);
                    cout << "INGRESE LA CLASE DE ASIENTO: ";
                    cin >> asiento;
                    asientoDisponible = checkSeat(vuelo, asiento);
                    while(asientoDisponible == false){
                        cout << "ASIENTOS INSUFICIENTES" << endl;
                        cout << "REINGRESE LA CLASE DE ASIENTO: ";
                        cin >> asiento;
                        asientoDisponible = checkSeat(vuelo, asiento);
                    }
                    generarReserva(dni,vuelo,precio, asiento);
                }
            }
            break;
        case 2:
            confirmacion=confirmarReserva(1);
            if(confirmacion==1){
                cout << "RESERVA CONFIRMADA CON EXITO" << endl ;
            }
            else{
                cout << "RESERVA NO ENCONTRADA " << endl ;
            }
            break;
        case 3:
            confirmacion=confirmarReserva(-1);
            if(confirmacion==1){
                cout << "RESERVA CANCELADA CON EXITO" << endl ;
            }
            else{
                cout << "RESERVA NO ENCONTRADA " << endl ;
            }

            break;
        case 4:
            cin.ignore();
            cout << "INGRESE DNI: ";
            cin.getline(dni,9);
            existe = existePasajero(dni);
            if( existe == true ){
                cout << "PASAJERO REGISTRADO " <<  endl;
            }
            else{
                cargarPasajero(dni);
            }
            break;
        case 5:
            listarReservas();
            break;
        case 6:
            buscarReserva();
            break;
        case 7:
            listarClientes();
            break;
        case 0:
            cout << "GRACIAS POR VISITAR SUNRISE TECHNOLOGIES.";
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();

    } while (opcion !=0);


}

void menuCheckin(){
    cout << "MENU CHECK-IN";
    anykey();
}
