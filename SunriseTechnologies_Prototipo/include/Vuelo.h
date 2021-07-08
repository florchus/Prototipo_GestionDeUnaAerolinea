#ifndef VUELO_H
#define VUELO_H
#include "Fecha.h"
#include "Avion.h"
#include "Horario.h"
#include "Destino.h"
class Vuelo{
    private:
        char _matriculaAvion[6];
        int _idVuelo;
        char _codigoDestino[4];
        char _codigoPartida[4];
        Fecha _fechaEmbarque;
        Horario _horaEmb;
        Horario _std; //Scheduled Time of Departure
        Horario _sta; //Scheduled Time of Arrival
        Fecha _fechaAterrizaje;
        Horario _eta; //Estimated Time of Arrival
        Horario _etd; //Estimated time of Departure
    public:
        char *getMatriculaAvion();
        int getidVuelo();
        char *getCodigoDestino();
        char *getCodigoPartida();
        Fecha getFechaEmbarque();
        Horario getHoraEmb();
        Horario getStd();
        Horario getSta();
        Fecha getFechaAterrizaje();
        Horario getEta();
        Horario getEtd();
        void setMatriculaAvion(char *);
        void setIdVuelo(int);
        void setCodigoDestino(char *);
        void setCodigoPartida(char *);
        void setFechaEmbarque(Fecha);
        void setHoraEmb(Horario);
        void setStd(Horario);
        void setSta(Horario);
        void setFechaAterrizaje(Fecha);
        void setEta(Horario);
        void setEtd(Horario);
        void setDest(Destino);
        void cargar();
        void cargar2();
        void mostrar();
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // VUELO_H
