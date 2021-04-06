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
#include "Gift.h"
using namespace std;

namespace sdds {
	void gifting(char* desc) {
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	void gifting(double& price) {
		bool done;
		int MIN_PRICE = 0;
		do {
			cout << "Enter gift price: ";
			cin >> price;
			if (price < MIN_PRICE || price > MAX_PRICE) {
				done = false;
				cout << "Gift price must be between " << MIN_PRICE << " and " << MAX_PRICE << endl;
			}
			else {
				done = true;
			}
		} while (!done);
	}

	void gifting(int& units) {
		bool done;
		do {
			cout << "Enter gift units: ";
			cin >> units;
			if (units < 1) {
				done = false;
				cout << "Gift units must be at least 1" << endl;
			}
			else {
				done = true;
			}
		} while (!done);
	}

	void display(const Gift& theGift) {
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;

		if (theGift.m_wrapLayers == 0) {
			cout << "Unwrapped!" << endl;
		}
		else {
			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++) {
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
			}
		}
	}

	bool wrap(Gift& theGift) {
		bool done;
		if (theGift.m_wrapLayers != 0) {
			cout << "Gift is already wrapped!" << endl; return false;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			do {
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> theGift.m_wrapLayers;
				if (MAX_WRAP < theGift.m_wrapLayers || theGift.m_wrapLayers <= 0) {
					done = false;
					cout << "Layers at minimum must be 1, try again." << endl;
				}
				else {
					done = true;
				}

			} while (!done);

			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];
			char temp[50];
			for (int i = 0; i < theGift.m_wrapLayers; i++) {
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> temp;
				theGift.m_wrap[i].m_pattern = nullptr;
				theGift.m_wrap[i].m_pattern = new char[strlen(temp) + 1];
				strcpy(theGift.m_wrap[i].m_pattern, temp);
			}
			return true;
		}
	}
	bool unwrap(Gift& theGift) {
		if (theGift.m_wrapLayers == 0) {
			cout << "Gift isn't wrapped! Cannot unwrap." << endl; return false;
		}
		else {
			int temp = theGift.m_wrapLayers;
			for (int i = 0; i < temp; i++) {
				delete[] theGift.m_wrap[i].m_pattern;
				theGift.m_wrap[i].m_pattern = nullptr;
				theGift.m_wrapLayers--;
			}
			cout << "Gift being unwrapped." << endl;
			delete[] theGift.m_wrap;
			theGift.m_wrap = nullptr; return true;
		}
	}
	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	}
}