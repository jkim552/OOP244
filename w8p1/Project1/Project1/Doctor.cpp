/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Doctor.h"
using namespace std;

namespace sdds {
	Doctor::Doctor(char* doc, double hourly, int min, bool special) :
		Employee(hourly,min)
	{
		strcpy(type, doc);
		isSpecialist = special;
	}

	double Doctor::getSalary(int workedHours) {
		double sal;
		if (workedHours <= getMinum()) {
			sal = Employee::getSalary(workedHours);
		}
		else {
			int overtime = workedHours - getMinum();
			sal = overtime * Employee::getSalary() *1.5;
			sal += Employee::getSalary(getMinum());
		}
		if (isSpecialist) {
			sal += 2000;
		}
		return sal;
	}

	ostream& Doctor::display(ostream& out){
		out << "Doctor" << endl;
		out << "Type: ";
		if (isSpecialist) {
			out << type << " (specialist)" << endl;
		}
		else {
			out << type << endl;
		}
		out << "Pay Rate: " << Employee::getSalary() << endl;
		out << "Min Hours: " << Employee::getMinum() << endl;
		return out;
	}
}