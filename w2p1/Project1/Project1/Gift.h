/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_GIFT_H //header guard
#define SDDS_GIFT_H
namespace sdds {

	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
	
	struct Wrapping {
		char* m_pattern;
	};
	struct Gift {
		// Allowcated array of characters that will store the description of the gift
		char m_description[MAX_DESC+1];
		// Price of gift. Min = 0 Max = MAX_PRICE
		double m_price;
		// Units/copies of the gift
		int m_units;
		Wrapping* m_wrap;
		int m_wrapLayers;
	};

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
}
#endif