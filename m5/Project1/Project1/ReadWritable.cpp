/* Citation and Sources...
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/17 Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ReadWritable.h"
using namespace std;
namespace sdds {
	// Constructor
	ReadWritable::ReadWritable() {
		flag = false;
	}

	// Destructor
	ReadWritable::~ReadWritable() {}
	
	// isCsv() const
	bool ReadWritable::isCsv() const {
		return flag;
	}

	// setCsv(bool value)
	void ReadWritable::setCsv(bool value) {
		flag = value;
	}

	istream& ReadWritable::read(istream& is) {
		return is;
	}

	ostream& ReadWritable::write(ostream& os) const{
		return os;
	}

	istream& operator>>(istream& is, ReadWritable& r) {
		r.read(is);
		return is;

	}

	ostream& operator<<(ostream& os, const ReadWritable& w) {
		w.write(os);
		return os;
	}
}
