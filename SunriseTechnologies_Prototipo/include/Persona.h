#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
    protected:
        char _dni[9];
        char _nombre[50];
        char _apellido[50];
        char _telefono[11];
        char _email[20];
    public:
        Persona();
        void cargar();
        void mostrar();
        char *getDni();
        char *getNombre();
        char *getApellido();
        char *getTelefono();
        char *getEmail();
        void setDni(char *);
        void setNombre(char *);
        void setApellido(char *);
        void setTelefono(char *);
        void setEmail(char *);

};

#endif // PERSONA_H
