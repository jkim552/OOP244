/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include <iostream>
#include "Employee.h"

namespace sdds {
	class Doctor : Employee{
	private:
		char type[32];
		bool isSpecialist;
	public:
		Doctor(char* doc, double hourly, int min, bool special = false);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
	};



}


#endif // !SDDS_DOCTOR_H
