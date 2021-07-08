#ifndef PASAJERO_H
#define PASAJERO_H
#include "Persona.h"
#include "Fecha.h"

class Pasajero:public Persona
{
    private:
        Fecha _nacimiento;
    public:
        void cargar();
        void mostrar();
        Fecha getNacimiento();
        void setNacimiento(Fecha);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // PASAJERO_H
