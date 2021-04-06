	/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/06 Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
	void Utils::read(int& val, int min, int max, const char* ErrorMess) {
		bool ok;
		char newline;
		const char* orgMes = ErrorMess;
		const char invalidInt[] = "Invalid Integer, try again: ";
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
				ErrorMess = invalidInt;
			}
			else {
				ok = val <= max && val >= min;
				ErrorMess = orgMes;
			}
		} while (!ok && cout << ErrorMess);
	}
	
	void Utils::toUpperCase(char* a) {
		for (unsigned int i = 0; i < strlen(a); i++) {
			if (a[i] >= 'a' && a[i] <= 'z') {
				a[i] = a[i] - 32;
			}
		}
	}
}