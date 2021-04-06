/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
	// Constructor with parameters
	Truck::Truck(const char* number1, int year1, float maxC, const char* add, float cap, bool def)
		: MotorVehicle(number1, year1) 
	{
		maxCapacity = maxC;
		capacity = cap;
		de_fault = def;
		// Alternate constructor if there is a user input
		if (def == true) {
			copy(add);
		}
		else {
			moveTo(add);
		}
	}

	// addCargo
	bool Truck::addCargo(double cargo) {
		bool changed = false;
		if (maxCapacity > capacity) {
			capacity += cargo;
			if (capacity > maxCapacity) {
				capacity = maxCapacity;
			}
			changed = true;
		}
		return changed;
	}

	// unloadCargo
	bool Truck::unloadCargo() {
		bool unloaded = false;
		if (capacity > 0) {
			capacity = 0;
			unloaded = true;
		}
		return unloaded;
	}
	void Truck::write(std::ostream& os) const {
		MotorVehicle::write(os);
		os.precision(0);
		os << fixed << " | " << capacity << "/" << maxCapacity;
	}
	void Truck::read(std::istream& is) {
		int temp_year;
		char temp_num[32];
		char temp_add[64];
		double temp_maxCap;
		double temp_cap;

		cout << "Built year: ";
		is >> temp_year;
		cout << "License plate: ";
		is >> temp_num;
		cout << "Current location: ";
		is >> temp_add;
		cout << "Capacity: ";
		is >> temp_maxCap;
		cout << "Cargo: ";
		is >> temp_cap;
		Truck temp(temp_num, temp_year, temp_maxCap, temp_add, temp_cap, true);
		*this = temp;
	}
	// Virtual Destructor
	Truck::~Truck() {}

	// Operator <<
	ostream& operator<<(ostream& os, const Truck& t) {
		t.write(os);
		return os;
	}
	
	// Operator >> 
	istream& operator>>(istream& is, Truck& t) {
		t.read(is);
		return is;
	}
}