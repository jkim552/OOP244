/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	// Custom Constructor
	MotorVehicle::MotorVehicle(const char* number1, int year1, const char* add) {
		strcpy(pnumber, number1);
		year = year1;
		if (add != nullptr) {
			strcpy(address, add);
		}
		else {
			strcpy(address, "Factory");
		}
	}
	
	// Move
	void MotorVehicle::moveTo(const char* add) {
		if (strcmp(address, add) != 0) {
			cout << "|" << setw(10) << pnumber;
			cout << "| |";
			cout << setw(20) << address;
			cout << " --->--- ";
			strcpy(address, add);
			cout << setw(20) << left << address;
			cout << "|" << endl;
			cout.unsetf(ios::left);
		}
	}
	// Copy address without printing
	void MotorVehicle::copy(const char* add) {
		strcpy(address, add);
	}

	// Write
	std::ostream& MotorVehicle::write(ostream& os) const {
		os << "| " << year << " | ";
		os << pnumber << " | " << address;
		return os;
	}
	// Read
	std::istream& MotorVehicle::read(istream& is){
		char temp_number[32];
		char temp_add[64];
		int temp_year;

		cout << "Built year: ";
		is >> temp_year;
		cout << "License plate: ";
		is >> temp_number;
		cout << "Current location: ";
		is >> temp_add;
		MotorVehicle temp(temp_number, temp_year, temp_add);
		*this = temp;
		return is;
	}

	// Operator<< (Calls write function)
	ostream& operator<<(ostream& os, const MotorVehicle& m) {
		m.write(os);
		return os;
	}

	// Operator>> (Calls read function)
	istream& operator>>(istream& is, MotorVehicle& m) {
		m.read(is);
		return is;
	}

	// Virtual Destructor & Constructor
	//MotorVehicle::MotorVehicle() {}
	MotorVehicle::~MotorVehicle() {}
}