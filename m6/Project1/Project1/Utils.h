/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
Version 1.0
Author John Kim
Revision History
-----------------------------------------------------------
Date Reason
2020/07/06 Preliminary release
2020/07/20 Reused from MS4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	const unsigned int ReadBufferSize = 10;
	struct Utils {
		static void read(int& val, int min, int max, const char* errorMessage = "");
		static void toUpperCase(char* val);
	};
}
#endif