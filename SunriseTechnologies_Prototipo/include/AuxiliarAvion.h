#ifndef AUXILIARAVION_H
#define AUXILIARAVION_H


class AuxiliarAvion{
    private:
        int _capacidadAsientosW;
        int _capacidadAsientosJ;
        int _idVuelo;


    public:
        void cargar();
        void mostrar();
        int getCapacidadAsientosW();
        int getCapacidadAsientosJ();
        int getIdVuelo();
        void setCapacidadAsientosW(int);
        void setCapacidadAsientosJ(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // AUXILIARAVION_H
