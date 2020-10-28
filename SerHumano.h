#ifndef SERHUMANO_H
#define SERHUMANO_H
#include <iostream>
#include <string>

using namespace std;
class SerHumano
{
    public:
        SerHumano();
        virtual ~SerHumano();
        void setPersonName(string _personName);//Cambia el nombre del ser humano
        void setPersonLastName(string _personLastName);//Cambia el apellido del ser humano
        void setPersonBirthday(int _day,int _month,int _year);//genera un string con la fecha de nacimiento del ser humano
        string getPersonName();//Regresa el nombre
        string getPersonLastName();//Regresa el apellido
        string getPersonBirthday();//Regresa el string con la fecha de nacimiento
        string toString();//Genera un string con los datos del usuario

    protected:
        string personName;//Nombre
        string personLastName;//Apellido
        string personBirthday;//Fecha de nacimiento
};

#endif // SERHUMANO_H
