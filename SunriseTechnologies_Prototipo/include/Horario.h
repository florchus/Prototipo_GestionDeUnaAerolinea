#ifndef HORARIO_H
#define HORARIO_H


class Horario
{
    private:
        int _hora;
        int _minuto;
    public:
        int getHora();
        int getMinuto();
        void setHora(int );
        void setMinuto(int );
        void mostrar();
        void cargar();
};

#endif // HORARIO_H
