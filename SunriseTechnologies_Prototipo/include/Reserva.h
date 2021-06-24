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
    public:
        Reserva();
        void mostrar();
        int getIdPnr();
        Fecha getFechaCompra();
        Fecha getFechaEmbarque();
        float getImporte();
        int getIdVuelo();
        int getEstado();
        void setIdPnr(int);
        void setFechaEmbarque(Fecha);
        void setFechaCompra(Fecha );
        void setImporte(float);
        void setIdVuelo(int);
        void setEstado(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // RESERVA_H
