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
		car.getDesc();
		cargo->setDesc(car.getDesc());
		cargo->setWeight(car.getWeight());
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
			cout << "    Name: " << trainName << endl;
			cout << "      ID: " << trainID << endl;
			if (cargo == NULL) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "   Cargo: " << cargo->getDesc() << endl;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "  Weight: " << cargo->getWeight() << endl;
			}
		}
		cout.precision(3);
	}

	bool Train::swapCargo(Train& other) {
		// check if two trains are valid
		bool z;
		if (cargo != NULL && other.cargo != NULL) {
			// returns true if both are not null
			z = true;
			Cargo temp;
			// store description and weight of cargo to temporary cargo
			temp.setDesc(cargo->getDesc());
			temp.setWeight(cargo->getWeight());

			// store other cargo description and weight to cargo
			cargo->setDesc(other.cargo->getDesc());
			cargo->setWeight(other.cargo->getWeight());

			// store temp cargo description and weight ( oringially from cargo) to other cargo
			other.cargo->setDesc(temp.getDesc());
			other.cargo->setWeight(temp.getWeight());
		}
		else {
			z = false;
		}
		return z;
	}


	bool Train::increaseCargo(double weight) {
		bool z = true;
		// check if the current train is valid, 
		// carries valid cargo and the new weight doesn't exceed MAX_WEIGHT.

		if (cargo != NULL && cargo->getWeight() != MAX_WEIGHT) {
			double newWeight = cargo->getWeight() + weight;
			// check the capacity of new weight and compare with max weight
			if (newWeight < MAX_WEIGHT) {
				cargo->setWeight(newWeight);
			}
			else {
				cargo->setWeight(MAX_WEIGHT);
			}
		}
		else { 
			z = false;
		}
		return z;
	}

	bool Train::decreaseCargo(double weight) {
		bool z = true;
		// check if the current train is valid, 
		// carries valid cargo and the new weight doesn't go below MIN_WEIGHT.

		if (cargo != NULL && cargo->getWeight() != MIN_WEIGHT) {
			double newWeight = cargo->getWeight() - weight;
			// check the capacity of new weight and compare with min weight
			if (newWeight > MIN_WEIGHT) {
				cargo->setWeight(newWeight);
			}
			else {
				cargo->setWeight(MIN_WEIGHT);
			}
		}
		else {
			z = false;
		}
		cout.precision(4);
		return z;
	}









}