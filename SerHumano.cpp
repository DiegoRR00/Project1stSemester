#include "SerHumano.h"
#include <iostream>
#include <string>

using namespace std;
SerHumano::SerHumano()
{
        personName="";
        personLastName="";
        personBirthday="";

}

SerHumano::~SerHumano()
{
    delete &personName;
    delete &personLastName;
    delete &personBirthday;
}
//Cambia el nombre
void SerHumano::setPersonName(string _personName)
{
    personName=_personName;
}
//Cambia el apellido
void SerHumano::setPersonLastName(string _personLastName)
{
    personLastName=_personLastName;
}
//Genera un string con la fecha de cumpleanios
void SerHumano::setPersonBirthday(int _day,int _month,int _year)
{
    personBirthday=to_string(_day)+"/"+to_string(_month)+"/"+to_string(_year);
}
//Regresa el nombre
string SerHumano::getPersonName()
{
    return personName;
}
//Rgeresa el apellido
string SerHumano::getPersonLastName()
{
    return personLastName;
}
//Regresa el string de cumpleanios
string SerHumano::getPersonBirthday()
{
    return personBirthday;
}
//Convierte todo a string
string SerHumano::toString()
{
    string msg="Nombre:\t"+personName+"\n";
    msg+="Apellido:\t"+personLastName+"\n";
    msg+="Fecha de nacimiento:\t"+personBirthday+"\n";
    return msg;
}

