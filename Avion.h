#ifndef AVION_H
#define AVION_H
#include<iostream>
#include<string>
using namespace std;
//Creo un avión que define lugares y precio

class Avion
{
    public:
        Avion();
        virtual ~Avion();
        int getCapacityFirst();//regresa los lugares de primera clase
        int getCapacityTourist();//lo mismo pero con clase turista
        void setCapacityFirst(int _capacityFirst);//define lugares 1a clase
        void setCapacityTourist(int _capacityTourist);//define lugares turista
        string getModel();//regresa el modelo
        void setModel(string _model);//define el modelo
        float getPriceByKm();//regresa el precio por kilómetro
        void setPriceByKm(float _priceByKm);//define el precio por kilómetro
        string toString();//vuelve todo un string

    protected:

    private:
        int capacityFirst;
        int capacityTourist;
        string model;
        float priceByKm;

};

#endif // AVION_H
