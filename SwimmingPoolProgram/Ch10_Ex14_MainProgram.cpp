#include <iostream>
#include <iomanip>
#include "SwimmingPool.h"

using namespace std;

void printMainMenu();

int main() 
{
	int response;

	double _length;
	double _width;
	double _depth;

	SwimmingPool pool;

	cout << fixed << showpoint << setprecision(2);

	printMainMenu();
	
	cin >> response;

	switch(response)
	{
	case 1:
		//if (pool.hasDimensions())
		//	cout << "pool has dimensions";
		//else
		//{
			cout << "Enter pool dimensions:\n"
				<< "Length: ";
			cin >> _length;
			//pool.setLength(_length);

			cout << "\nWidth: ";
			cin >> _width;
			//pool.setWidth(_width);

			cout << "\nDepth: ";
			cin >> _depth;
			//pool.setDepth(_depth);
		//}

		break;
	case 2:
		cout << "";
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
	cout << response;
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