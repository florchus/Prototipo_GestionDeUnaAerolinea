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
        gotoxy(4, 4);
        cout << "MENÚ OPERADOR" << endl;
        gotoxy(4, 5);
        cout << "-------------" << endl;
        gotoxy(4, 6);
        cout << "1-ALTA USUARIO" << endl;
        gotoxy(4, 7);
        cout << "2-BLANQUEO DE USUARIO" << endl; //SETEAR 0000 Y VERIFICAR QUE SEA ASI, ENTONCES EL USUARIO INGRESA NUEVA CONTRASEÑA CON UN SETCONTRASENIA
        gotoxy(4, 8);
        cout << "3-LISTAR USUARIO " << endl ; //Menu secreto
        gotoxy(4, 9);
        cout << "0-SALIR" << endl;
        gotoxy(4, 10);
        cout << "--> ";
        gotoxy(8, 10);
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
        gotoxy(4, 4);
        cout << "MENÚ DESTINOS" << endl;
        gotoxy(4, 5);
        cout << "-------------" << endl;
        gotoxy(4, 6);
        cout << "1-ALTA DE DESTINOS" << endl;
        gotoxy(4, 7);
        cout << "2-BAJA DE DESTINOS" << endl;
        gotoxy(4, 8);
        cout << "3-ALTA LOGICA DE DESTINO" << endl;
        gotoxy(4, 9);
        cout << "4-MODIFICACIÓN DE DESTINOS" << endl;
        gotoxy(4, 10);
        cout << "5-LISTADO DE DESTINOS" << endl;
        gotoxy(4, 11);
        cout << "0-SALIR" << endl;
        gotoxy(4, 12);
        cout << "--> ";
        gotoxy(8, 12);
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
        gotoxy(4, 4);
        cout << "MENÚ VUELOS" << endl;
        gotoxy(4, 5);
        cout << "-----------" << endl;
        gotoxy(4, 6);
        cout << "1-REGISTRAR VUELOS" << endl;
        gotoxy(4, 7);
        cout << "2-MODIFICACIÓN DE VUELOS" << endl;
        gotoxy(4, 8);
        cout << "3-LISTADO DE VUELOS" << endl;
        gotoxy(4, 9);
        cout << "0-SALIR" << endl;
        gotoxy(4, 10);
        cout << "--> ";
        gotoxy(8, 12);
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

void menuReportes(){
    int opcion;
    do{
        cls();
        gotoxy(4, 4);
        cout << "MENÚ REPORTES" << endl;
        gotoxy(4, 5);
        cout << "-----------" << endl;
        gotoxy(4, 6);
        cout << "1-LISTADO POR PNR" << endl;
        gotoxy(4, 7);
        cout << "2-LISTADO CANTIDAD PASAJEROS POR DESTINO" << endl;
        gotoxy(4, 8);
        cout << "3-LISTADO CANTIDAD DE PASAJEROS POR VUELO" << endl;
        gotoxy(4, 9);
        cout << "4-BALANCE DE RECAUDACIÓN MENSUAL" << endl;
        gotoxy(4, 10);
        cout << "5-BALANCE DE RECAUDACIÓN ANUAL" << endl;
        gotoxy(4, 11);
        cout << "6-DESTINO MENOS RENTABLE POR MES" << endl;
        gotoxy(4, 12);
        cout << "7-PORCENTAJE DE OCUPACIÓN POR VUELO" << endl;
        gotoxy(4, 13);
        cout << "8-DESTINO MÁS RENTABLE POR MES" << endl;
        gotoxy(4, 14);
        cout << "9-RANKING DE LOS 5 DESTINOS CON MAYOR OCUPACIÓN ANUAL" << endl;
        gotoxy(4, 15);
        cout << "10-RANKING DE LOS 5 DESTINOS CON MENOR OCUPACIÓN ANUAL" << endl;
        gotoxy(4, 16);
        cout << "11-RANKING DE LOS 5 DESTINOS CON MAYOR RECAUDACIÓN ANUAL " << endl;
        gotoxy(4, 17);
        cout << "0-SALIR" << endl;
        gotoxy(4, 18);
        cout << "--> ";
        gotoxy(8, 18);
        cin >> opcion;
        cls();
        switch (opcion){
            case 1:
                listarReservas();
                break;
            case 2:
                listarCantPaxPorDestino();
                break;
            case 3:
                listarCantPaxPorVuelo();
                break;
            case 4:
                balanceMensual();
                break;
            case 5:
                balanceAnual();
                break;
            case 6:
                destinosMenosRentables();
                break;
            case 7:
                porcentajeOcupaciondeVuelo();
                break;
            case 8:
                destinoMasRentables();
                break;
            case 9:
                rankingMayorOcupa();
                break;
            case 10:
                rankingMenorOcupa();
                break;
            case 11:
                rankingMayorRecaudacion();
                break;
           case 0:
                cout << endl << endl;
                break;
            default:
                cout << "OPCIÓN INCORRECTA.";
                break;
       }
      anykey();
    } while (opcion);
}

