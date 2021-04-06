/* ------------------------------------------------------
Final Project Milestone 5
Module: Car
Filename: Car.cpp
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/27  Preliminary release
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	Car::Car() : Vehicle() {
		carWashFlag = false;
	}

	Car::Car(const char* num, const char* model) : Vehicle(num, model) {
		carWashFlag = false;
	}

	bool Car::DoCarWash() const {
		bool ok = true;
		bool val = true;
		char yn;
		char newline;
		const char invalid[] = "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
		cout << "Carwash while parked? (Y)es/(N)o: ";
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

	istream& Car::read(istream& is) {
		if (isCsv()) {
			Vehicle::read(is);
			is >> carWashFlag;
			is.ignore(5000, '\n');
		}
		else {
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(is);
			carWashFlag = DoCarWash();
		}
		return is;
	}

	ostream& Car::write(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {
				os << "C,";
				Vehicle::write(os);
				os << carWashFlag << endl;
			}
			else {
				os << "Vehicle type: Car" << endl;
				Vehicle::write(os);
				if (carWashFlag) {
					os << "With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}
		return os;
	}


}