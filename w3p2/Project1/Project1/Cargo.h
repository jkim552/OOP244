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
	const double MAX_WEIGHT = 777.555;
	const double MIN_WEIGHT = 44.2222;
	class Cargo {
		char cDesc[MAX_DESC+1];
		double cWeight;

	public: 
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);
	};
}
#endif
