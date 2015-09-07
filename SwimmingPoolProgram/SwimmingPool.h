/*
* Chad Lewis
* 09/5/2015
* CSC 161 C01
*/

#pragma once
class SwimmingPool
{

public:
	SwimmingPool();
	SwimmingPool(double, double, double);
	SwimmingPool(double, double, double, double, double);

	void setLength(double);
	void setWidth(double);
	void setDepth(double);
	void setDrainRate(double);
	double getDrainRate();
	void setFillRate(double);
	double getFillRate();
	void setFillTime(int);
	void setDrainTime(int);
	void setWaterVolume(double);

	double getVolume();
	double getWaterVolume();
	double getFillAmount(double);
	int getDrainTime();
	int getFillTime();

	double drain();

	double fill();
	double fill(int);

	bool hasDimensions();
	bool hasWater();

private:
	double _length;
	double _width;
	double _depth;
	double _fillRate;
	double _drainRate;
	int _fillTime;
	int _drainTime;

	double _volume;
	double _waterVolume;
};