#ifndef USUARIO_H
#define USUARIO_H
#include "Persona.h"

class Usuario:public Persona{
    private:        char _id[10];
        char _contrasenia[5];
        int _permiso;
    public:
        void cargar();
        void mostrar();
        char *getId();
        char *getContrasenia();
        int getPermiso();
        void setId(char*);
        void setContrasenia(char*);
        void setPermiso(int);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // USUARIO_H
