/*
* Chad Lewis
* 09/5/2015
* CSC 161 C01
*/

#include "SwimmingPool.h"
using namespace std;


// Default constructor
SwimmingPool::SwimmingPool() 
{ 
	_length = 0;
	_width = 0;
	_depth = 0;
}

// Basic constructor defined with member initialization
SwimmingPool::SwimmingPool (double l, double w, double d) :_length(l), _width(w), _depth(d)
{
	// Assign to the instance variables the arguments passed to constructo

	_volume = _length * _width * _depth;
}

// Full Constructor
SwimmingPool::SwimmingPool(double length, double width, double depth, double fillRate, double drainRate)
{
	// Assign to the instance variables the arguments passed to constructor
	_length = length;
	_width = width;
	_depth = depth;
	_fillRate = fillRate;
	_drainRate = drainRate;

	_volume = getVolume();
	// Get the volume 
}

void SwimmingPool::setLength(double l)
{
	_length = l;
}

void SwimmingPool::setWidth(double w)
{
	_width = w;
}

void SwimmingPool::setDepth(double d)
{
	_depth = d;
}

void SwimmingPool::setDrainRate(double r)
{
	_drainRate = r;
}

double SwimmingPool::getDrainRate()
{
	return _drainRate;
}

void SwimmingPool::setFillRate(double r)
{
	_fillRate = r;
}

double SwimmingPool::getFillRate()
{
	return _fillRate;
}

void SwimmingPool::setFillTime(int t)
{
	_fillTime = t;
}

void SwimmingPool::setDrainTime(int t)
{
	_drainTime = t;
}
// Member function to calculate volume
double SwimmingPool::getVolume() 
{
	// No need to check values of instance variables

	// Return the volume
	return _length * _width * _depth;
}

void SwimmingPool::setWaterVolume(double v)
{
	_waterVolume = v;
}
double SwimmingPool::getWaterVolume()
{
	return _waterVolume;
}

// Returns amount of water needed to fill an empty or partially filled pool
double SwimmingPool::getFillAmount(double currentWaterVolume)
{

	return getVolume() - currentWaterVolume;
}

// Returns time needed to completely or partially drain the pool
int SwimmingPool::getDrainTime() 
{
	return (int)(_waterVolume/_drainRate);
}

// Returns the time need to completely or partially drain the pool
int SwimmingPool::getFillTime()
{
	return (int)(getVolume()/_fillRate);
}

// Drain the pool for a specified time period
// Returns adjusted water volume
double SwimmingPool::drain()
{
	double waterDrained = _drainRate * _drainTime;
	
	_waterVolume -= waterDrained;
	if (_waterVolume < 0)
		_waterVolume = 0;
	return waterDrained;
}

double SwimmingPool::fill()
{
	_waterVolume += _fillRate * _fillTime;
	return _waterVolume;
} 

// Fill the pool for a specified time period
// Returns adjusted water volume
double SwimmingPool::fill(int time)
{
	return 0;
}



bool SwimmingPool::hasDimensions()
{
	if (_length > 0 && _width > 0 && _depth > 0)
		return true;
	else
		return false;
}

bool SwimmingPool::hasWater()
{
	if (_waterVolume > 0)
		return true;
	else
		return false;
}