/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/06 Preliminary release
2020/?/? Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {

	//**********************
	// MenuItem class

	MenuItem::MenuItem(const char* value) : m_value(nullptr) {
		if (value != nullptr) {
			int len = strlen(value);
			this->m_value = new char[len + 1];
			strncpy(this->m_value, value, len);
			this->m_value[len] = '\0';
		}

	}

	MenuItem::~MenuItem() {
		delete[] this->m_value;
		this->m_value = nullptr;
	}

	void MenuItem::display() const {
		if (this->m_value != nullptr) {
			cout << this->m_value << endl;
		}
	}

	//**********************

	//**********************
	// Private Methods
	void Menu::indent() const {
		if (this->m_indentation == 1) {
			cout << "    ";
		}
		else if (this->m_indentation == 2) {
			cout << "        ";
		}
	}

	void Menu::clear() {
		delete[] this->m_title;
		this->m_title = nullptr;
		this->m_noOfItems = 0;
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			delete[] this->m_items[i]->m_value;
			this->m_items[i]->m_value = nullptr;
		}
	}

	//**********************

	//**********************
	// Constructors, Copy Constructor, Assignment(2), Destructor

	Menu::Menu(const char* title, int indentation) :
		m_title(nullptr),
		m_items{nullptr},
		m_noOfItems(0),
		m_indentation(indentation) {
		*this = title;
	}

	Menu::Menu(const Menu& M) :
		m_title(nullptr),
		m_items{nullptr},
		m_noOfItems(0),
		m_indentation(M.m_indentation) {
		*this = M;
	}

	Menu& Menu::operator=(const char* title) {
		if (title != nullptr) {
			delete[] this->m_title;
			int len = strlen(title);
			this->m_title = new char[len + 1];
			strncpy(this->m_title, title, len);
			this->m_title[len] = '\0';
		}
		else {
			clear();
		}
		return *this;
	}

	Menu& Menu::operator=(const Menu& M) {
		if (this != &M) {
			clear();
			if (M.isEmpty() == false) {
				*this = M.m_title;
				for (int i = 0; i < M.m_noOfItems; i++) {
					add(M.m_items[i]->m_value);
				}
				this->m_indentation = M.m_indentation;
			}
		}
		return *this;
	}

	Menu::~Menu() {
		clear();
	}

	//**********************
	// Add function and insertion function

	void Menu::add(const char* item) {
		if (this->isEmpty() != true && this->m_noOfItems < MAX_NO_OF_ITEMS) {
			if (item != nullptr) {
				this->m_items[this->m_noOfItems] = new MenuItem(item);
				this->m_noOfItems++;
			}
			else {
				clear();
			}
		}
	}

	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}
	//**********************

	//**********************
	// Display menu function

	void Menu::display() const {
		if (this->isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else if (this->m_indentation != 0){
			if (this->m_noOfItems == 0) {
				indent();
				cout << this->m_title << endl;
				cout << "No Items to display!" << endl;
			}
			else if (this->m_noOfItems != 0) {
				indent();
				cout << this->m_title << endl;
				for (int i = 0; i < this->m_noOfItems; i++) {
					indent();
					cout << i + 1 << "- ";
					this->m_items[i]->display();
				}
				indent();
				cout << "> ";
			}
		}
		else {
			if (!(this->isEmpty())) {
				cout << this->m_title << endl;
				if (this->m_noOfItems == 0) {
					cout << "No Items to display!" << endl;
				}
				else if (this->m_noOfItems != 0) {
					for (int i = 0; i < this->m_noOfItems; i++) {
						
						cout << i + 1 << "- ";
						this->m_items[i]->display();
					}
					
					cout << "> ";
				}
			}
		}
	}
	//**********************

	//**********************
	// Casting

	Menu::operator int() const {
		return run();
	}

	Menu::operator bool() const {
		return !isEmpty();
	}

	bool Menu::isEmpty() const {
		return (m_title == nullptr);
	}
	//**********************

	//**********************
	// Run

	int Menu::run() const {
		int selection = 0;
		display();
		if (!isEmpty() && m_noOfItems > 0) {
			Utils::read(selection, 1, m_noOfItems, "Invalid selection, try again: ");
		}
		return selection;
	}
}