/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H //header guard
#define SDDS_MENU_H

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;

	class MenuItem {
	private:
		char* m_value;
	public:
		MenuItem(const char* item);
		MenuItem(const MenuItem& mi) = delete;
		MenuItem& operator=(const MenuItem& mi) = delete;
		~MenuItem();
		void display() const;
		friend class Menu;
	};

	class Menu {
	private:
		char* m_title;
		MenuItem* m_items[MAX_NO_OF_ITEMS];
		int m_noOfItems;
		int m_indentation;
		void indent() const;
		void clear();
	public:
		Menu(const char* title, int indentation = 0);
		Menu(const Menu&);
		Menu& operator=(const Menu&);
		Menu& operator=(const char* title);
		~Menu();
		void add(const char* item);
		Menu& operator<<(const char* item);
		void display() const;
		operator int() const;
		operator bool() const;
		bool isEmpty() const;
		int run() const;
	};

}


#endif
