#pragma once
using namespace System;


ref class Sale
{
private:
	int SaleId;
	int BikeId;
	int QuantitySold;
	DateTime SaleDate;
	double CostOfSale;
	double CommissionPercent;

public:
	Sale();
	Sale(int _SaleId, int _BikeId, int _QuantitySold, DateTime _SaleDate, double _CostOfSale, double _CommissionPercent);

	//setters
	void setSaleId(int _SaleId);
	void setBikeId(int _BikeId);
	void setQuantitySold(int _QuantitySold);
	void setSaleDate(DateTime _SaleDate);
	void setCostOfSale(double _CostOfSale);
	void setCommissionPercent(double _CommissionPercent);

	//getters
	int getSaleId();
	int getBikeId();
	int getQuantitySold();
	DateTime getSaleDate();
	double getCostOfSale();
	double getCommissionPercent();

	// Methods
	double CalculateProfit(double pricePerUnit);
	bool ValidateData();
};

