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
		if (num == nullptr || model == nullptr || num[0] == '\0' || model[0] == '\0' ||
			strlen(num) > 8 || strlen(model) < 2){
			setEmpty();
		}
		else {
			strcpy(plateNum, num);
			toUppercase();
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
	void Vehicle::setEmpty() {
		plateNum[0] = '\0';
		makeModel = nullptr;
		spotNum = 0;
	}

	bool Vehicle::isEmpty() const {
		bool val = false;
		if (plateNum[0] == '\0' && makeModel == nullptr && spotNum == 0) {
			val = true;
		}
		return val;
	}

	const char* Vehicle::getLicensePlate() const{
		return plateNum;
	}

	void Vehicle::toUppercase() {
		for (int i = 0; i < strlen(plateNum); i++) {
			if (plateNum[i] >= 97 && plateNum[i] <= 122) {
				plateNum[i] = plateNum[i] - 32;
			}
		}
	}

	const char* Vehicle::getMakeModel() const{
		return makeModel;
	}

	void Vehicle::setMakeModel(const char* model) {
		if (model == nullptr || model[0] == '\0' || strlen(model) < 2) {
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
	int Vehicle::getParkingSpot() const {
		return spotNum;
	}
	
	void Vehicle::setParkingSpot(int num) {
		if (num < 0) {
			delete[] makeModel;
			makeModel = nullptr;
			setEmpty();
			
		}
		else {
			spotNum = num;
		}
	}

	bool operator==(const Vehicle& ve, const char* num) {
		char num2[9];
		bool val = false;
		for (int i = 0; i < strlen(num); i++) {
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

	bool operator==(const Vehicle& a, const Vehicle& b) {
		
		return (a == b.getLicensePlate());
	}
	/*
	istream& Vehicle::read(istream& is) {
		if (isCsv()) {



		}
		return is;
	}
	*/
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
	// Friend's code

	std::istream& Vehicle::read(std::istream& istr) {
		if (isCsv()) {	// Comma Separated mode //
			istr >> this->spotNum;
			if (istr.fail()) {	// check if the istream object failed while reading
				// If this was true it will set the Vehicle object to an invalid empty state.
				istr.clear();
				istr.ignore(2000, '\n');
				delete[] makeModel;
				makeModel = nullptr;
				this->setEmpty();
			}
			else {
				istr.ignore();
				string csvStr = "";
				std::getline(istr, csvStr, ',');
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					delete[] makeModel;
					makeModel = nullptr;
					this->setEmpty();
				}
				else {
					if (csvStr.length() <= 8) {
						strcpy(plateNum, csvStr.c_str());
						this->toUppercase();

						csvStr = "";
						std::getline(istr, csvStr, ',');
						if (istr.fail()) {	// check if the istream object failed while reading
							istr.clear();
							istr.ignore(2000, '\n');
							delete[] makeModel;
							makeModel = nullptr;
							this->setEmpty();
						}
						else {
							if (csvStr.length() >= 2 && csvStr.length() <= 60) {
								this->setMakeModel(csvStr.c_str());
							}
							else {
								std::cout << "Invalid input";
								this->setEmpty();
								istr.clear();
								istr.ignore(2000, '\n');
							}
						}
					}
					else {
						std::cout << "Invalid input";
						this->setEmpty();
						istr.clear();
						istr.ignore(2000, '\n');
					}
				}
			}
		}
		else {	// Vehicle is not set to Comma Separated mode //
			int keepreading = 1;
			std::cout << "Enter Licence Plate Number: ";
			keepreading = 1;
			string str = "";
			do {
				std::getline(istr, str);
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					delete[] makeModel;
					makeModel = nullptr;
					this->setEmpty();
				}
				else {
					if (str.length() <= 8) {
						strcpy(plateNum, str.c_str());
						this->toUppercase();
						keepreading = 0;
					}
					else {
						cerr << "Invalid Licence Plate, try again: ";
					}
				}
			} while (keepreading == 1);

			std::cout << "Enter Make and Model: ";
			str = "";
			keepreading = 1;
			do {
				std::getline(istr, str);
				if (istr.fail()) {	// check if the istream object failed while reading
					istr.clear();
					istr.ignore(2000, '\n');
					delete[] makeModel;
					makeModel = nullptr;
					this->setEmpty();
				}
				else {
					if (str.length() >= 2 && str.length() <= 60) {
						this->setMakeModel(str.c_str());
						this->spotNum = 0;
						keepreading = 0;
					}
					else {
						std::cout << "Invalid Make and model, try again: ";
					}
				}
			} while (keepreading == 1);
		}
		return istr;
	}
}

