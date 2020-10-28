#include "Vuelo.h"
#include<iostream>
#include<string>
using namespace std;
Vuelo::Vuelo(Avion* _plane)
{
        bookedFirst=0;
        bookedTourist=0;
        flightNumber=0;
        destination="";
        origin="";
        airline="";
        duration=0.0;
        priceTourist=0.0;
        priceFirst=0.0;
        plane=_plane;
        demand=0;
        distance=0.0;
        date="";
}

Vuelo::~Vuelo()
{
        delete &bookedFirst;
        delete &bookedTourist;
        delete &flightNumber;
        delete &destination;
        delete &origin;
        delete &airline;
        delete &duration;
        delete &priceTourist;
        delete &priceFirst;
        delete &plane;
        delete &demand;
        delete &distance;
        delete &date;
}
//Número de asientos de primera clase ocupados
void Vuelo::setBookedFirst(int _bookedFirst)
{
    if (_bookedFirst<=plane->getCapacityFirst())//Revisa que lo que se busca apartar no supere el total de lugares
    {
        bookedFirst=_bookedFirst;
    }
    else
    {
        cout<<"No existen tantos lugares de primera clase"<<endl;
    }

}
//Aparta lugares de primera clase
int Vuelo::getBookedFirst()
{
    return bookedFirst;
}
//Regresa los lugares de turista apartados
int Vuelo::getBookedTourist()
{
    return bookedTourist;
}
//Aparta lugares de clase turista
void Vuelo::setBookedTourist(int _bookedTourist)
{
    if (_bookedTourist<=plane->getCapacityTourist())//Revisa que lo que se busca apartar no supere el total de lugares
    {
        bookedTourist=_bookedTourist;
    }
    else
    {
        cout<<"No existen tantos lugares de clase turista"<<endl;
    }
}
//Regresa el número de vuelo
int Vuelo::getFlightNumber()
{
    return flightNumber;
}
//Cambia el número de vuelo
void Vuelo::setFlightNumber(int _flightNumber)
{
    flightNumber=_flightNumber;
}
//Cambia el destino
void Vuelo::setDestination(string _destination)
{
    destination= _destination;
}
//Regresa el destino
string Vuelo::getDestination()
{
    return destination;
}
//Regresa el origen del vuelo
string Vuelo::getOrigin()
{
    return origin;
}
//Cambia el origen
void Vuelo::setOrigin(string _origin)
{
    origin=_origin;
}
//Cambia la aerolínea
void Vuelo::setAirline(string _airline)
{
    airline=_airline;
}
//Regresa la aerolínea
string Vuelo::getAirline()
{
    return airline;
}
//regresa la duracion en horas
float Vuelo::getDuration()
{
    return duration;
}
//Cambia la duracion del vuelo
void Vuelo::setDuration(float _duration)
{
    duration=_duration;
}
//Genera el precio de la clase turista
void Vuelo::setPriceTourist()
{
    priceTourist=plane->getPriceByKm()*distance;//Precio que depende de la distancia y el precio del avion por distancia
    if (demand==1)//Significa mucha demanda, aumentando el precio
    {
        priceTourist=priceTourist*1.1;
    }
    if (demand==2)//significa demanda normal, no modifica el precio
    {
        priceTourist=priceTourist;
    }
    if (demand==3)//Significa poca demanda, por lo que aumenta al precio debido al elevado precio de volar
    {
        priceTourist=priceTourist*1.2;
    }
    priceTourist=priceTourist/(plane->getCapacityFirst()+plane->getCapacityTourist());//Precio por persona en el avión
    //A=Pago por avión
    //P=pago por persona
    //Tomando que se necesitan 240 USD para pagar a la tripulacion =4690MXN A
    //Precio de cada aeorpuerto 1089 USD=21284.19MXN A
    //Precio de la aeronave, por simplificacion será el A320=1783USD =34848.22MXN A
    //Precio de mantenimiento 2121USD=41454.33MXN A
    //Seguro de 36USD por hora=703.61MXN A
    //Precio de personal administración de aereolinea 10USD P
    //Impuestos 77.91  https://heraldodemexico.com.mx/pais/impuesto-a-los-vuelos-internacionales-sube-91/ P
    //Por simplicidad, consideramos impuestos para llegar a los EEUU P
    //Impuesto EEUU 7.9% +5.6USD=109.45MXN+17.7USD de viaje internacional+5.5 de migracion+12USD de varios departamentos P
    //Ganancia 10USD
    //Total de pago por pasajero=77.91MXN+33.1USD=724.84
    //Fuente: https://www.youtube.com/watch?v=6Oe8T3AvydU
    priceTourist=priceTourist*7.9+(4290.00+2*21284.19+34848.22+41454.33+(703.61*duration))/(plane->getCapacityFirst()+plane->getCapacityTourist());//Precio extra por avión
    priceTourist=priceTourist+(724.84);//Precio extra por pasajero
}
//Regresa el precio de la clase turista
float Vuelo::getPriceTourist()
{
    return priceTourist;
}
//Genera un precio para la primera clase
void Vuelo::setPriceFirst()
{
    priceFirst=plane->getPriceByKm()*distance;
    if (demand==1)//Mucha demanda
    {
        priceFirst=priceFirst*1.1;
    }
    if (demand==2)//Demanda media
    {
        priceFirst=priceFirst;
    }
    if (demand==3)
    {
        priceFirst=priceFirst*1.2;//Demanda baja
    }
    priceFirst=priceFirst/(plane->getCapacityFirst()+plane->getCapacityTourist());
    //A=Pago por avión
    //P=pago por persona
    //Tomando que se necesitan 240 USD para pagar a la tripulacion =4690MXN A
    //Precio de cada aeorpuerto 1089 USD=21284.19MXN A
    //Precio de la aeronave, por simplificacion será el A320=1783USD =34848.22MXN A
    //Precio de mantenimiento 2121USD=41454.33MXN A
    //Seguro de 36USD por hora=703.61MXN A
    //Precio de personal administración de aereolinea 10USD P
    //Impuestos 77.91  https://heraldodemexico.com.mx/pais/impuesto-a-los-vuelos-internacionales-sube-91/ P
    //Por simplicidad, consideramos impuestos para llegar a los EEUU P
    //Impuesto EEUU 7.9% +5.6USD=109.45MXN+17.7USD de viaje internacional+5.5 de migracion+12USD de varios departamentos P
    //Ganancia 10USD
    //Total de pago por pasajero=77.91MXN+33.1USD=724.84
    //Fuente: https://www.youtube.com/watch?v=6Oe8T3AvydU
    priceFirst=priceFirst*7.9+(4290.00+2*21284.19+34848.22+41454.33+(703.61*duration))/(plane->getCapacityFirst()+plane->getCapacityTourist());//Costo extra por avión
    priceFirst=priceFirst+(724.84);//Copsto extra por persona
    //Considerando un aumento del 220% entre clase turista y primera clase
    priceFirst=priceFirst*2.2;
}
//Regresa el precio de la primera clase
float Vuelo::getPriceFirst()
{
    return priceFirst;
}
//Cambia el valor de la demanda
void Vuelo::setDemand(int _demand)
{
    demand=_demand;
}
//Regresa la demanda
int Vuelo::getDemand()
{
    return demand;
}
//Cambia el valor de la distancia
void Vuelo::setDistance(float _distance)
{
    distance=_distance;
}
//Regresa la distancia
float Vuelo::getDistance()
{
    return distance;
}
//Regresa la fecha de vuelo
string Vuelo::getDate()
{
    return date;
}
//Genera una fecha aleatoria de vuelo
void Vuelo::setDate()
{
    //Generamos mes
    int mes=1+(13-2)*(float)rand()/RAND_MAX;
    mes=floor(mes);
    //generar anio
    int anio=20+(21-20)*(float)rand()/RAND_MAX;
    anio=floor(anio);
    //generar cantidad de dias que dependen del mes
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
    {
        int dia=1+(31-1)*(float)rand()/RAND_MAX;
        dia=floor(dia);
        date=to_string(dia)+"/"+to_string(mes)+"/"+to_string(anio);
    }
    else if (mes==2)
    {
        int dia=1+(28-1)*(float)rand()/RAND_MAX;
        dia=floor(dia);
        date=to_string(dia)+"/"+to_string(mes)+"/"+to_string(anio);
    }
    else
    {
        int dia=1+(30-1)*(float)rand()/RAND_MAX;
        dia=floor(dia);
        date=to_string(dia)+"/"+to_string(mes)+"/"+to_string(anio);
    }



}
//Genera un string con todos los datos
string Vuelo::toString()
{
     string msg="Vuelo "+to_string(flightNumber)+"\n";
     msg+="Nombre:\t"+origin+" a "+destination+"\n";
     msg+=plane->toString();
     msg+="Asientos reservados de primera clase:\t"+to_string(bookedFirst)+"\n";
     msg+="Asientos reservados de clase turista:\t"+to_string(bookedTourist)+"\n";
     msg+="Aerolinea:\t"+airline+"\n";
     msg+="Duracion:\t"+to_string(duration)+" horas\n";
     msg+="Precio turista:\t $"+to_string(priceTourist)+"MXN\n";
     msg+="Precio primera clase:\t $"+to_string(priceFirst)+"MXN\n";
     msg+="Demanda:\t"+to_string(demand)+"\n";
     return msg;
}
//Genera un string con los datos importantes para el usuario
string Vuelo::toStringForUser()
{
    string msg="Vuelo "+to_string(flightNumber)+"\n";
    msg+="Nombre:\t"+origin+" a "+destination+"\n";
    msg+="Aerolinea:\t"+airline+"\n";
    msg+="Fecha:\t"+date+"\n";
    msg+="Duracion:\t"+to_string(duration)+"\n";
    msg+="Precio turista:\t $"+to_string(priceTourist)+"MXN\n";
    msg+="Precio primera clase:\t $"+to_string(priceFirst)+"MXN\n";
    return msg;
}
