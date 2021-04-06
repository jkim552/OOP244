/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_SAIYAN_H //header guard
#define SDDS_SAIYAN_H

namespace sdds {
	class Saiyan {
		char m_name[32];
		int m_dob; // <= 2020
		int m_power; // >= 0
		bool m_super;
	
	public: 
		Saiyan();
		Saiyan(const char*, int, int); //name, date of birth, power as parameters
		void set(const char* name, int dob, int power, bool super = false);
		void setEmpty();
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other) const;
	};
}



#endif