/* ------------------------------------------------------
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.cpp
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/20  Preliminary release
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Vehicle.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	/* Public Constructor */
	Vehicle::Vehicle() {
		plateNum[0] = '\0';
		makeModel = nullptr;
		spotNum = 0;
		// setEmpty();
	}
	/* Constructor with paramters */
	Vehicle::Vehicle(const char* num, const char* model) {
		if (!num || !model || num[0] == '\0' || strlen(num) > 8 || strlen(model) < 2) {
			makeModel = nullptr;
			setEmpty();
		}
		else {
			strcpy(plateNum, num);
			Utils::toUpperCase(plateNum);
			makeModel = new char[strlen(model) + 1];
			strcpy(makeModel, model);
			spotNum = 0;
		}
	}

	/* Destructor */
	Vehicle::~Vehicle() {
		delete[] makeModel;
		makeModel = nullptr;
	}

	/*-----------------------Protected Member Function-------------------------*/
	/* setEmpty() */
	void Vehicle::setEmpty() {
		if (makeModel != nullptr) {
			delete[] makeModel;
		}
		plateNum[0] = '\0';
		makeModel = nullptr;
		spotNum = 0;
	}
	/* isEmpty() */
	bool Vehicle::isEmpty() const {
		return (plateNum[0] == '\0' && !makeModel && spotNum == 0);
	}
	/* getLicensePlate() */
	const char* Vehicle::getLicensePlate() const {
		return plateNum;
	}
	/* getMakeModel() */
	const char* Vehicle::getMakeModel() const {
		return makeModel;
	}
	/* setMakeModel() */
	void Vehicle::setMakeModel(const char* model) {
		if (!model || strlen(model) < 2) {
			setEmpty();
		}
		else {
			if (getMakeModel() != nullptr) {
				delete[] makeModel;
				makeModel = nullptr;
			}
			int len = strlen(model);
			makeModel = new char[len + 1];
			strcpy(makeModel, model);
		}
	}
	/*-----------------------------------------------------------------------*/

	/*-----------------------Pulbic Member Function--------------------------*/
	/* getParkingSpot() */
	int Vehicle::getParkingSpot() const {
		return spotNum;
	}
	/* setParkingSpot() */
	void Vehicle::setParkingSpot(int num) {
		if (num < 0) {
			setEmpty();
		}
		else {
			spotNum = num;
		}
	}
	/* bool operator== for char comparison */
	bool operator==(const Vehicle& ve, const char* num) {
		char num2[9];
		bool val = false;
		for (unsigned int i = 0; i < strlen(num); i++) {
			if (num[i] >= 97 && num[i] <= 122) {
				num2[i] = num[i] - 32;
			}
			else {
				num2[i] = num[i];
			}
		}
		if (strncmp(ve.getLicensePlate(), num2, strlen(num)) == 0) {
			val = true;
		}
		return val;
	}
	/* bool operator== for class comparison */
	bool operator==(const Vehicle& a, const Vehicle& b) {
		return (a == b.getLicensePlate());
	}
	
	istream& Vehicle::read(istream& is) {
		// Comma seperated mode
		if (isCsv()) {
			is >> spotNum;
			if (is.fail()) {
				is.clear();
				//is.ignore(5000, '\n');   Done in tester file
				setEmpty();
			}
			else {
				is.ignore(); // eat ,
				string plate;
				getline(is, plate, ',');
				if (is.fail()) {
					is.clear();
					//is.ignore(5000, '\n');  Done in tester file
					setEmpty();
				}
				else {
					strncpy(plateNum, plate.c_str(), 8);
					plateNum[8] = '\0';
					Utils::toUpperCase(plateNum);
					string model;
					getline(is, model, ',');
					if (is.fail()) {
						is.clear();
						//is.ignore(5000, '\n'); Done in tester file
						setEmpty();
					}
					else {
						char model2[61];
						strncpy(model2, model.c_str(), 60);
						model2[60] = '\0';
						setMakeModel(model2);
					}
				}
			}
		}
		// Not comma seperated mode
		else {
			int isContinue = 1;
			string tempPlate;
			cout << "Enter Licence Plate Number: ";
			do {
				is >> tempPlate;
				if (is.fail()) {
					is.clear();
					is.ignore(5000, '\n');
					setEmpty();
					isContinue = 0;
				}
				else if (tempPlate.length() > 8) {
					cout << "Invalid Licence Plate, try again: ";
				}
				else {
					strcpy(plateNum, tempPlate.c_str());
					Utils::toUpperCase(plateNum);
					isContinue = 0;
				}
			} while (isContinue);

			cout << "Enter Make and Model: ";
			isContinue = 1;
			string tempModel;
			do {
				is.ignore(); // eat
				getline(is, tempModel);
				if (is.fail()) {
					is.clear();
					is.ignore(5000, '\n');
					setEmpty();
					isContinue = 0;
				}
				else if (tempModel.length() < 2 || tempModel.length() > 60) {
					cout << "Invalid Make and model, try again: ";
				}
				else {
					setMakeModel(tempModel.c_str());
					isContinue = 0;
				}
			} while (isContinue);

		}
		return is;
	}

	ostream& Vehicle::write(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				os << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
			}
			else {
				os << "Parking Spot Number: ";
				if (getParkingSpot() == 0) {
					os << "N/A" << endl;
				}
				else {
					os << getParkingSpot() << endl;
				}
				os << "Licence Plate: " << getLicensePlate() << endl;
				os << "Make and Model: " << getMakeModel() << endl;
			}
		}
		return os;
	}
	/*-----------------------------------------------------------------------*/
}

