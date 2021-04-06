/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_BASKET_H //header guard
#define SDDS_BASKET_H

namespace sdds {

	struct Fruit {
		char m_name[30 + 1]; // the name of the fruit
		double m_qty; // quantity in kg
	};

	class Basket {
		Fruit* m_fruits;
		int m_cnt;
		double m_price;

	public:
		Basket();
		Basket(Fruit* fruits, int size, double price);
		Basket(const Basket& obj);
		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(Fruit fruit);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Basket& theBasket);
}
#endif