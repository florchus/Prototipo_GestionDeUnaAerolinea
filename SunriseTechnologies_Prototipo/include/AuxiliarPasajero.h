#ifndef AUXILIARPASAJERO_H
#define AUXILIARPASAJERO_H


class AuxiliarPasajero
{
    private:
        char _dni[9];
        int _idPnr;
        float _kilos;
        bool _embarco;
    public:
        void mostrar();
        char *getDni();
        int getIdPnr();
        float getKilos();
        bool getEmbarco();
        void setKilos(float);
        void setEmbarco(bool);
        void setDni(char*);
        void setIdPnr(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // AUXILIARPASAJERO_H
