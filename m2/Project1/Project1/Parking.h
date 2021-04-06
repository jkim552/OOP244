/* Citation and Sources...
Final Project Milestone 1
Module: Parking
Filename: Parking.h
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/13 Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"
#include "Utils.h"

namespace sdds {
	class Parking {
	private:
		char* filename;
		Menu* parking;
		Menu* vehicle;
		bool isEmpty() const;
		void displayStatus() const;
		void parkVehicle() const;
		void returnVehicle() const;
		void listParked() const;
		bool closeParking() const;
		bool exitParking() const;
		bool loadFile() const;
		void saveFile() const;
	public:
		Parking(const char* nam);
		~Parking();
		Parking(const Parking& pk) = delete;
		Parking& operator=(const Parking& pk) = delete;
		int run() const;

	};

}


#endif