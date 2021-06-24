#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Pasajero.h"

void cargarUsuarios();

int login();

void altaDestinos();

void altaLogicaDestino();

void bajaDestinos();

void modificarDestinos();

void listadoDestinos();

void listadoVuelos();

void modificarVuelos();

void altaVuelos();

void listaCiudades();

void buscarVuelo(char *);

void buscarVueloBue(char *);

float buscarprecio(char *);

void reservarAsiento(int, char);

void generarReserva(char *, int, float, char);

bool existePasajero(char *);

void cargarPasajero(char *);

int generarPnr();

bool confirmarReserva(int);

void listarReservas();

void buscarReserva();

void listarUsuarios(); // borrar

void mostrarPaxPorPnr(int);

void mostrarPax(char*);

int calcularEdad(char *, Fecha);

void mostrarCapacidadAsientos(int );

bool checkSeat(int , char);

void listarClientes();

#endif // FUNCIONES_H_INCLUDED
