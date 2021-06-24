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
using namespace std;
using namespace rlutil;


int main(){
    saveDefaultColor();
	setlocale(LC_ALL, "Spanish");

//	Destino reg;
//	int n=0;
//	while(reg.leerDeDisco(n++)){
//        cin.ignore();
//        reg.mostrar();
//        reg.grabarEnDisco();
//	}
//
//	cout << "fin";
    setColor(WHITE);
    int permiso, opcion =0;
    permiso = login();
    while(opcion == 0){
        cls();
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
                setBackgroundColor(LIGHTMAGENTA);
                menuCheckin();
                opcion =1;
                break;
            case -1:
                resetColor();
                cout << "VUELVA A INGRESAR AL SISTEMA" << endl;
                anykey();
                permiso = login();
                break;
        }
        setBackgroundColor(BLACK);
        cls();
        resetColor();
        setColor(WHITE);
        if(opcion == 1){
            cout << endl;
            cout << "Desea ingresar otro usuario(Si=0/No=1)?";
            cin >> opcion;
        }
        if(opcion == 0){
            cin.ignore();
            permiso = login();
        }
    }
	return 0;
}
