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
#include "Cargo.h"
using namespace std;

namespace sdds {

	void Cargo::setDesc(const char* description) {
		int len = 0;
		// If the string is longer than MAX_DESC, accept only MAX_DESC characters.
		if (strlen(description) > MAX_DESC) {
			len = MAX_DESC;
		}
		// a modifier that sets the description of the cargo within the MAX_DESC limit.
		else {
			len = strlen(description);
		}

		strncpy(cDesc, description, len);
		cDesc[len] = '\0';
	}

	void Cargo::setWeight(double weight) {
		// a modifier that sets the weight of the cargo.
		if (weight <= MAX_WEIGHT && weight >= MIN_WEIGHT) {
			cWeight = weight;
		}
		// If the parameter is invalid, set the attribute to MIN_WEIGHT.
		else {
			cWeight = MIN_WEIGHT;
		}


	}

	void Cargo::initialize(const char* desc, double weight) {
		// Check if the description is not a null pointer or the first character is not a whitespace
		if (desc != nullptr && desc[0] != '\0') {
			// Calls the functions to set the value for the attributes to the value received as parameters.
			setDesc(desc);
			setWeight(weight);
		}
		else {
			cDesc[0] = '\0';
			cWeight = 0;
		}
	}

	const char* Cargo::getDesc() const {
		// returns the description of the cargo
		return cDesc;
	}

	double Cargo::getWeight() const {
		// returns the weight of the cargo
		return cWeight;
	}
}