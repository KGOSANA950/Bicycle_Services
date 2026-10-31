#include "Sale.h"

Sale::Sale()
{
    SaleId = 0;
    BikeId = 0;
    QuantitySold = 0;
    SaleDate = DateTime::Now;
    CostOfSale = 0.0;
    CommissionPercent = 0.0;
}

Sale::Sale(int _SaleId, int _BikeId, int _QuantitySold, DateTime _SaleDate, double _CostOfSale, double _CommissionPercent)
{
    this->SaleId = _SaleId;
    this->BikeId = _BikeId;
    this->QuantitySold = _QuantitySold;
    this->SaleDate = _SaleDate;
    this->CostOfSale = _CostOfSale;
    this->CommissionPercent = _CommissionPercent;
}

void Sale::setSaleId(int _SaleId)
{
    this->SaleId = _SaleId;
}

void Sale::setBikeId(int _BikeId)
{
    this->BikeId = _BikeId;
}

void Sale::setQuantitySold(int _QuantitySold)
{
    this->QuantitySold = _QuantitySold;
}

void Sale::setSaleDate(DateTime _SaleDate)
{
    this->SaleDate = _SaleDate;
}

void Sale::setCostOfSale(double _CostOfSale)
{
    this->CostOfSale = _CostOfSale;   
}

void Sale::setCommissionPercent(double _CommissionPercent)
{
    this->CommissionPercent = _CommissionPercent;
}

int Sale::getSaleId()
{
    return SaleId;
}

int Sale::getBikeId()
{
    return BikeId;
}

int Sale::getQuantitySold()
{
    return QuantitySold;
}

DateTime Sale::getSaleDate()
{
    return SaleDate;
}

double Sale::getCostOfSale()
{
    return CostOfSale;
}

double Sale::getCommissionPercent()
{
    return CommissionPercent;
}

double Sale::CalculateProfit(double pricePerUnit)
{
    // Profit = (Price x Sold) - (Cost x Sold) - (Price x Sold x Commission%)
    double revenue = pricePerUnit * QuantitySold;
    double cost = CostOfSale * QuantitySold;
    double commission = revenue * (CommissionPercent / 100.0);
    return revenue - cost - commission;
}

bool Sale::ValidateData()
{
    return (QuantitySold >= 0 && CostOfSale >= 0 && CommissionPercent >= 0);
}