void menuSistemas(){
    int opcion;
    do{
        cls();
        gotoxy(4, 4);
        cout << "MENÚ SISTEMAS" << endl;
        gotoxy(4, 5);
        cout << "-------------" << endl;
        gotoxy(4, 6);
        cout << "1-OPERADOR" << endl;
        gotoxy(4, 7);
        cout << "2-DESTINOS" << endl;
        gotoxy(4, 8);
        cout << "3-VUELOS" << endl;
        gotoxy(4, 9);
        cout << "4-CREAR FLOTA DE AVIONES" << endl;
        gotoxy(4, 10);
        cout << "5-MOSTRAR FLOTA" << endl;
        gotoxy(4, 11);
        cout << "6-REPORTES" << endl;
        gotoxy(4, 12);
        cout << "0-SALIR" << endl;
        gotoxy(4, 13);
        cout << "--> ";
        gotoxy(8, 13);
        cin >> opcion;
        cls();
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
        case 4:
            crearFlota();
            break;
        case 5:
            mostrarFlota();
            break;
        case 6:
            menuReportes();
            break;
        case 0:
            setColor(WHITE);
            gotoxy(10, 10);
            cout << "____ ____ ____ ____ _ ____ ____ ";
            gotoxy(10, 11);
            cout << "| __ |__/ |__| |    | |__| [__   ";
            gotoxy(10, 12);
            cout << "|__] |  \\ |  | |___ | |  | ___]  ";
            msleep(50);
            gotoxy(10, 13);
            cout << "        ___  ____ ____ ";
            gotoxy(10, 14);
            cout << "        |__] |  | |__/ ";
            gotoxy(10, 15);
            cout << "        |    |__| |  \\ ";
            msleep(50);
            gotoxy(10, 16);
            cout << "            _  _ _ ____ _ ___ ____ ____ ";
            gotoxy(10, 17);
            cout << "            |  | | [__  |  |  |__| |__/ ";
            gotoxy(10, 18);
            cout << "             \\/  | ___] |  |  |  | |  \\ ";
            msleep(50);
            gotoxy(10, 19);
            cout << "                    ____ _  _ _  _ ____ _ ____ ____ ";
            gotoxy(10, 20);
            cout << "                    [__  |  | |\\ | |__/ | [__  |___ ";
            gotoxy(10, 21);
            cout << "                    ___] |__| | \\| |  \\ | ___] |___ ";
            msleep(50);
            gotoxy(10, 22);
            cout << "                            ___ ____ ____ _  _ _  _ ____ _    ____ ____ _ ____ ____ ";
            gotoxy(10, 23);
            cout << "                             |  |___ |    |__| |\\ | |  | |    |  | | __ | |___ [__  ";
            gotoxy(10, 24);
            cout << "                             |  |___ |___ |  | | \\| |__| |___ |__| |__] | |___ ___] ";

            for(int i=0; i<30; i++){
                gotoxy(80+i, 40-i);
                cout << "            ####                  ";
                gotoxy(80+i, 41-i);
                cout << "             ####                 ";
                gotoxy(80+i, 42-i);
                cout << "             #####                ";
                gotoxy(80+i, 43-i);
                cout << "              ######              ";
                gotoxy(80+i, 44-i);
                cout << "               ######        ###  ";
                gotoxy(80+i, 45-i);
                cout << "               #######   #########";
                gotoxy(80+i, 46-i);
                cout << "                ###  #############";
                gotoxy(80+i, 47-i);
                cout << "                 ################ ";
                gotoxy(80+i, 48-i);
                cout << "    ###       ################    ";
                gotoxy(80+i, 49-i);
                cout << "     #### ################        ";
                gotoxy(80+i, 50-i);
                cout << "     #################            ";
                gotoxy(80+i, 51-i);
                cout << "      ##########                  ";
                gotoxy(80+i, 52-i);
                cout << "       ##:                        ";
                gotoxy(80+i, 53-i);
                cout << "                                  ";
                msleep(50);
            }
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
        gotoxy(4, 4);
        cout << "MENÚ RESERVA" << endl;
        gotoxy(4, 5);
        cout << "-------------" << endl;
        gotoxy(4, 6);
        cout << "1-RESERVAR" << endl;
        gotoxy(4, 7);
        cout << "2-CONFIRMAR RESERVA" << endl;
        gotoxy(4, 8);
        cout << "3-CANCELAR RESERVA" << endl;
        gotoxy(4, 9);
        cout << "4-REGISTRAR PASAJERO" << endl;
        gotoxy(4, 10);
        cout << "5-LISTAR RESERVAS" << endl;
        gotoxy(4, 11);
        cout << "6-BUSCAR RESERVA POR PNR" << endl;
        gotoxy(4, 12);
        cout << "7-LISTAR CLIENTES" << endl;
        gotoxy(4, 13);
        cout << "0-SALIR" << endl;
        gotoxy(4, 14);
        cout << "--> ";
        gotoxy(8, 14);
        cin >> opcion;
        cls();
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
            setColor(WHITE);
            gotoxy(10, 10);
            cout << "____ ____ ____ ____ _ ____ ____ ";
            gotoxy(10, 11);
            cout << "| __ |__/ |__| |    | |__| [__   ";
            gotoxy(10, 12);
            cout << "|__] |  \\ |  | |___ | |  | ___]  ";
            msleep(50);
            gotoxy(10, 13);
            cout << "        ___  ____ ____ ";
            gotoxy(10, 14);
            cout << "        |__] |  | |__/ ";
            gotoxy(10, 15);
            cout << "        |    |__| |  \\ ";
            msleep(50);
            gotoxy(10, 16);
            cout << "            _  _ _ ____ _ ___ ____ ____ ";
            gotoxy(10, 17);
            cout << "            |  | | [__  |  |  |__| |__/ ";
            gotoxy(10, 18);
            cout << "             \\/  | ___] |  |  |  | |  \\ ";
            msleep(50);
            gotoxy(10, 19);
            cout << "                    ____ _  _ _  _ ____ _ ____ ____ ";
            gotoxy(10, 20);
            cout << "                    [__  |  | |\\ | |__/ | [__  |___ ";
            gotoxy(10, 21);
            cout << "                    ___] |__| | \\| |  \\ | ___] |___ ";
            msleep(50);
            gotoxy(10, 22);
            cout << "                            ___ ____ ____ _  _ _  _ ____ _    ____ ____ _ ____ ____ ";
            gotoxy(10, 23);
            cout << "                             |  |___ |    |__| |\\ | |  | |    |  | | __ | |___ [__  ";
            gotoxy(10, 24);
            cout << "                             |  |___ |___ |  | | \\| |__| |___ |__| |__] | |___ ___] ";

            for(int i=0; i<30; i++){
                gotoxy(80+i, 40-i);
                cout << "            ####                  ";
                gotoxy(80+i, 41-i);
                cout << "             ####                 ";
                gotoxy(80+i, 42-i);
                cout << "             #####                ";
                gotoxy(80+i, 43-i);
                cout << "              ######              ";
                gotoxy(80+i, 44-i);
                cout << "               ######        ###  ";
                gotoxy(80+i, 45-i);
                cout << "               #######   #########";
                gotoxy(80+i, 46-i);
                cout << "                ###  #############";
                gotoxy(80+i, 47-i);
                cout << "                 ################ ";
                gotoxy(80+i, 48-i);
                cout << "    ###       ################    ";
                gotoxy(80+i, 49-i);
                cout << "     #### ################        ";
                gotoxy(80+i, 50-i);
                cout << "     #################            ";
                gotoxy(80+i, 51-i);
                cout << "      ##########                  ";
                gotoxy(80+i, 52-i);
                cout << "       ##:                        ";
                gotoxy(80+i, 53-i);
                cout << "                                  ";
                msleep(50);
            }
            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();

    } while (opcion !=0);


}

