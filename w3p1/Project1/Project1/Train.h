/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_TRAIN_H //header guard
#define SDDS_TRAIN_H
#include "Cargo.h"
namespace sdds {
	const int MAX_NAME = 30;

	class Train {
		char trainName[MAX_NAME];
		int trainID;
		Cargo* cargo;
	public:
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;

	};
}
#endif