/* ------------------------------------------------------
Final Project Milestone 5
Module: Car
Filename: Car.h
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/27  Preliminary release
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		bool carWashFlag;
	public:
		Car();											// Vehicle()
		Car(const char* num, const char* model);		// Vehicle(const char*, const char*)
		Car(const Car& car) = delete;					// Can't copy
		Car& operator=(const Car& car) = delete;		// Can't Assign
		std::istream& read(std::istream& is);			// Read
		std::ostream& write(std::ostream& os) const;	// Write
		bool DoCarWash() const;
	};
}
#endif