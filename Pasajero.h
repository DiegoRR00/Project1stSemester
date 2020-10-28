#ifndef PASAJERO_H
#define PASAJERO_H
#include<iostream>
#include<string>
#include "SerHumano.h"
using namespace std;

class Pasajero:public SerHumano
{
    public:
        Pasajero();
        virtual ~Pasajero();
        string getName();//regresa el nombre del pasajero
        void setName();//Cambia el nombre
        float getKmTraveled();//Regresa el num de kilometros que ha viajado el pasajero
        void setKmTraveled(float _kmTraveled);//cambia el numero de kilometros que ha viajado el usuario
        string toString();//Convierte todo en un string

    private:
        string name;//Nombre
        float kmTraveled;//Kilomtros viajados
};

#endif // PASAJERO_H
