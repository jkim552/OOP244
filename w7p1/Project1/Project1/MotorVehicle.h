/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_MOTORVEHICLE_H //header guard
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds {
	class MotorVehicle {
	private:
		char pnumber[32];
		char address[64];
		int year;
	public:
		MotorVehicle(const char* number1, int year1, const char* add = nullptr);
		void moveTo(const char* add);
		void copy(const char* add);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
		//MotorVehicle();
		virtual ~MotorVehicle();
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& m);
	std::istream& operator>>(std::istream& is, MotorVehicle& m);
}
#endif
