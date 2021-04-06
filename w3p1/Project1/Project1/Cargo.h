/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_CARGO_H //header guard
#define SDDS_CARGO_H

namespace sdds {
	const int MAX_DESC = 20;
	struct Cargo {
		char desc[MAX_DESC];
		double weight;
	};
}
#endif
