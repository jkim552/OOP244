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
#include "Saiyan.h"
using namespace std;

namespace sdds {

	Saiyan::Saiyan() {  // Initialization of Saiyan
		m_name[0] = '\0';
		m_dob = 3000;
		m_power = -1;
		m_super = false;
		// setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		setEmpty();
		set(name, dob, power);
	}
	
	void Saiyan::display() const {
		if (!isValid()) {
			cout << "Invalid Saiyan!" << endl;
		}
		else {
			
			cout << m_name << endl;
			cout << "DOB: " << m_dob << endl;
			cout << "Power: " << m_power << endl;
			if (m_super == 1) {
				cout << "Super: yes" << endl;
			}
			else {
				cout << "Super: no" << endl;
			}
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {

		if (name == nullptr) {
			name = NULL;
			setEmpty();
		}
		else {
			int size = strlen(name);
			for (int i = 0; i < size; i++) {
				strcpy(&m_name[i], &name[i]);
			}
			m_name[size] = '\0';
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}

	void Saiyan::setEmpty() {
		m_name[0] = '\0';
		m_dob = 3000;
		m_power = -1;
		m_super = false;
	}

	bool Saiyan::isValid() const {

		return !(m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0);
	}

	bool Saiyan::fight(const Saiyan& other) const {
		return m_power > other.m_power;
	}
}





