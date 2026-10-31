#pragma once
using namespace System;

public ref class Bicycle
{
private:
	int BikeId;
	String^ BikeName;
	double Price;
	int AvailableStock;
	String^ ImagePath;

public:
	Bicycle();
	Bicycle(int _BikeId, String^ _BikeName, double _Price, int _AvailableStock, String^ _ImagePath);

	//setters
	void setBikeId(int _BikeId);
	void setBikeName(String^ _BikeName);
	void setPrice(double _Price);
	void setAvailableStock(int _AvailableStock);
	void setImagePath(String^ _ImagePath);

	//getters
	int getBikeId();
	String^ getBikeName();
	double getPrice();
	int getAvailableStock();
	String^ getImagePath();

	// Methods
	double CalculateProfit(int sold, double costPerUnit, double commissionPct);
	bool ValidateData();

};

