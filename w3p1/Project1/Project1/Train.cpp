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
#include "Train.h"
using namespace std;

namespace sdds {
	void Train::initialize(const char* name, int id) {
		if (name == nullptr || id < 1 || name[0] == '\0') {
			name = NULL;
			trainName[0] = '\0';
			trainID = 0;
			cargo = nullptr;
		}
		else {
			if (strlen(name) > MAX_DESC) {
				for (int i = 0; i < MAX_DESC; i++) {
					strcpy(&trainName[i], &name[i]);
				}
				trainID = id;
				cargo = nullptr;
			}
			else {
				int len = strlen(name);
				for (int i = 0; i < len; i++) {
					strcpy(&trainName[i], &name[i]);
				}
				trainName[len] = '\0';
				trainID = id;
				cargo = nullptr;
			}
		}
	}
	bool Train::isValid() const {
		bool isvalid = true;
		if ((trainName[0] == '\0') && (trainID < 1)) {
			isvalid = false;
		}
		return isvalid;
	}
	void Train::loadCargo(Cargo car) {
		if (cargo != nullptr) {
			delete cargo;
		}
		cargo = nullptr;
		cargo = new Cargo;
		strncpy(cargo->desc, car.desc, strlen(car.desc));
		cargo->desc[strlen(car.desc)] = '\0';
		cargo->weight = car.weight;
	}
	void Train::unloadCargo() {
		delete cargo;
		cargo = nullptr;
	}
	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (trainName == nullptr || trainID < 1 || trainName[0] == '\0') {
			cout << "This is an invalid train." << endl;
		}
		else {
			cout << "Name: " << trainName << endl;
			cout << "ID: " << trainID << endl;
			if (cargo == NULL) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "Cargo: " << cargo->desc << endl;
				cout << "Weight: " << cargo->weight << endl;
			}
		}
	}
}