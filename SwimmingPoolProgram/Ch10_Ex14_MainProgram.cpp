#include <iostream>
#include <iomanip>
#include "SwimmingPool.h"

using namespace std;

void printMainMenu();
void printPoolVolume();
void printGetPoolVolume();

SwimmingPool pool;

double _length;
double _width;
double _depth;

double _currentWaterVolume;

bool _end;

int main() 
{
	int response;

	cout << fixed << showpoint << setprecision(1);

	while (!_end)
	{
		printMainMenu();

		cin >> response;

		switch (response)
		{
		case 1:
			if (pool.hasDimensions())
				printPoolVolume();
			else
			{
				printGetPoolVolume();
				printPoolVolume();
			}

			break;

		case 2:
			cout << "Water needed: "
				<< pool.getFillAmount(_currentWaterVolume);
			break;

		case 3:
			cout << "";
			break;

		case 4:
			cout << "";
			break;

		case 5:
			cout << "";
			break;
		}
	}

	system("pause");

	return EXIT_SUCCESS;
}

void printMainMenu()
{
	cout << "\n Type the number cooresponding to the task you would like to complete:\n\n\n"
		<< " 1) Set pool dimensions"
		<< endl
		<< " 2)	Determine water needed to fill pool to capacity\n\n"
		<< " Determine time required to:\n\n"
		<< " 3)	fill pool\n"
		<< " 4)	drain pool\n\n"
		<< " For a specific amount of time:\n\n"
		<< " 5)	fill pool\n"
		<< " 6)	drain pool\n\n"
		<< " Choice: ";
}

void printPoolVolume()
{
	cout << "\n Pool volume is "
		<< pool.getVolume()
		<< endl
		<< endl;
}

void printGetPoolVolume()
{
	cout << "\n Enter pool dimensions:"
		<< endl
		<< " Length: ";
	cin >> _length;
	pool.setLength(_length);

	cout << " Width: ";
	cin >> _width;
	pool.setWidth(_width);

	cout << " Depth: ";
	cin >> _depth;
	pool.setDepth(_depth);
}