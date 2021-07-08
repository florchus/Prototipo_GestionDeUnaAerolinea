#ifndef ASIENTO_H
#define ASIENTO_H
#include "Vuelo.h"

class Asiento{
    private:
        char _clase; //si es W (1) o J (0)
        int _fila;
        int _columna;
        int _idVuelo;
    public:
        void cargar();
        void mostrar();
        char getClase();
        int getFila();
        int getColumna();
        int getIdVuelo();
        void setClase(char);
        void setFila(int);
        void setColumna(int);
        void setIdVuelo(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // ASIENTO_H
