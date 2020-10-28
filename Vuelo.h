#ifndef VUELO_H
#define VUELO_H
#include<iostream>
#include<string>
#include <time.h>
#include <math.h>
#include "Avion.h"
using namespace std;

class Vuelo
{
    public:
        Vuelo(Avion* _aiplane);
        virtual ~Vuelo();
        void setBookedFirst(int _bookedFirst);//Aparta lugares de primera clase
        int getBookedFirst();//Aparta lugares de primera clase
        int getBookedTourist();//Regresa los lugares de turista apartados
        void setBookedTourist(int _bookedTourist);//Aparta lugares de clase turista
        int getFlightNumber(); //Regresa el número de vuelo
        void setFlightNumber(int _flightNumber);//Cambia el número de vuelo
        void setDestination(string _destination);//Cambia el destino
        string getDestination();//Regresa el destino
        string getOrigin();//Regresa el origen del vuelo
        void setOrigin(string _origin);//Cambia el origen
        void setAirline(string _airline);//Cambia la aerolínea
        string getAirline();//Regresa la aerolínea
        float getDuration();//regresa la duracion en horas
        void setDuration(float _duration);//Cambia la duracion del vuelo
        void setPriceFirst();//Genera un precio para la primera clase
        float getPriceFirst();//regresa el precio de primera clase
        void setPriceTourist();//Genera el precio de la clase turista
        float getPriceTourist();//Regresa el precio de la clase turista
        void setDemand(int _demand);//Cambia el valor de la demanda
        int getDemand();//Regresa la demanda
        float getDistance();//Regresa la distancia
        void setDistance(float _distance);//Cambia el valor de la distancia
        string getDate();//Regresa la fecha de vuelo
        void setDate();//Genera una fecha aleatoria de vuelo
        string toString();//Genera un string con todos los datos
        string toStringForUser();//Genera un string con los datos importantes para el usuario

    private:
        int bookedFirst; //Número de asientos de primera clase ocupados
        int bookedTourist;//Número de asientos de clase turista ocupados
        int flightNumber;//Número de identificación del vuelo
        string destination;//Ciudad de destino
        string origin;//Ciudad de origen
        string airline;//Aerolínea que opera el vuelo
        float duration;//Tiempo en horas que dura el vuelo
        float priceTourist;//Precio de clase turista
        float priceFirst;//Precio de primera clase
        Avion* plane;//Avión que realiza el vuelo
        int demand;//Demanda del vuelo que cambia el precio
        float distance;//Distancia en km del vuelo
        string date;//Fecha del vuelo
};

#endif // VUELO_H
