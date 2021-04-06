/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Engine.h"
#include <cstring>
using namespace std;

namespace sdds {
	// Default constructor
	Engine::Engine() {
		this->m_size = 0;
		this->m_type[0] = '\0';
	}
	// Custom Constructor
	Engine::Engine(const char* type, double size) {
		strcpy(m_type, type);
		this->m_size = size;
	}
	// Return size of engine
	double Engine::get () const{
		return this->m_size;
	}
	// Print the content of an object in the format [SIZE] liters - [TYPE]
	void Engine::display() const {
		cout << this->m_size << " liters - " << this->m_type;
	}
}