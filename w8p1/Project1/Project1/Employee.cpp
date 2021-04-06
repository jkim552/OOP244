/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
using namespace std;

namespace sdds {
	int Employee::getMinum() const {
		return minimum;
	}
	double Employee::getSalary(){
		return salaryHourly;
	}

	Employee::Employee(double hourly, int min) :
		minimum(getMinum()),
		salaryHourly(getSalary())
	{}

	double Employee::getSalary(int workedHours) {
		double s = getSalary();
		return s * workedHours;
	}

	ostream& Employee::display(ostream& out) {
		return out;
	}

	Employee::~Employee() {}

	ostream& operator<<(ostream& os, Employee& e) {
		e.display(os);
		return os;
	}
}