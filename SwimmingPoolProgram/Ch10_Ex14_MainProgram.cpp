/*
* Chad Lewis
* 09/5/2015
* CSC 161 C01
*/

#include <iostream>
#include <iomanip>
#include "SwimmingPool.h"

using namespace std;

void printMainMenu();
void printPoolVolume();
void printGetPoolDimensions(bool);
void printHasDimensions();
void checkDimensions();
void printError();
void printPoolDimensions();
double editValue(double);
void printGetFillRate();
void printGetDrainRate();
void printAddWater();
void printDrainRate();
void printFillRate();
char printWantWater();

SwimmingPool pool;

int _response;
int _numResponses;

double _length;
double _width;
double _depth;
//double _currentWaterVolume;
double _drainRate;
double _fillRate;

bool _end;

char _newValue[5];


int main() 
{
	int fillTime;
	int drainTime;
	double drained;

	// Set output style and precision
	cout << fixed << showpoint << setprecision(2);

	// Main program loop
	//	ends when _end==true
	while (!_end)
	{
		// Prints main option list
		printMainMenu();

		// Switch based on response
		switch (_response)
		{

		// Sets pool dimensions
		case 1:
			if (pool.hasDimensions())
				printHasDimensions();
			else
			{
				printPoolDimensions();
				printPoolVolume();
			}

			break;

		// Prints pool dimensions
		case 2:
			printGetPoolDimensions(false);
			system("pause");
			break;

		// Prints fill rate
		case 3:
			printGetFillRate();
			break;

		// Prints drain rate
		case 4:
			printGetDrainRate();
			break;

		// Determine water need to fill pool to capacity
		case 5:
			checkDimensions();
			
			if (!pool.hasWater())
				cout << "\n The pool is currently empty";
			else
			{
				cout << " The pool currently has "
					<< pool.getWaterVolume()
					<< " units"
					<< endl;
			}
			cout << "\n\n Water needed: "
				<< pool.getFillAmount(pool.getWaterVolume())
				<< " units of water\n\n";
			system("pause");
		
			break;

		// Determine time required to fill pool at rate
		case 6:
			if (!pool.hasDimensions())
			{
				cout << " Pool dimensions not yet entered.\n";
				printGetPoolDimensions(false);
			}

			if (pool.getFillRate() <= 0)
				printGetFillRate();

			cout << "\n Time to fill pool: "
				<< pool.getFillTime()
				<< endl
				<< endl;

			system("pause");
			break;

		// Determine time required to drain pool at rate
		case 7:
			checkDimensions();

			if (_drainRate <= 0)
				printGetDrainRate();

			if (!pool.hasWater())
			{
				
				char response = printWantWater();

				while (response != 'y' && response != 'n')
				{
					printError();
					response = printWantWater();
				}

				if (response == 'y')
					printAddWater();
				else
					break;;
			}
			
				cout << "\n Time to drain pool: "
					<< pool.getDrainTime()
					<< endl
					<< endl;
			

			system("pause");
			break;

		case 8:
			checkDimensions();

			if (pool.getFillRate() <= 0)
				printGetFillRate();
			else
				printFillRate();

			cout << "\n Enter fill time: ";
			cin >> fillTime;

			pool.setFillTime(fillTime);
			pool.setWaterVolume(pool.getWaterVolume() + pool.fill());

			cout << endl
				<< pool.fill()
				<< " units of water were added to the pool\n\n"
				<< " The pool now contains "
				<< pool.getWaterVolume()
				<< " units of water\n\n";

			system("pause");
			break;

		case 9:
			checkDimensions();

			if (pool.getDrainRate() <= 0)
				printGetDrainRate();
			else
				printDrainRate();

			cout << "\n Enter drain time: ";
			cin >> drainTime;
			pool.setDrainTime(drainTime);

			if (!pool.hasWater())
			{
				char response = printWantWater();

				while (response != 'y' && response != 'n')
				{
					printError();
					response = printWantWater();
					cout << "\n\n Response is "
						<< response;
				}

				if (response == 'y')
					printAddWater();
				else
					break;

			}

			drained = pool.drain();
			cout << endl
				<< " "
				<< drained
				<< " units of water were removed from the pool\n\n"

				<< " The pool now contains "
				<< pool.getWaterVolume()
				<< " units of water\n\n";

			system("pause");
			break;
		case 10:
			_end = true;
			break;

		default:
			printError();
			break;
		}
	}

	return EXIT_SUCCESS;
}

