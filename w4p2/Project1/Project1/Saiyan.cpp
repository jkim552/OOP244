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
#include "Saiyan.h"
using namespace std;

namespace sdds {

	Saiyan::~Saiyan() {
		clearmemory();
	}


	Saiyan::Saiyan() {  // Initialization of Saiyan
		m_name = nullptr;
		m_dob = 3000;
		m_power = -1;
		m_super = false;
		m_level = -1;
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
			cout << right << setw(10) << "DOB: " << m_dob << endl;
			cout << right << setw(10) << "Power: " << m_power << endl;
			if (m_super == 1) {
				cout << right << setw(10) << "Super: " << "yes" << endl;
				cout << right << setw(10) << "Level: " << m_level << endl;
			}
			else {
				cout << right << setw(10) << "Super: " << "no" << endl;
			}

		}
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		clearmemory();

		if (name == nullptr || name[0] == '\0' || dob > 2020 || power < 0){
			name = NULL;
			setEmpty();
		}
		else {
			int size = strlen(name);
			m_name = nullptr;
			m_name = new char[size + 1];
			for (int i = 0; i < size; i++) {
				strcpy(&m_name[i], &name[i]);
			}
			m_name[size] = '\0';
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	}

	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = 3000;
		m_power = -1;
		m_super = false;
		m_level = -1;
	}

	bool Saiyan::isValid() const {

		return !(m_name == nullptr || m_name[0] == '\0' || m_dob > 2020 || m_power < 0);
	}

	void Saiyan::clearmemory() {
		delete[] m_name;
		m_name = nullptr;
	}

	bool Saiyan::fight(Saiyan& other) {
		if (m_level > 0) {
			m_power *= (1 + 0.1 * m_level);
		}
		if (other.m_level > 0) {
			other.m_power *= (1 + 0.1 * other.m_level);
		}
		return m_power > other.m_power;
	}
}





