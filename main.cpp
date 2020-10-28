#include <iostream>
#include <time.h>
#include "Usuario.h"
#include "Avion.h"
#include "Pasajero.h"
#include "Vuelo.h"
using namespace std;

/*
Diego Reyna Reyes
A01657387
Proyecto Final
Este progama es un sistema de reservación, el cual funciona a través de usuarios, que pueden reservar vuelos para distintos pasajeros.
Se pueden realizar las siguientes acciones:
    Ver todos los vuelos disponibles
    Reservar un vuelo
    Ver los vuelos reservados
    Cambiar de cuenta
    Abonar dinero a tu cuenta
    Ver la información de tu cuenta
Entregado el 02/12/2019

Casos de prueba.
    Al iniciar sesión, debe aparecer un mensaje que diga Bienvenido nombreDeUsuario; el cual es una combinación de tu Nombre, tu epellido, el último dígito de tu año de nacimiento y 3 número aleatorios
    Al reservar un vuelo, si no se ha abonado dinero a tu cuenta, te dará la opción de abonar dinero a tu cuenta.}
    Si se quiere reservar un vuelo que no exista, debe aparecer un mensaje que te indique que ese vuelo no existe.
    Si se quiere cancelar una reserva que no se ha hecho, debe indicártelo
    Si no se ha creado un segundo usuario, se pedirá que se cree al cambiar de usuario, si ya fue creado, solo se te pedirá que selecciones el usuario que quieres usar.

*/



//Precio gasolina 1L=1.86 USD->36.35 MXN  https://www.iata.org/publications/economics/fuel-monitor/Pages/index.aspx
#define precioGas 36.35
//datos Airbus A320 https://es.m.wikipedia.org/wiki/Airbus_A320
#define alcanceA320 6100.0
#define gasA320 24210.0
#define pClaseA320 12
#define tClaseA320 138
//datos boing 737 max 9(Sé que está suspendido, pero solía ser uno de los más usados en el mundo) https://www.airlines-inform.com/commercial-aircraft/Boeing-737-900.html https://es.wikipedia.org/wiki/Boeing_737_MAX
#define alcance737 6658.0
#define gas737 26030
#define pClase737 20
#define tClase737 160
//Numero Vuelos
#define numVuel 3 //Al introducir muchos vuelos, el programa deja de imprimir
#define numDestination 14
#define velocidadPromedio 885

