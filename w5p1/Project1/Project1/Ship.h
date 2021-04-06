/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_SHIP_H //header guard
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds {
	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
	class Ship {
		Engine m_engines[10];
		char m_type[TYPE_MAX_SIZE + 1];
		int m_engCnt;
	public:
		void setEmpty();
		Ship();
		Ship(const char*, Engine* engineAdd, int size);
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		double cPower() const;
		bool isValid() const;

	};
	bool operator<(double power, const Ship& theShip);
}
#endif