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
	void setFillRate(double);

	double getVolume();
	double getFillAmount(double);
	int getDrainTime();
	int getFillTime();

	double drain(int);
	double fill(int);

	bool hasDimensions();
};