int main()
{
    //Creo mis dos posibles aviones
    Avion* airbusA320=new Avion();
    airbusA320->setCapacityFirst(pClaseA320);
    airbusA320->setCapacityTourist(tClaseA320);
    airbusA320->setModel("Airbus A320");
    airbusA320->setPriceByKm(precioGas*gasA320/alcanceA320);//alcance 6100km, capacidad tanque 24210L por lo tanto= litros/alcance*precio
    Avion* boeing373= new Avion();
    boeing373->setCapacityFirst(pClase737);
    boeing373->setCapacityTourist(tClase737);
    boeing373->setModel("Boeing 737-900");
    boeing373->setPriceByKm(precioGas*gas737/alcance737);

    //Creo la lista de mis vuelos con destinos aleatorios
    Vuelo** allFlights=new Vuelo*[numVuel];
    string aeropuertos[numDestination]={"Toronto","Los Angeles","Bogota","Tokio","Rio de Janeiro","Madrid","Nueva York","Paris","Londres","Guadalajara","Monterrey","Cancun","Acapulco","La Paz"};
    //Datos obtenidos de Google earth
    float distancia[numDestination]={3255.44,2494.23,3161.8,11313.57,7680.35,9090.92,3364.12,9221.35,8937.99,450.83,707.58,1302.96,291.6,1265.78};
    for (int i=0;i<numVuel;i++)
    {
        int destino=0+(sizeof(aeropuertos)/sizeof(*aeropuertos))*(float)rand()/RAND_MAX;//Elige un destino aleatorio
        if (i%2==0)//Para que sean variados los vuelos
        {
            allFlights[i]=new Vuelo(airbusA320);
            allFlights[i]->setDate();//genero una fecha aleatoria
            allFlights[i]->setAirline("Aereomexico");
            allFlights[i]->setBookedFirst(i);//Aparto asientos
            allFlights[i]->setBookedTourist(i+1);//Aparto asientos
            allFlights[i]->setDemand(1);//vario demanda
            allFlights[i]->setFlightNumber(5451+i);//genero un número de vuelos
            allFlights[i]->setOrigin("Mexico");//Salgan de la CDMX
            allFlights[i]->setDestination(aeropuertos[destino]);//Lleguen a un nuevo lugar

        }
        else
        {
            allFlights[i]=new Vuelo(boeing373);
            allFlights[i]->setDate();//genero una fecha aleatoria
            allFlights[i]->setAirline("Air Canada");
            allFlights[i]->setBookedFirst(i);//Aparto asientos
            allFlights[i]->setBookedTourist(i+2);//Aparto asientos
            allFlights[i]->setDemand(3);//vario demanda
            allFlights[i]->setFlightNumber(5451+i);//genero un número de vuelos
            allFlights[i]->setDestination("Mexico");//Lleguen a la CDMX
            allFlights[i]->setOrigin(aeropuertos[destino]);//Salgan de un nuevo lugar
        }
        allFlights[i]->setDistance(distancia[destino]);//Eligo distancia a partir de las ciudades que conecta
        allFlights[i]->setDuration(distancia[destino]/velocidadPromedio);//Calculo cuanto dura mi vuelo
        allFlights[i]->setPriceFirst();//Genero mi precio de primera clase
        allFlights[i]->setPriceTourist();//Genero mi precio turista


    }
    int bookedFlightsP1[numVuel],bookedFlightsP2[numVuel];//Genero mis listas de vuelos apartados
    for (int i=0;i<numVuel;i++)//Las lleno de 0
    {
        bookedFlightsP1[i]=0;
        bookedFlightsP2[i]=0;
    }
    //Iniciar sesion
    //Quien va a viajar
    Pasajero* pasajero1= new Pasajero();
    Pasajero* pasajero2= new Pasajero();
    //Genero los dos usuarios
    Usuario* perfil1= new Usuario(numVuel,pasajero1);
    Usuario* perfil2= new Usuario(numVuel,pasajero2);
    //Pido los datos del usuario para generar su cuenta
    string _personName,_personLastName,_password;
    int _day,_month,_year;
    cout<<"Introduzca su nombre de pila:"<<endl<<endl;
    cin>>_personName;
    cout<<"Introduzca su primer apellido:"<<endl<<endl;
    cin>>_personLastName;
    cout<<"Intoruzca su dia de nacimiento"<<endl<<endl;
    cin>>_day;
    cout<<"Intoruzca su mes de nacimiento"<<endl<<endl;
    cin>>_month;
    cout<<"Intoruzca su anio de nacimiento"<<endl<<endl;
    cin>>_year;
    cout<<"Introduzca una contrasena:"<<endl<<endl;//No tiene utilidad, pero para dar una mayor impresion de estar en un sistema de reservación
    cin>>_password;
    //Doy los valores a mi clase
    perfil1->setPersonBirthday(_day,_month,_year);
    perfil1->setPersonName(_personName);
    perfil1->setPersonLastName(_personLastName);
    perfil1->setUserName();
    perfil1->setPassword(_password);
    cout<<"Bienvenido "<<perfil1->getUserName()<<endl<<endl;

    int numUsuario=1;//Acciones dependiendo del usuario activo
    int totalUsers=0;//determina si necesito pedir crear un nuevo usuario o seleccionar entre los 2
    //menu
    int menu=0;
    int opcionMenu;
    while (menu==0)
    {
        cout<<"Ver vuelos -->1\nReserva vuelo-->2\nCancelar vuelos reservado-->3\nMostrar detlles de los vuelos reservados-->4\nAbonar dinero a cuenta-->5\nCambiar de usuario-->6\nVer datos de usuario->7\nSalir-->8"<<endl<<endl;
        cin>>opcionMenu;
        //muestra todos los vuelos
        if (opcionMenu==1)
        {
            perfil1->showFlights(allFlights);
        }
        //Genera una reserva
        if (opcionMenu==2)
        {
            if (numUsuario==1)
            {
                string nombrePasajero,apellidoPasajero;
                float numKm=50000*(float)rand()/RAND_MAX;//N[umero aleatorio de kilometros
                cout<<"Da el nombre de pila del pasajero que tomara el vuelo:"<<endl;
                cin>>nombrePasajero;
                cout<<"Da el apellido del pasajero que tomara el vuelo:"<<endl;
                cin>>apellidoPasajero;
                //Si no se ha abonado dinero a la cuenta, se pide que ingrese dinero
                if (perfil1->getMoney()==0)
                {
                    float _money;
                    cout<<"No tiene dinero abonado en la cuenta\nIngrese el dinero a abonar:"<<endl;
                    cin>>_money;
                    perfil1->setMoney(_money);
                }
                //Genera mi reserva
                pasajero1->setPersonName(nombrePasajero);
                pasajero1->setPersonLastName(apellidoPasajero);
                pasajero1->getName();
                pasajero1->setKmTraveled(numKm);
                perfil1->bookFlight(allFlights,bookedFlightsP1);

            }
            else
            {
                string nombrePasajero,apellidoPasajero;
                float numKm2=50000*(float)rand()/RAND_MAX;//N[umero aleatorio de kilometros
                cout<<"Da el nombre de pila del pasajero que tomara el vuelo:"<<endl;
                cin>>nombrePasajero;
                cout<<"Da el apellido del pasajero que tomara el vuelo:"<<endl;
                cin>>apellidoPasajero;
                //Si no se ha abonado dinero a la cuenta, se pide que ingrese dinero
                if (perfil2->getMoney()==0)
                {
                    float _money;
                    cout<<"No tiene dinero abonado en la cuenta\nIngrese el dinero a abonar:"<<endl;
                    cin>>_money;
                    perfil2->setMoney(_money);
                }
                //Genera mi reserva
                pasajero2->setPersonName(nombrePasajero);
                pasajero2->setPersonLastName(apellidoPasajero);
                pasajero2->getName();
                pasajero2->setKmTraveled(numKm2);
                perfil2->bookFlight(allFlights,bookedFlightsP2);
            }
        }
        //Cancela el vuelo
        if (opcionMenu==3)
        {
            if (numUsuario==1)
            {
                perfil1->printBookedFlights(allFlights,bookedFlightsP1);
                int flightToCancel;
                cout<<"Ingrese el número de vuelo a reservar:"<<endl;
                cin>>flightToCancel;
                perfil1->cancelReservation(flightToCancel,bookedFlightsP1);
            }
            else
            {
                perfil2->printBookedFlights(allFlights,bookedFlightsP2);
                int flightToCancel;
                cout<<"Ingrese el número de vuelo a cancelar:"<<endl;
                cin>>flightToCancel;
                perfil2->cancelReservation(flightToCancel,bookedFlightsP2);
            }
        }
        //Imprime los vuelos reservados
        if (opcionMenu==4)
        {
            if (numUsuario==1)
            {
                perfil1->printBookedFlights(allFlights,bookedFlightsP1);
            }
            else
            {
                perfil2->printBookedFlights(allFlights,bookedFlightsP2);
            }
        }
        //Abona dinero
        if (opcionMenu==5)
        {
            if (numUsuario==1)
            {
                float _money;
                cout<<"Ingrese el dinero a abonar:"<<endl;
                cin>>_money;
                perfil1->setMoney(_money);
            }
            else
            {
                float _money;
                cout<<"Ingrese el dinero a abonar:"<<endl;
                cin>>_money;
                perfil2->setMoney(_money);
            }

        }
        //Cambia de sesión
        if (opcionMenu==6)
        {
            cout<<"Seleccionar usuario:"<<endl;
            int userInput;
            string _userName;
            if (totalUsers==0)//Si solo hay un usuario creado, da la opcion de crear uno nuevo
            {
                cout<<"Usuario 1: "<<perfil1->getUserName()<<"->1"<<endl;
                cout<<"Crear nuevo usuario->2"<<endl;
                cin>>userInput;
                if (userInput==1)
                {
                    numUsuario=1;
                    cout<<"Bienvenido "<<perfil1->getUserName()<<endl<<endl;
                }
                else
                {
                    //Pido los datos del usuario para generar su cuenta
                    string _personName,_personLastName,_password;
                    int _day,_month,_year;
                    cout<<"Introduzca su nombre de pila:"<<endl<<endl;
                    cin>>_personName;
                    cout<<"Introduzca su primer apellido:"<<endl<<endl;
                    cin>>_personLastName;
                    cout<<"Intoruzca su dia de nacimiento"<<endl<<endl;
                    cin>>_day;
                    cout<<"Intoruzca su mes de nacimiento"<<endl<<endl;
                    cin>>_month;
                    cout<<"Intoruzca su anio de nacimiento"<<endl<<endl;
                    cin>>_year;
                    cout<<"Introduzca una contrasena:"<<endl<<endl;//No tiene utilidad, pero para dar una mayor impresion de estar en un sistema de reservación
                    cin>>_password;
                    perfil2->setPersonBirthday(_day,_month,_year);
                    perfil2->setPersonName(_personName);
                    perfil2->setPersonLastName(_personLastName);
                    perfil2->setUserName();
                    perfil2->setPassword(_password);
                    cout<<"Bienvenido "<<perfil2->getUserName()<<endl<<endl;
                    numUsuario=2;
                }
            }
            else //Si ya hay dos usuarios creados, pido que solo inicie sesión en uno
            {
                cout<<"Usuario 1:  "<<perfil1->getUserName()<<"->1"<<endl;
                cout<<"Usuario 2:  "<<perfil2->getUserName()<<"->2"<<endl;
                cin>>userInput;
                if (userInput==1)
                {
                    numUsuario=1;
                    cout<<"Bienvenido "<<perfil1->getUserName()<<endl<<endl;
                }
                else if(userInput==2)
                {
                    numUsuario=2;
                    cout<<"Bienvenido "<<perfil2->getUserName()<<endl<<endl;
                }
                else
                {
                    cout<<"Perfil invalido"<<endl;
                }

            }

        }
        //Imprime los datos de mi usuario y los vuelos reservados
        if (opcionMenu==7)
        {
            if (numUsuario==1)
            {
                cout<<perfil1->toString()<<endl;
                perfil1->printBookedFlights(allFlights,bookedFlightsP1);
            }
            else
            {
                cout<<perfil2->toString()<<endl;
                perfil2->printBookedFlights(allFlights,bookedFlightsP2);
            }
        }
        //Sale del menu
        if (opcionMenu==8)
        {
            menu=1;
            cout<<"Gracias por visitarnos"<<endl;
        }
    }
    //Borro todo
    perfil1->~Usuario();
    airbusA320->~Avion();
    boeing373->~Avion();
    for (int m=0;m<numVuel;m++)
    {
        allFlights[m]->~Vuelo();
    }
    pasajero1->~Pasajero();
    pasajero2->~Pasajero();
    return 0;
}
