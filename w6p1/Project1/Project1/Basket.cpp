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
#include "Basket.h"
using namespace std;

namespace sdds {

	//Default constructor
	Basket::Basket() {
		this->m_fruits = nullptr;
		this->m_cnt = 0;
		this->m_price = 0;
	}

	Basket::Basket(Fruit* fruits, int size, double price){
		this->m_fruits = new Fruit[size];

		if (size != 0 && price != 0 && fruits) {
			for (int i = 0; i < size; i++) {
				strcpy(this->m_fruits[i].m_name, fruits[i].m_name);
				this->m_fruits[i].m_qty = fruits[i].m_qty;
			}
			this->m_cnt = size;
			this->m_price = price;
		}
		else {
			delete[] this->m_fruits;
			*this = Basket();
		}
	}

	Basket::Basket(const Basket& obj) {
		if (obj.m_fruits != nullptr) {
			this->m_fruits = new Fruit[obj.m_cnt];
			for (int i = 0; i < obj.m_cnt; i++) {
				strcpy(this->m_fruits[i].m_name, obj.m_fruits[i].m_name);
				this->m_fruits[i].m_qty = obj.m_fruits[i].m_qty;
			}
			this->m_cnt = obj.m_cnt;
			this->m_price = obj.m_price;
		}
		else {
			this->m_fruits = nullptr;
		}
	}

	Basket::~Basket() {
		delete[] this->m_fruits;
		this->m_fruits = nullptr;
	}

	void Basket::setPrice(double price) {
		this->m_price = price;
	}

	Basket::operator bool() const {
		return(this->m_cnt > 0);
	}

	Basket& Basket::operator+=(Fruit fruits) {
		if (fruits.m_name[0] != '\0' && fruits.m_qty != 0) {
			Fruit* temp;
			int cnt = this->m_cnt;
			temp = new Fruit[cnt + 1];
			for (int i = 0; i < cnt; i++) {
				strcpy(temp[i].m_name, this->m_fruits[i].m_name);
				temp[i].m_qty =  this->m_fruits[i].m_qty;
			}
			strcpy(temp[cnt].m_name, fruits.m_name);
			temp[cnt].m_qty = fruits.m_qty;

			delete[] this->m_fruits;
			this->m_fruits = nullptr;

			cnt++;

			this->m_fruits = new Fruit[cnt];

			for (int i = 0; i < cnt; i++) {
				strcpy(this->m_fruits[i].m_name, temp[i].m_name);
				this->m_fruits[i].m_qty = temp[i].m_qty;
			}

			delete[] temp;
			temp = nullptr;
			
			this->m_cnt++;
		}
		return *this;
	}

	void Basket::display(std::ostream& os) const{
		if (this->m_fruits == nullptr || this->m_cnt == 0 || this->m_price == 0) {
			os << "The basket is empty!" << endl;
		}
		else {
			os << "Basket content:" << endl;
			os.setf(ios::fixed);
			os.precision(2);
			for (int i = 0; i < this->m_cnt; i++) {
				os.width(10);
				os << this->m_fruits[i].m_name << ": " << this->m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << this->m_price << endl;
		}

	}

	std::ostream& operator<<(std::ostream& os, const Basket& theBasket) {
		theBasket.display(os);
		return os;
	}
}
