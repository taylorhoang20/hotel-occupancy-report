#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	int totalFloors, numRooms, numOccupied;
	int totalRooms = 0, totalOccupied = 0;
	double occupancyRate; 

	cout << "Enter the number of floors in the hotel: ";
	cin >> totalFloors;

	while (totalFloors < 1)
	{
		cout << "Not a valid input. Please try again. ";
		cin >> totalFloors;
	}

	ofstream outfile("HotelReport.txt");

	if (!outfile)
	{
		cout << "Error opening file" << endl;
	}

	outfile << "Hotel Report" << endl << endl << endl;

	for (int floor = 1; floor <= totalFloors; ++floor)
	{
		cout << "Enter the number of rooms on the " << floor << " floor: ";
		cin >> numRooms;

		while (numRooms < 1)
		{
			cout << "Not a valid input. Please try again. ";
			cin >> numRooms;
		}

		cout << "Enter the number rooms that are occupid on the " << floor << " floor: ";
		cin >> numOccupied;

		while (numOccupied < 0 || numOccupied > numRooms)
		{
			cout << "Not a valid input. Please try again. ";
			cin >> numOccupied;
		}

		totalRooms += numRooms;
		totalOccupied += numOccupied;
	
		outfile << "Floor " << floor << ":" << endl;
		outfile << "Total number of rooms: " << numRooms << endl;
		outfile << "Total number of occupied rooms: " << numOccupied << endl;
		outfile << "Total number of rooms not occupied: " << numRooms - numOccupied << endl;
		outfile << fixed << setprecision(2);
		outfile << "Floor occupancy rate: " << (double)numOccupied / numRooms * 100 << "%" << endl << endl;
	}

	occupancyRate = (double)totalOccupied / totalRooms * 100;

	outfile << "\nTotals Report" << endl << endl;
	outfile << "Total floors: " << totalFloors << endl;
	outfile << "Total rooms: " << totalRooms << endl;
	outfile << "Total number of occupied rooms: " << totalOccupied << endl;
	outfile << "Total number of rooms not occupied: " << totalRooms - totalOccupied << endl;
	outfile << fixed << setprecision(2);
	outfile << "Total occupancy rate: " << occupancyRate << "%" << endl;

	outfile.close();


	return 0;
}