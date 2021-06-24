#ifndef DESTINO_H
#define DESTINO_H


class Destino
{
    private:
        char _destino[50];
        float _precio;
        char _pais[50];
        char _codigoDestino[4];
        bool _estado;
    public:
        Destino();
        void cargar();
        void mostrar();
        char *getDestino();
        float getPrecio();
        char *getPais();
        char *getCodigoDestino();
        bool getEstado();
        void setDestino(char*);
        void setPrecio(float);
        void setPais(char*);
        void setCodigoDestino(char *);
        void setEstado(bool);
        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // DESTINO_H
