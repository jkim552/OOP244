/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream>

namespace sdds {
	class Employee {
	private:
		const int minimum;
		double salaryHourly;
	protected:
		int getMinum() const;
		double getSalary();
	public:
		Employee(double hourly, int min);
		double getSalary(int workedHours);
		std::ostream& display(std::ostream& out);
		virtual ~Employee();
	};
	std::ostream& operator<<(std::ostream& os, Employee& e);
}





#endif