void printMainMenu()
{
	_numResponses = 6;

	cout << "\n Type the number cooresponding to the task you would like to complete:\n\n\n"
		<< " 1)	Set pool dimensions\n"
		<< " 2)	Print pool dimensions\n"
		<< " 3)	Set fill rate\n"
		<< " 4)	Set drain rate\n"
		<< " Print fill and drain rates\n"
		<< " Add water to pool\n"
		<< " Remove water from pool\n"
		<< " 5)	Determine water needed to fill pool to capacity\n\n"
		<< " Determine time required to:\n\n"
		<< " 6)	fill pool\n"
		<< " 7)	drain pool\n\n"
		<< " For a specific amount of time:\n\n"
		<< " 8)	fill pool\n"
		<< " 9)	drain pool\n"
		<< " 10)	Exit Program\n\n"
		<< " Choice: ";

	cin >> _response;
}

void printPoolVolume()
{
	cout << "\n Pool volume is "
		<< pool.getVolume()
		<< endl
		<< endl;
}

void printGetPoolDimensions(bool edit)
{
	cout << "\n Enter pool dimensions:"
		<< endl
		<< " Length: ";
	if (edit)
		editValue(_length);
	cin >> _length;
	pool.setLength(_length);

	cout << " Width: ";
	if (edit)
		editValue(_width);
	cin >> _width;
	pool.setWidth(_width);

	cout << " Depth: ";
	if (edit)
		editValue(_depth);
	cin >> _depth;
	pool.setDepth(_depth);

	printPoolVolume();
}

double editValue(double value)
{
	cout << value;
	cin.seekg(0, cin.beg);
	cin.getline(_newValue, 5);
	return atof(_newValue);
}

void printHasDimensions()
{
	_numResponses = 2;

	cout << " The pool already has dimensions"
		<< endl
		<< endl
		<< "1)	Create new dimensions"
		//<< endl
		//<< "2)	Edit current dimensions"
		<< endl 
		<< "2)	Return to main menu"
		<< endl
		<< "Response: ";

	cin >> _response;

	switch (_response)
	{
	case 1:
		printGetPoolDimensions(false);
		break;
	//case 2:
	//	// Print pool dimensions prompt with existing values
	//	printGetPoolDimensions(true);
	//	break;
	case 2:
		printMainMenu();
		break;
	default:
		printError();
		printHasDimensions();
		break;
	}
}

// Function that prints an error when invalid option entered at menu
void printError()
{
	cout << "\a"	// make an error sound 
		// print error
		<< " You entered an invalid response, please try again"
		<< endl
		<< endl;
}

void printPoolDimensions()
{
	cout << "\n\nPool Dimensions\n\n" 
		<< " Length: "
		<< _length
		<< endl
		<< " Width: "
		<< _width
		<< endl
		<< " Depth: "
		<< _depth
		<< endl
		<< endl;

	printPoolVolume();
}

void checkDimensions()
{
	if (!pool.hasDimensions())
		{
			cout << " Pool dimensions not yet entered.\n";
			printGetPoolDimensions(false);
		}
}

void printGetFillRate()
{
	cout << "\n Enter the fill rate: ";
	cin >> _fillRate;
	pool.setFillRate(_fillRate);
}

void printGetDrainRate()
{
	cout << " Enter the drain rate: ";
	cin >> _drainRate;
	pool.setDrainRate(_drainRate);
}

void printAddWater()
{
	double currentWaterVolume;

	cout << " How much water would you like to add?\n\n"
		<< " Response: ";
	cin >> currentWaterVolume;
	if (currentWaterVolume > pool.getVolume())
	{
		currentWaterVolume = pool.getVolume();
		cout << "\n You entered more than the pool could hold ("
			<< pool.getVolume()
			<< ") but I fixed that for you.\n";
	}
	pool.setWaterVolume(currentWaterVolume);
}

void printDrainRate()
{
	cout << " Drain rate is currently: "
		<< pool.getDrainRate()
		<< endl
		<< endl;
}

void printFillRate()
{
	cout << " Fill rate is currently: "
		<< pool.getFillRate()
		<< endl
		<< endl;
}

char printWantWater()
{
	char response;

	cout << " The pool has no water to drain!\n"
		<< " Would you like to add water?"
		<< endl
		<< endl
		<< " Response: ";
	cin >> response;

	return response;
}