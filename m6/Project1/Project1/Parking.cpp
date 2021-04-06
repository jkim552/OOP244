/* Citation and Sources...
Final Project Milestone 1
Module: Parking
Filename: Parking.cpp
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/13 Preliminary release
2020/08/03 Added more member functions and others for Milestone 6
2020/08/04 Complied through matrix to fix minor output mistakes
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Car.h"
#include "Motorcycle.h"
#include "Menu.h"
#include "Utils.h"
#include "Parking.h"
using namespace std;

namespace sdds {

	/*--------------------------Parking Constructor*--------------------------*/  // Double check
	Parking::Parking(const char* nam, int num) : parkingSpots{nullptr}
	{
		if (nam == nullptr || strlen(nam) == 0 || num < 10 || num > MAXNUMSPOT) {
			filename = nullptr;
			parking = nullptr;
			vehicle = nullptr;
			numOfSpots = 0;
		}
		else {
			int len = strlen(nam);
			filename = new char[len + 1];
			strcpy(filename, nam);
			numOfSpots = num;
			numOfParkedV = 0;
		}
		if (loadFile()) {
			parking = new Menu("Parking Menu, select an action:", 0);
			*parking << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			vehicle = new Menu("Select type of the vehicle:", 1);
			*vehicle << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
		}

	}
	/*------------------------------------------------------------------------*/

	/*--------------------------Parking Destructor----------------------------*/   // Double check
	Parking::~Parking() {
		if (parking != nullptr) { delete parking; }
		if (vehicle != nullptr ){ delete vehicle; }
		saveFile();
		if (filename != nullptr) {	
			delete[] filename;
		}
		for (int i = 0; i < numOfSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
			}
		}
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------isEmpty()---------------------------------*/
	bool Parking::isEmpty() const {
		bool status = true;
		if (filename != nullptr) {
			status = false;
		}
		return status;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------displayStatus()---------------------------*/
	void Parking::displayStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout << left << setw(4) << numOfSpots - numOfParkedV;
		cout << " *****" << endl;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------parkVehicle()--------------------------*/
	void Parking::parkVehicle() {
		if ((numOfSpots - numOfParkedV) == 0) {
			cout << "Parking is full" << endl;
		}
		else {
			int selection = 0;
			selection = vehicle->run();
			if (selection == 1 || selection == 2) {
				// Create a vehicle instance and depending on the selection, create a new instance of Car or Motorcycle
				Vehicle* vh;
				if (selection == 1) {
					vh = new Car();
				}
				else {
					vh = new Motorcycle();
				}
				vh->read(cin);
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] == nullptr) {
						vh->setParkingSpot(i + 1);
						parkingSpots[i] = vh;
						numOfParkedV += 1; 
						cout << endl << "Parking Ticket" << endl;
						parkingSpots[i]->write(cout);
						cout << endl;
						break;
					}
				}
			}
			else if (selection == 3) {
				cout << "Parking cancelled" << endl;
			}
		}
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------returnVehicle()---------------------------*/
	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		int isContinue = 1;
		char tempPlate[9];
		cout << "Enter Licence Plate Number: ";
		do {
			cin.getline(tempPlate, 9);
			if (strlen(tempPlate) > 8) {
				cout << "Invalid Licence Plate, try again: ";
			}
			else {
				// Search for matching license plate
				// If found, delete it and set it to nullptr
				// else, print not found
				Utils::toUpperCase(tempPlate);
				int found = 0;
				for (int i = 0; i < numOfSpots; i++) {    // i < 3 
					// friend bool operator==(const Vehicle & ve, const char* num);
					if (*parkingSpots[i] == tempPlate) {
						parkingSpots[i]->setCsv(false);
						cout << endl << "Returning: " << endl;
						parkingSpots[i]->write(cout);
						cout << endl;
						numOfParkedV -= 1;
						delete parkingSpots[i];      
						parkingSpots[i] = nullptr;
						found = 1;
						break;
					}
				}
				if (found == 0){
					cout << "License plate " << tempPlate << " Not found" << endl;
				}
				isContinue = 0;
			}
		} while (isContinue);
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------listParked()------------------------------*/
	void Parking::listParked() const {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numOfSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				parkingSpots[i]->setCsv(false);
				parkingSpots[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------closeParking()------------------------------*/
	bool Parking::closeParking() {
		bool returning = true;
		if (isEmpty()) {
			cout << "Closing Parking" << endl;
		}
		else {
			bool ok = true;
			bool val = true;
			char yn;
			char newline;
			const char invalid[] = "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
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

			if (!val) {
				returning = false;
			}
			else {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] != nullptr) {
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						parkingSpots[i]->write(cout);
						numOfParkedV -= 1;
						delete parkingSpots[i];
						parkingSpots[i] = nullptr;
					}
				}
				returning = true;
			}
		}
		return returning;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------exitParking()------------------------------*/
	bool Parking::exitParking() const {
		bool ok = true;
		bool val = true;
		char yn;
		char newline;
		const char invalid[] = "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
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
	/*------------------------------------------------------------------------*/

	/*------------------------------loadFile()--------------------------------*/
	bool Parking::loadFile() {
		bool val = true;
		ifstream ifs;
		if (!isEmpty()) {
			//cout << "loading data from " << filename << endl;
			ifs.open(filename); // default in(read)
			if (!(ifs.good()) || isEmpty()) {
				;
			}
			else{
				for (int i = 0; ifs.good() && i < numOfSpots; i++) {
					
					if (numOfParkedV < numOfSpots) {
						// e,g C,1,ASD123, Honda Civic, 0
						char MorC = ifs.get(); // eat M or C
						if (ifs.good()) {
							Vehicle* vh;
							if (MorC == 'M') {
								vh = new Motorcycle();
							}
							else {
								vh = new Car();
							}
							vh->setCsv(true);
							// char dummy = ifs.get(); // eat , Complie error when used in matrix so switched out with ignore().
							ifs.ignore(5000, ','); // eat ,
							vh->read(ifs); // read 1,ASD123,Honda Civic,0
							vh->setParkingSpot(i + 1);
							parkingSpots[i] = vh;
							numOfParkedV += 1;
						}
					}
				}
			}
		}
		else {
			val = false;
		}
		ifs.close();
		return val;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------saveFile()--------------------------------*/
	void Parking::saveFile() const {
		ofstream ofs;
		ofs.open(filename);
		if (ofs.good()) {
			for (int i = 0; i < numOfSpots; i++) {
				if (parkingSpots[i] != nullptr) {
					parkingSpots[i]->setCsv(true);
					parkingSpots[i]->write(ofs);
				}
			}
		}
		ofs.close();
	}
	/*------------------------------------------------------------------------*/

	int Parking::run() {
		int selection = 0;
		if (!this->isEmpty()) {
			// Calls the parking status function
			// Display parking menu and waits for the response
			int keepgoing = 1;
			do {
				displayStatus();
				selection = parking->run();
				if (selection == 1) {
					parkVehicle();
				}
				else if (selection == 2) {
					returnVehicle();
				}
				else if (selection == 3) {
					listParked();
				}
				else if (selection == 4) {
					bool val = closeParking();
					if (val) {
						keepgoing = 0;
					}
					else {
						cout << "Aborted!" << endl;
					}
				}
				else if (selection == 5) {
					bool val = exitParking();
					if (val) {
						cout << "Exiting program!" << endl;
						keepgoing = 0;
					}
				}
			} while (keepgoing == 1);
		}
		return selection;
	}
}