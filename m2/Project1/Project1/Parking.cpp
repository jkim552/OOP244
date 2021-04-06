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
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include "Parking.h"
using namespace std;

namespace sdds {

	/*--------------------------Parking Constructor*--------------------------*/  // Double check
	Parking::Parking(const char* nam) {
		if (nam == nullptr || strlen(nam) == 0) {
			filename = nullptr;
			parking = nullptr;
			vehicle = nullptr;
		}
		else {
			int len = strlen(nam);
			filename = new char[len + 1];
			strcpy(filename, nam);
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
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------parkVehicle()--------------------------*/     // Needs to Do
	void Parking::parkVehicle() const {
		int selection = 0;
		selection = vehicle->run();
		if (selection == 1) {
			cout << "Parking Car" << endl;
		}
		else if (selection == 2) {
			cout << "Parking Motorcycle" << endl;
		}
		else if (selection == 3) {
			cout << "Cancelled parking" << endl;
		}
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------returnVehicle()---------------------------*/
	void Parking::returnVehicle() const {
		cout << "Returning Vehicle" << endl;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------listParked()------------------------------*/
	void Parking::listParked() const {
		cout << "Listing Parked Vehicles" << endl;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------closeParking()------------------------------*/
	bool Parking::closeParking() const {
		cout << "Closing Parking" << endl;
		return true;
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
	bool Parking::loadFile() const{
		bool val = true;
		if (!isEmpty()) {
			cout << "loading data from " << filename << endl;
		}
		else {
			val = false;
		}
		return val;
	}
	/*------------------------------------------------------------------------*/

	/*------------------------------loadFile()--------------------------------*/
	void Parking::saveFile() const {
		if (!isEmpty()) {
			cout << "Saving data into " << filename << endl;
		}
	}
	/*------------------------------------------------------------------------*/

	int Parking::run() const {
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