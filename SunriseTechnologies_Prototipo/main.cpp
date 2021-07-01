//Nombre: María Soledad Arena - Florencia Farias - Miguel Acosta
//TP Nº:
//EJ Nº:
/*Comentarios:
*/
#include <iostream>
#include <clocale>
#include "Usuario.h"
#include "funciones.h"
#include "menu.h"
#include "rlutil.h"
#include "Destino.h"
#include "AuxiliarAvion.h"
#include "Avion.h"
#include "Vuelo.h"
using namespace std;
using namespace rlutil;


int main(){
    saveDefaultColor();
	setlocale(LC_ALL, "Spanish");
//	Vuelo reg;
//	int pos =0;
//	int idvuelo = 1;
//	while(reg.leerDeDisco(pos)){
//        if(reg.getidVuelo() == idvuelo){
//            reg.setMatriculaAvion("LVAAA");
//            reg.grabarEnDisco(pos);
//        cout << "MATRICULA" << reg.getMatriculaAvion();
//        }
//        pos++;
//	}

//	AuxiliarAvion reg;
//	for(int i=0; i<417; i++){
//        reg.cargar();
//        reg.grabarEnDisco();
//	}
//	int pos=0;
//	while(reg.leerDeDisco(pos++)){
//        reg.mostrar();
//	}
//    anykey();
	setColor(WHITE);
    gotoxy(25,3);
    cout << "  ___   _   _   _  _   ___   ___   ___   ___     _____   ___    ___   _  _    ";
    gotoxy(25,4);
    cout << " / __| | | | | | \\| | | _ \\ |_ _| / __| | __|   |_   _| | __|  / __| | || |    ";
    gotoxy(25,5);
    cout << " \\__ \\ | |_| | | .` | |   /  | |  \\__ \\ | _|      | |   | _|  | (__  | __ |  _ ";
    gotoxy(25,6);
    cout << " |___/  \\___/  |_|\\_| |_|_\\ |___| |___/ |___|     |_|   |___|  \\___| |_||_| (_)";

    setColor(YELLOW);
    gotoxy(18,10);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,11);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,12);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,13);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,14);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,15);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,16);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,17);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,18);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,19);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,20);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,21);
    cout << "                                               ##                                                 " << endl;
    gotoxy(18,22);
    cout << "                                            /######\\                                              " << endl;
    gotoxy(18,23);
    cout << "                                           /########\\                                             " << endl;
    gotoxy(18,24);
    cout << "                                          /##########\\                                            " << endl;
    gotoxy(18,25);
    cout << "                                         /############\\                                           " << endl;
    gotoxy(18,26);
    cout << "                          .             /## ,      , ##\\                                          " << endl;
    gotoxy(18,27);
    cout << "                           i######:     ####        ####     :######i                             " << endl;
    gotoxy(18,28);
    cout << "                                .#########:##########:#########.                                  " << endl;
    gotoxy(18,29);
    cout << "#                                      ##################                                      #  " << endl;
    gotoxy(18,30);
    cout << "\\#                                     ########W#########                                     #/  " << endl;
    gotoxy(18,31);
    cout << "#############:.                        ##################                        .:############   " << endl;
    gotoxy(18,32);
    cout << "   iE######################################################################################Ei     " << endl;
    gotoxy(18,33);
    cout << "           .tK####################################################################Kt.             " << endl;
    gotoxy(18,34);
    cout << "                     ######################################################                       " << endl;
    gotoxy(18,35);
    cout << "                    #     #     ################################     #     #                      " << endl;
    gotoxy(18,36);
    cout << "                   # ##### #             ##############             # ##### #                     " << endl;
    gotoxy(18,37);
    cout << "                   # ## ## #              ############              # ## ## #                     " << endl;
    gotoxy(18,38);
    cout << "                   # ## ## #               ##########               # ## ## #                     " << endl;
    gotoxy(18,39);
    cout << "                   # ##### #                 ######                 # ##### #                     " << endl;
    gotoxy(18,40);
    cout << "                    # ### #                                          # ### #                      " << endl;
    gotoxy(18,41);
    cout << "                     #####                                            #####                       " << endl;
    cout << endl;
    for(int i=0; i<36; i++){
        gotoxy(10+3*i, 1);
        cout << "#~#";
        if(i<40){
            gotoxy(10+3*i, 43);
            cout << "#~#";
        }
	}
	for(int i=0; i<43; i++){
        gotoxy(10, i);
        cout << "#";
        gotoxy(119, i);
        cout << "#";
	}

    anykey();
    cls();
    int permiso, opcion =0;
    bool b = 0;
    setColor(WHITE);
    permiso = login();
    while(opcion == 0){
        cls();
        b=0;
        switch (permiso){
            case 1:
                setBackgroundColor(BLUE);
                menuSistemas();
                opcion =1;
                break;
            case 2:
                setBackgroundColor(GREEN);
                menuReserva();
                opcion =1;
                break;
            case 3:
                setBackgroundColor(DARKGREY);
                menuCheckin();
                opcion =1;
                break;
            case -1:
                resetColor();
                setColor(WHITE);
                cout << "  VUELVA A INGRESAR AL SISTEMA" << endl;
                anykey();
                permiso = login();
                b = 1;
                break;
        }
        setBackgroundColor(BLACK);
        cls();
        resetColor();
        setColor(WHITE);
        if(opcion == 1){
            cout << endl;
            cout << "  Desea ingresar otro usuario(Si=0/No=1)?";
            cin >> opcion;
        }
        if(opcion == 0 && b == 0){
            cin.ignore();
            permiso = login();
        }
    }
	return 0;
}
