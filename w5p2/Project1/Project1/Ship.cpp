/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"
using namespace std;

namespace sdds {
	// Delete the existing memory of dynamic memory
	void Ship::clearmemoryE() {
		delete[] this->m_engines;
		this->m_engines = nullptr;
	}
	void Ship::clearmemoryT() {
		delete[] this->m_type;
		this->m_type = nullptr;
	}
	void Ship::setEmpty() {
		this->m_engines = nullptr;
		this->m_type = nullptr;
		this->m_engCnt = 0;
	}

	// Default Constructor
	Ship::Ship() {
		setEmpty();
	}

	// Deconstructor
	Ship::~Ship() {
		clearmemoryE();
		clearmemoryT();
	}
	
	// Custom Constructor
	Ship::Ship(const char* shipType, Engine* engineAdd, int size){
		// create a new array of engines	
		this->m_engines = new Engine[size];
		// Valid ( Size under 10)
		if (size < 10) {
			// Copy the ship type
			int len = strlen(shipType);
			this->m_type = new char[len + 1];
			for (int i = 0; i < len; i++) {
				strcpy(&this->m_type[i], &shipType[i]);
			}
			this->m_type[len] = '\0';

			// Iterate over the array and copy each element
			for (int i = 0; i < size; i++) {
				this->m_engines[i].m_size = (engineAdd + i)->m_size;
				strcpy(this->m_engines[i].m_type, (engineAdd + i)->m_type);
			}

			// Copy the number of engines that are installed
			this->m_engCnt = size;
		}
		else {
			// Set to empty state if the size does not meet the requirement  
			clearmemoryE();
			this->setEmpty();
		}
	}

	Ship::operator bool() const {
		// Iterated each element of Engine, Type, Number of engines installed for validation
		bool result = true;
		int i = 0;
		// Stop the loop if at least one engine validation returns false
		// Loop until the number of engines installed
		do {
			if ((this->m_engines + i) == nullptr && this->m_type == nullptr && this->m_engCnt <= 0) {
				result = false;
			}
			i++;
		} while (result == true && i < this->m_engCnt);

		return result;
	}

	Ship& Ship::operator+=(Engine engine) {
		// Valid ship => Within the limit of engines installed.
		// Add the new engine to the end of the array
		if (engine.m_size == 0 || engine.m_type[0] == '\0' || this->m_engCnt >= 10){
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			// Crete a temporary engine to copy existing data
			Engine* temp;
			// End index
			int engCnt = this->m_engCnt;
			temp = new Engine[engCnt + 1];
			// Copy each all data inside the engine to temporary engine.
			for (int i = 0; i < engCnt; i++) {
				strcpy(temp[i].m_type, this->m_engines[i].m_type);
				temp[i].m_size = this->m_engines[i].m_size;
			}
			// Concatnate the new engine to the end index.
			strcpy(temp[engCnt].m_type, engine.m_type);
			temp[engCnt].m_size = engine.m_size;
			// The original engine is no longer use; clear that memory
			clearmemoryE();
			// Increase the engCnt since new engine is added
			engCnt++;
			// Since the original engine is set to null
			// Initialize new engine with increased number of engines
			this->m_engines = new Engine[engCnt];
			// Do the same, copy all the data.
			for (int i = 0; i < engCnt; i++) {
				strcpy(this->m_engines[i].m_type, temp[i].m_type);
				this->m_engines[i].m_size = temp[i].m_size;
			}
			// temp engine is no longer use; delete it
			delete[] temp;
			temp = nullptr;
			// increase the m_engCnt
			this->m_engCnt++;

		}
		return *this;
	}

	bool Ship::operator<(double power) const {
		return (cPower() < power);
	}

	double Ship::cPower() const{
		
		double power = 0;
		int i = 0;
		// Number of engines installed = Length of engines array
		int size = this->m_engCnt;
		do {
			power += (5 * (this->m_engines + i)->m_size);
			i++;
		} while (i < size);

		return power;
	}

	void Ship::display() const {
		if (!isValid()) {
			cout << "No available data" << endl;
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			
			// Print the ship power
			cout << this->m_type << " - " << setw(6) << setprecision(2) << fixed << cPower() << endl;
			int i = 0;
			// Number of engines installed = Length of engines array
			int size = this->m_engCnt;
			do {
				cout.precision(2);
				(this->m_engines + i)->display(); 
				cout << endl;
				i++;
			} while (i < size);

		}
		cout.precision(3);
	}

	bool Ship::isValid() const {
		return !(this->m_engCnt == 0 || this->m_type[0] == '\0');
	}

	bool operator<(double power, const Ship& theShip) {
		return (!(theShip < sdds::MAX_STD_POWER));
	}

}