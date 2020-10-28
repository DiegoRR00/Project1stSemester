#include "Avion.h"

Avion::Avion()
{
    capacityFirst=0;
    capacityTourist=0;
    model="";
    priceByKm=0.0;
}

Avion::~Avion()
{
    delete &capacityFirst;
    delete &capacityTourist;
    delete &model;
    delete &priceByKm;
}
int Avion::getCapacityFirst()//regresa los lugares de primera clase
{
    return capacityFirst;
}
int Avion::getCapacityTourist()//lo mismo pero con clase turista
{
    return capacityTourist;
}
void Avion::setCapacityFirst(int _capacityFirst)//define lugares 1a clase
{
    capacityFirst=_capacityFirst;
}
void Avion::setCapacityTourist(int _capacityTourist)//define lugares turista
{
    capacityTourist=_capacityTourist;
}
string Avion::getModel()//regresa el modelo
{
    return model;
}
void Avion::setModel(string _model)//define el modelo
{
    model=_model;
}
float Avion::getPriceByKm()//regresa el precio por kilómetro
{
    return priceByKm;
}
void Avion::setPriceByKm(float _priceByKm)//define el precio por kilómetro
{
    priceByKm=_priceByKm;
}
string Avion::toString()//vuelve todo un string
{
    string msg="Avion:\t"+model+"\n";
    msg+="Lugares turista:\t"+to_string(capacityTourist)+"\n";
    msg+="Lugares primera clase:\t"+to_string(capacityFirst)+"\n";
    msg+="Precio por km:\t$"+to_string(priceByKm)+"MXN\n";
    return msg;
}
