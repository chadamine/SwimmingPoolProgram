#include <iostream>
#include <iomanip>
#include "SwimmingPool.h"

using namespace std;

void printMainMenu();
void printPoolVolume();
void printGetPoolVolume(bool);
void printHasDimensions();
void printError();
double editValue(double);

SwimmingPool pool;

int _response;
int _numResponses;

double _length;
double _width;
double _depth;
double _currentWaterVolume;

bool _end;

char _newValue[5];


int main() 
{
	cout << fixed << setprecision(0);

	while (!_end)
	{
		printMainMenu();

		switch (_response)
		{
		case 1:
			if (pool.hasDimensions())
				printHasDimensions();
			else
			{
				printGetPoolVolume(false);
				printPoolVolume();
			}

			break;
		case 2:

			break;

		case 3:
			if (pool.hasWater()) {
				cout << "Water needed: "
					<< pool.getFillAmount(_currentWaterVolume);
			}
			break;

		case 4:
			cout << "";
			break;

		case 5:
			cout << "";
			break;

		case 6:
			cout << "";
			break;
		default:
			printError();
			break;
		}
	}

	system("pause");

	return EXIT_SUCCESS;
}

void printMainMenu()
{
	_numResponses = 6;

	cout << "\n Type the number cooresponding to the task you would like to complete:\n\n\n"
		<< " 1)	Set pool dimensions"
		<< endl
		<< " 2)	Print pool dimensions"
		<< " 3)	Determine water needed to fill pool to capacity\n\n"
		<< " Determine time required to:\n\n"
		<< " 4)	fill pool\n"
		<< " 5)	drain pool\n\n"
		<< " For a specific amount of time:\n\n"
		<< " 6)	fill pool\n"
		<< " 7)	drain pool\n\n"
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

void printGetPoolVolume(bool edit)
{

	cout << "\n Enter pool dimensions:"
		<< endl
		<< " Length: ";
	if (edit)
		editValue(_length);
	cin >> _length;
	pool.setLength(_length);
	cout << _length
		<< " saved";

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

	cout << "The pool already has dimensions"
		<< endl
		<< endl
		<< "1)	Create new dimensions"
		<< endl
		<< "2)	Edit current dimensions"
		<< endl 
		<< endl
		<< "Response: ";

	cin >> _response;

	switch (_response)
	{
	case 1:
		printGetPoolVolume(false);
		break;
	case 2:
		// Print pool dimensions prompt with existing values
		printGetPoolVolume(true);
		break;
	case 3:
		printMainMenu();
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
		<< "You entered an invalid response, please try again"
		<< endl
		<< endl;
}
