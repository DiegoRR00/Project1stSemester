#include "Usuario.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
//constructor
Usuario::Usuario(int _totalFlights,Pasajero* _passenger)
{
    userName="";
    password="0000";
    money=0.0;
    passenger=_passenger;
    totalFlights=_totalFlights;
}
//Destructor
Usuario::~Usuario()
{
    delete &userName;
    delete &password;
    delete &money;
    delete &totalFlights;
}
//Cambia el valor de password
 void Usuario::setUserName()
 {
    int m=100+(999-100)*(float)rand()/RAND_MAX;
     userName=personName+personLastName+personBirthday.back()+to_string(m);
 }
//Cmabia el valor de password
 void Usuario::setPassword(string _password)
 {
     password=_password;
 }
//regresa la password
 string Usuario::getPassword()
 {
     return password;
 }
//regresa el userName
 string Usuario::getUserName()
 {
     return userName;
 }
//regresa el valor del dinero
float Usuario::getMoney()//regresa el dinero del usuario
{
    return money;
}
//muestra los vuelos disponibles
void Usuario::showFlights(Vuelo** _flights)
{
    for (int i=0;i<totalFlights;i++)
    {
        cout<<_flights[i]->toStringForUser()<<endl;
    }
}
//reserva vuelo, recibe la lista de vuelos
void Usuario::bookFlight(Vuelo** _flights, int _bookedFlights[])//reserva vuelo
{

    showFlights(_flights);
    int vueloExistente=1;

    int flightSelection;

    cout<<"Seleccione el numero de vuelo que quiera reservar:"<<endl;
    cin>>flightSelection;
    for (int k=0;k<totalFlights;k++)//revisa en todos mis vuelos si existe la solución mostrada
    {
        if (_flights[k]->getFlightNumber()==flightSelection)\
        {
            //Vuelo posible
            int classSelection;
            int claseValida=1;
            float priceFlight;
            vueloExistente=0;
            while (claseValida==1)
            {
                cout<<"Seleccione en que clase quiere reservar:\nPrimera Clase-->1\nClase Turista-->2"<<endl;
                cin>>classSelection;
                if (classSelection==1)
                {
                    claseValida=0;
                    priceFlight=_flights[k]->getPriceFirst();//determina el precio dependiendo de la clase que se busca
                }
                if (classSelection==2)
                {
                    claseValida=0;
                    priceFlight=_flights[k]->getPriceTourist();//determina el precio dependiendo de la clase que se busca
                }
            }
            float kmRecorridos;
            kmRecorridos= passenger->getKmTraveled();
            //Checa si el pasajero aplica a descuento
            if (kmRecorridos>=50000)
            {
                priceFlight=priceFlight*.6;
            }
            //Si hay suficiente dinero para pagar
            if (money>=priceFlight)
            {
                money=money-priceFlight;
                for (int m=0;m<totalFlights;m++)
                {
                    //Guarda la reservacion
                    if (_bookedFlights[m]==0)
                    {
                        _bookedFlights[m]=flightSelection;
                        break;
                    }
                }
                cout<<"Pago aceptado, reserva confirmada"<<endl<<endl;
            }
            else
            {
                cout<<"No hay suficiente dinero en la cuenta"<<endl<<endl;
            }

        }
    }
    //Si el vuelo no se encuentra en los vuelos disponibles
    if (vueloExistente==1)
    {
        cout<<"El vuelo seleccionado no existe"<<endl;
    }

}
//cambia de pasajero
void Usuario::setPassenger(Pasajero* _passenger)//crea un pasajero
{
    passenger=_passenger;
}
//cambia el valor de money
void Usuario::setMoney(float _money)//añade dinero a su cuenta
{
    money+=_money;
}
//cancela reservacion
void Usuario::cancelReservation(int _flightNumber, int _bookedFlights[])//cancela una reservación
{
    int reservaConfrimada=0;
    for (int i=0;i<totalFlights;i++)
    {
        if (_flightNumber==_bookedFlights[i])//Busca en los vuelos reservados
            {
                reservaConfrimada=1;
                _bookedFlights[i]=0;
                cout<<"Reserva Cancelada"<<endl;
            }
    }
        if (reservaConfrimada==0)//Si el vuelo no estaba en los vuelos reservados, se imprime el mensaje
    {
        cout<<"No se habia reservado en este vuelo"<<endl;
    }
}
//imprime los vuelos apartados de la lista bookedFlights
void Usuario::printBookedFlights(Vuelo** _flights, int _bookedFlights[])
{
    int numOfBookedFlights=0;
    for (int i=0;i<totalFlights;i++)
    {
        int numVuelo=_flights[i]->getFlightNumber();
        for (int x=0;x<totalFlights;x++)
        {
            if (_bookedFlights[x]==numVuelo)
            {
                numOfBookedFlights+=1;
                cout<<_flights[i]->toStringForUser()<<endl;
            }
        }
    }
    if (numOfBookedFlights==0)//Si la lista no tiene vuelos imprime el mensaje
    {
        cout<<"No hay vuelos reservados"<<endl<<endl;
    }
}
//Regresa un string con los datos del usuario
string Usuario::toString()
 {
     string msg="Usuario:\t"+userName+"\nContrasena:\t"+password+"\n";
     msg+="Nombre:\t"+personName+"\n";
     msg+="Apellido:\t"+personLastName+"\n";
     msg+="Fecha de nacimiento:\t"+personBirthday+"\n";
     msg+="Dinero abonado:\t$"+to_string(money)+"MXN\n";
     msg+="Vuelos reservados:\n";
     return msg;
 }
