#ifndef AVION_H
#define AVION_H


class Avion{
    private:
        int _capacidadAsientosW;
        int _capacidadAsientosJ;
        float _capacidadCombustible;
        char _modelo[11];
        char _matricula[6];
    public:
        void cargar();
        void mostrar();
        int getCapacidadAsientosW();
        int getCapacidadAsientosJ();
        float getCapacidadCombustible();
        char *getModelo();
        char *getMatricula();
        void setCapacidadAsientosW(int);
        void setCapacidadAsientosJ(int);
        void setCapacidadCombustible(float);
        void setModelo(char*);
        void setMatricula(char *);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // AVION_H
