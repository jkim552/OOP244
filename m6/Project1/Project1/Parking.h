/* Citation and Sources...
Final Project Milestone 6
Module: Parking
Filename: Parking.h
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/13 Preliminary release
2020/07/28 Reused on M6
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"
#include "Utils.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
namespace sdds {
	const int MAXNUMSPOT = 100;
	class Parking {
	private:
		int numOfSpots;
		Vehicle* parkingSpots[MAXNUMSPOT];
		int numOfParkedV;

		char* filename;
		Menu* parking;
		Menu* vehicle;
		bool isEmpty() const;
		void displayStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParked() const;
		bool closeParking();
		bool exitParking() const;
		bool loadFile();
		void saveFile() const;
	public:
		Parking(const char* nam, int num);
		~Parking();
		Parking(const Parking& pk) = delete;
		Parking& operator=(const Parking& pk) = delete;
		int run();

	};

}


#endif