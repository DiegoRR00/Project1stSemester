#include "Pasajero.h"
#include<iostream>
#include<string>
using namespace std;
Pasajero::Pasajero()
{
        name="";
        kmTraveled=0.0;
}

Pasajero::~Pasajero()
{
    delete &name;
    delete &kmTraveled;
}
//Regresa el nombre del pasajero
string Pasajero::getName()
{
    return name;
}
//Genera el nombre completo del Pasajero
void Pasajero::setName()
{
    name=personName+" "+personLastName;
}
//Regresa el numero de kilometros viajados
float Pasajero::getKmTraveled()
{
    return kmTraveled;
}
//Cambia el valor de los kilometros viajados
void Pasajero::setKmTraveled(float _kmTraveled)
{
    kmTraveled=_kmTraveled;
}
//Conierte todo en un string
string Pasajero::toString()
{
    string msg="Pasajero:\t"+name+"\nKilometros viajadoos:\t"+to_string(kmTraveled);
    return msg;
}
