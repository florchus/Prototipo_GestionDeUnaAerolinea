#ifndef AUXILIARPASAJERO_H
#define AUXILIARPASAJERO_H


class AuxiliarPasajero
{
    private:
        char _dni[9];
        int _idPnr;
        float _kilos;
        bool _embarco;
        int _fila;
        int _columna;
    public:
        void mostrar();
        void mostrar2();
        void mostrar3();
        char *getDni();
        int getIdPnr();
        float getKilos();
        bool getEmbarco();
        int getFila(){return _fila;}
        int getColumna(){return _columna;}
        void setKilos(float);
        void setEmbarco(bool);
        void setDni(char*);
        void setIdPnr(int);
        void setFila(int fila){_fila = fila;}
        void setColumna(int columna){_columna = columna;}
        void grabarEnDisco();
        bool grabarEnDisco(int);
        bool leerDeDisco(int);
};

#endif // AUXILIARPASAJERO_H
