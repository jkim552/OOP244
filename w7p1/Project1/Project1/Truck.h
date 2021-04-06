/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_TRUCK_H //header guard
#define SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"
namespace sdds {
	class Truck : public MotorVehicle {
	private:
		double maxCapacity;
		double capacity;
		bool de_fault;
	public:
		Truck(const char* number1, int year1, float maxC, const char* add, float cap = 0, bool def = false);
		bool addCargo(double cargo);
		bool unloadCargo();
		void write(std::ostream& os) const;
		void read(std::istream& is);
		virtual ~Truck();

	};
	std::ostream& operator<<(std::ostream& os, const Truck& t);
	std::istream& operator>>(std::istream& is, Truck& t);
}
#endif