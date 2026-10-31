#include "Bicycle.h"
#include "Sale.h"

using namespace System;

Bicycle::Bicycle()
{
    BikeId = 0;
    BikeName = "";
    Price = 0.0;
    AvailableStock = 0;
}

Bicycle::Bicycle(int _BikeId, String^ _BikeName, double _Price, int _AvailableStock, String^ _ImagePath)
{
    this->BikeId = _BikeId;
    this->BikeName = _BikeName;
    this->Price = _Price;
    this->AvailableStock = _AvailableStock;
    this->ImagePath = _ImagePath;
}

void Bicycle::setBikeId(int _BikeId)
{
    this->BikeId = _BikeId;
}

void Bicycle::setBikeName(String^ _BikeName)
{
    this->BikeName = _BikeName;
}

void Bicycle::setPrice(double _Price)
{
    this->Price = _Price;
}

void Bicycle::setAvailableStock(int _AvailableStock)
{
    this->AvailableStock = _AvailableStock;
}

void Bicycle::setImagePath(String^ _ImagePath)
{
    this->ImagePath = _ImagePath;
}

int Bicycle::getBikeId()
{
    return BikeId;
}

String^ Bicycle::getBikeName()
{
    return BikeName;
}

double Bicycle::getPrice()
{
    return Price;
}

int Bicycle::getAvailableStock()
{
    return AvailableStock;
}

String^ Bicycle::getImagePath()
{
    return ImagePath;
}

double Bicycle::CalculateProfit(int sold, double costPerUnit, double commissionPct)
{
    // Profit = (Price x Sold) - (Cost x Sold) - (Price x Sold x Commission%)
    double revenue = Price * sold;
    double cost = costPerUnit * sold;
    double commission = revenue * (commissionPct / 100.0);
    return revenue - cost - commission;
}



bool Bicycle::ValidateData()
{
    return (Price >= 0 && AvailableStock >= 0 && BikeName != nullptr && BikeName->Length > 0);
}
