#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Pasajero.h"
#include "Destino.h"

//MENU OPERADOR
void cargarUsuarios();

void leerPasw(char []);

int login();

void listarUsuarios(); // borrar

//MENU DESTINOS
void altaDestinos();

void altaLogicaDestino();

void bajaDestinos();

void modificarDestinos();

void listadoDestinos();

//MENU VUELOS
void listadoVuelos();

void modificarVuelos();

void altaVuelos();

//MENU FLOTA
void crearFlota();

void mostrarFlota();

//MENU RESERVAS
void listaCiudades();

void buscarVueloBue(char *);

float buscarprecio(char *);

void mostrarCapacidadAsientos(int );

bool checkSeat(int , char);

bool existePasajero(char *);

int generarPnr();

int calcularEdad(char *, Fecha);

void generarReserva(char *, int, float, char);

void buscarVuelo(char *);

bool confirmarReserva(int);

void reservarAsiento(int, char);

void cargarPasajero(char *);

void listarReservas();

void buscarReserva();

void mostrarPaxPorPnr(int);

void mostrarPax(char*);

void listarClientes();

//MENU CHECK IN

void mostrarPax2(char*);

void listarReservasConfirmadas();

void seleccionarAsiento();

bool existePnr(int );

char buscarClase(int);

void despacharValija();

bool tieneEquipaje(char *,int);

bool pnrConfirmada(int);

int buscarVuelo(int);

int capacidadMatriz(int,char);

void mostrarMatriz(int **, int, int);//cambie aca el prototipo

void guardarAsientoenAux(char *,int,int,int);

void guardarAsientoenAsiento(int ,char,int,int);

bool asientoDisponible(int ,char ,int ,int, int);

bool pasajeroYaIngresado(int);

int mapaDeAsientos(int, char);

void mostrarInfoPnr();

void mostrarMapaDeAsiento(int);

void imprimirBP();

void buscarNyA(char *, char *, char *);

bool existeCheckin(int);

// MENU REPORTES

void listarCantPaxPorDestino();

int contarPax(char *);

int cantVueloPorDestino(char *);

int contPaxenAuxiliarPasajero(int );

void listarCantPaxPorVuelo();

void existeVuelo(int);

void balanceMensual();

void mostrarVector(float *,int );

void balanceAnual();

void destinosMenosRentables();

float acumRentabilidad(int,int, char *);

void porcentajeOcupaciondeVuelo();

void destinoMasRentables();

void leerDestino(Destino *, int);

void ponerEnCero(int *,int);

int ocupDestinoPorVuelo(int );

int totLibres(int );

void cargarOcupacion(int *,int, Destino *, int);

void ordenarVector(Destino *,int ,int *);

void ordenarVectorMenorAMayor(Destino *,int ,int *);

void rankingMayorOcupa();

int cantidadDestinos();

void rankingMenorOcupa();

void cargarRecaudacion(float *,int, Destino *, int);

void rankingMayorRecaudacion();

float recaudaDestinoPorVuelo(int);

void ponerEnCero(float *,int);

void ordenarVector(Destino *, int, float *);







































#endif // FUNCIONES_H_INCLUDED
