/* ------------------------------------------------------
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/20  Preliminary release
-----------------------------------------------------------*/
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

namespace sdds {
	class Vehicle : public ReadWritable {
		char plateNum[9];
		char* makeModel;
		int spotNum;
	protected:
		void setEmpty();											// Invalid Empty state
		bool isEmpty() const;										// True if empty else false
		const char* getLicensePlate() const;						// Read only address (pointer) of license plate
		const char* getMakeModel() const;							// Read only address (pointer) of make and model
		void setMakeModel(const char* model);						// if parameter is null, setEmpty();
	public:
		Vehicle();													// Safe Invalid Empty State (setEmpty();)
		Vehicle(const char* num, const char* model);				// Copy these values and spotNum = 0; else, setEmpty();
		Vehicle(const Vehicle& vi) = delete;						// Can't copy
		Vehicle& operator=(const Vehicle& vi) = delete;				// Can't assign
		virtual ~Vehicle();											// Destructor
		int getParkingSpot() const;									// Returns parking spot number
		void setParkingSpot(int num);								// if parameter is null, setEmpty();
		friend bool operator==(const Vehicle&, const Vehicle&);
		friend bool operator==(const Vehicle& ve, const char* num);
		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;
	};
	bool operator==(const Vehicle&, const Vehicle&);
	bool operator==(const Vehicle& ve, const char* num);
}
#endif