void menuCheckin(){
    int opcion;
    do{
        cls();
        gotoxy(4, 4);
        cout << "MENÚ CHECK IN" << endl;
        gotoxy(4, 5);
        cout << "-------------" << endl;
        gotoxy(4, 6);
        cout << "1-LISTAR RESERVAS CONFIRMADAS" << endl;
        gotoxy(4, 7);
        cout << "2-SELECCIONAR ASIENTO" << endl; //ACA MUESTRA MAPA DE ASIENTO
        gotoxy(4, 8);
        cout << "3-MOSTRAR MAPA DE ASIENTO" << endl;
        gotoxy(4, 9);
        cout << "4-DESPACHAR VALIJA" << endl;
        gotoxy(4, 10);
        cout << "5-MOSTRAR INFORMACION DEL PNR" << endl;
        gotoxy(4, 11);
        cout << "6-IMPRIMIR BOARDING PASS" << endl;
        gotoxy(4, 12);
        cout << "0-SALIR" << endl;
        gotoxy(4, 13);
        cout << "--> ";
        gotoxy(8, 13);
        cin >> opcion;
        cls();
        switch (opcion){
        case 1:
            listarReservasConfirmadas();
            break;
        case 2:
            seleccionarAsiento();

            break;
        case 3:
            int vuelo;
            char clase;
            cout << "INGRESE NUMERO DE VUELO: ";
            cin >> vuelo;
            cout << "INGRESE LA CLASE: ";
            cin >> clase;
            mapaDeAsientos(vuelo,clase);
            break;
        case 4:
            despacharValija();
            break;
        case 5:
            mostrarInfoPnr();
            break;
        case 6:
            imprimirBP();
            setColor(WHITE);
            break;
        case 0:
            setColor(WHITE);
            gotoxy(10, 10);
            cout << "____ ____ ____ ____ _ ____ ____ ";
            gotoxy(10, 11);
            cout << "| __ |__/ |__| |    | |__| [__   ";
            gotoxy(10, 12);
            cout << "|__] |  \\ |  | |___ | |  | ___]  ";
            msleep(50);
            gotoxy(10, 13);
            cout << "        ___  ____ ____ ";
            gotoxy(10, 14);
            cout << "        |__] |  | |__/ ";
            gotoxy(10, 15);
            cout << "        |    |__| |  \\ ";
            msleep(50);
            gotoxy(10, 16);
            cout << "            _  _ _ ____ _ ___ ____ ____ ";
            gotoxy(10, 17);
            cout << "            |  | | [__  |  |  |__| |__/ ";
            gotoxy(10, 18);
            cout << "             \\/  | ___] |  |  |  | |  \\ ";
            msleep(50);
            gotoxy(10, 19);
            cout << "                    ____ _  _ _  _ ____ _ ____ ____ ";
            gotoxy(10, 20);
            cout << "                    [__  |  | |\\ | |__/ | [__  |___ ";
            gotoxy(10, 21);
            cout << "                    ___] |__| | \\| |  \\ | ___] |___ ";
            msleep(50);
            gotoxy(10, 22);
            cout << "                            ___ ____ ____ _  _ _  _ ____ _    ____ ____ _ ____ ____ ";
            gotoxy(10, 23);
            cout << "                             |  |___ |    |__| |\\ | |  | |    |  | | __ | |___ [__  ";
            gotoxy(10, 24);
            cout << "                             |  |___ |___ |  | | \\| |__| |___ |__| |__] | |___ ___] ";

            for(int i=0; i<30; i++){
                gotoxy(80+i, 40-i);
                cout << "            ####                  ";
                gotoxy(80+i, 41-i);
                cout << "             ####                 ";
                gotoxy(80+i, 42-i);
                cout << "             #####                ";
                gotoxy(80+i, 43-i);
                cout << "              ######              ";
                gotoxy(80+i, 44-i);
                cout << "               ######        ###  ";
                gotoxy(80+i, 45-i);
                cout << "               #######   #########";
                gotoxy(80+i, 46-i);
                cout << "                ###  #############";
                gotoxy(80+i, 47-i);
                cout << "                 ################ ";
                gotoxy(80+i, 48-i);
                cout << "    ###       ################    ";
                gotoxy(80+i, 49-i);
                cout << "     #### ################        ";
                gotoxy(80+i, 50-i);
                cout << "     #################            ";
                gotoxy(80+i, 51-i);
                cout << "      ##########                  ";
                gotoxy(80+i, 52-i);
                cout << "       ##:                        ";
                gotoxy(80+i, 53-i);
                cout << "                                  ";
                msleep(50);
            }

            break;
        default:
            cout << "OPCIÓN INCORRECTA.";
            break;
        }
        anykey();


    } while (opcion!=0);
    anykey();
}
