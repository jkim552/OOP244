/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_Engine_H //header guard
#define SDDS_Engine_H

namespace sdds {
	const int TYPE_MAX_SIZE = 30;
	class Engine{
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];
	
	public:
		Engine();
		Engine(const char*, double);
		double get() const;
		void display() const;
		friend class Ship;
	};
}
#endif