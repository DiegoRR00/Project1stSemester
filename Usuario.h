#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <time.h>
#include "Pasajero.h"
#include "Vuelo.h"
#include "SerHumano.h"
using namespace std;

class Usuario:public SerHumano
{
    public:
        Usuario(int _totalFlights, Pasajero* _passenger);
        virtual ~Usuario();
        void setUserName();//cambia el nombre de usuario
        string getUserName();//regresa nombre de usuario
        void setPassword(string _password);//cambia la contraseña
        string getPassword();//regresa la contraseñ
        float getMoney();//regresa el dinero del usuario
        void showFlights(Vuelo** _flights);
        void bookFlight(Vuelo** _flights, int _bookedFlights[]);//reserva vuelo
        void setPassenger(Pasajero* _passenger);//crea un pasajero
        void setMoney(float _money);//añade dinero a su cuenta
        void cancelReservation(int _flightNumber,int _bookedFlights[]);//cancela una reservación
        void printBookedFlights(Vuelo** _flights,int _bookedFlights[]);//Imprime los vuelos reservados
        string toString();//convierte a string todo

    private:

        string userName;
        string password;
        float money;
        int totalFlights;
        Pasajero* passenger;

};

#endif // USUARIO_H
