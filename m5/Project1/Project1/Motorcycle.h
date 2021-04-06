/* ------------------------------------------------------
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/27  Preliminary release
-----------------------------------------------------------*/
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include "Vehicle.h"

namespace sdds {
	class Motorcycle : public Vehicle {
		bool hasSideCar;
	public:
		Motorcycle();												// Vehicle()
		Motorcycle(const char* num, const char* model);				// Vehicle(const char*, const char*)
		Motorcycle(const Motorcycle& motor) = delete;					// Can't copy
		Motorcycle& operator=(const Motorcycle& motor) = delete;		// Can't Assign
		std::istream& read(std::istream& is);			// Read
		std::ostream& write(std::ostream& os) const;	// Write
		bool sideCar() const;
	};
}

#endif // ! SDDS_MOTORCYCLE_H
