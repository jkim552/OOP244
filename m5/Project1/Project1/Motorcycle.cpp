/* ------------------------------------------------------
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/27  Preliminary release
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Motorcycle.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	Motorcycle::Motorcycle() : Vehicle() {
		hasSideCar = false;
	}

	Motorcycle::Motorcycle(const char* num, const char* model) : Vehicle(num, model) {
		hasSideCar = false;
	}

	bool Motorcycle::sideCar() const {
		bool ok = true;
		bool val = true;
		char yn;
		char newline;
		const char invalid[] = "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
		cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
		do {
			cin >> yn;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				cout << invalid;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = false;
				if (yn == 'Y' || yn == 'y') {
					val = true;
				}
				else if (yn == 'N' || yn == 'n') {
					val = false;
				}
				else {
					cout << invalid;
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
		} while (ok);
		return val;
	}

	istream& Motorcycle::read(istream& is) {
		if (isCsv()) {
			Vehicle::read(is);
			is >> hasSideCar;
			is.ignore(5000, '\n');
		}
		else {
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(is);
			hasSideCar = sideCar();
		}
		return is;
	}

	ostream& Motorcycle::write(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (isCsv()) {
				os << "M,";
				Vehicle::write(os);
				os << hasSideCar << endl;
			}
			else {
				os << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(os);
				if (hasSideCar) {
					os << "With Sidecar" << endl;
				}
			}
		}
		return os;
	}


}