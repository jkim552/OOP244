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
#include "Ship.h"
using namespace std;

namespace sdds {

	void Ship::setEmpty() {
		m_engines->m_size = 0;
		m_engines->m_type[0] = '\0';
		m_type[0] = '\0';
		m_engCnt = 0;
	}

	// Default Constructor
	Ship::Ship() {
		setEmpty();
	}
	
	// Custom Constructor
	Ship::Ship(const char* shipType, Engine* engineAdd, int size){
		// Valid ( Size under 10)
		if (size < 10) {
			// Copy the ship type
			strcpy(this->m_type, shipType);

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
			if ((this->m_engines + i)->m_size <= 0 && (this->m_engines + i)->m_type[0] == '\0' &&
				this->m_type[0] == '\0' && this->m_engCnt <= 0) {
				result = false;
			}
			i++;
		} while (result == true && i < this->m_engCnt);

		return result;
	}

	Ship& Ship::operator+=(Engine engine) {
		// Length is given in the class  =>m_engCnt
		// Created for better understanding
		int endIndex = m_engCnt;
		// Valid ship => Within the limit of engines installed.
		// Add the new engine to the end of the array
		if (this->m_engCnt < 10) {
			this->m_engines[endIndex].m_size = engine.m_size;
			strcpy(this->m_engines[endIndex].m_type, engine.m_type);
			m_engCnt++;
		}
		else {
			cout << "The object is not valid! Engine cannot be added!" << endl;
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
			cout << this->m_type << " - " << cPower() << endl;
			int i = 0;
			// Number of engines installed = Length of engines array
			int size = this->m_engCnt;
			do {
				(this->m_engines + i)->display(); 
				cout << endl;
				i++;
			} while (i < size);

		}
	}

	bool Ship::isValid() const {
		return !(this->m_engCnt == 0 || this->m_type[0] == '\0');
	}

	bool operator<(double power, const Ship& theShip) {
		return (!(theShip < sdds::MAX_STD_POWER));
	}

}