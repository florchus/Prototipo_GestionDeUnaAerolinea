#ifndef RESERVA_H
#define RESERVA_H
#include "Fecha.h"

class Reserva{
    private:
        int _idPnr; //PNR = Passenger Name Record = Codigo de Reserva
        Fecha _fechaCompra;
        Fecha _fechaEmbarque;
        float _importe;
        int _idVuelo;
        int _estado; //0=reserva nueva sin confirmar; 1=reserva confirmada; -1=reserva cancelada
        char _clase; //para setear W o J
    public:
        Reserva();
        void mostrar();
        void mostrarEstado();
        int getIdPnr();
        Fecha getFechaCompra();
        Fecha getFechaEmbarque();
        float getImporte();
        int getIdVuelo();
        int getEstado();
        char getClase();
        void setIdPnr(int);
        void setFechaEmbarque(Fecha);
        void setFechaCompra(Fecha );
        void setImporte(float);
        void setIdVuelo(int);
        void setEstado(int);
        void setClase(char);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // RESERVA_H
