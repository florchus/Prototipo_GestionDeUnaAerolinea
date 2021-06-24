#ifndef ASIENTO_H
#define ASIENTO_H
#include "Vuelo.h"

class Asiento{
    private:
        bool _clase; //si es W (1) o J (0)
        int _fila;
        int _columna;
        char _matriculaAvion[6];
        char _dni[9];
    public:
        void cargar();
        void mostrar();
        bool getClase();
        int getFila();
        int getColumna();
        char *getMatriculaAvion();
        char *getDni();
        void setClase(bool);
        void setFila(int);
        void setColumna(int);
        void setMatriculaAvion(char*);
        void setDni(char *);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // ASIENTO_H
