/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "Utils.h"
using namespace std;

void clearValue(void) {
	while (getchar() != '\n')
		;
}
int numMarks(int min, int max) {

	int nvalue;
	int keeptrying = 1;
	int rc;
	char after;

	do{
		rc = scanf("%d%c", &nvalue, &after);
		if (rc == 0) {
			cout << "Invalid Number, try again: ";
			clearValue();
		}
		else if (after != '\n') {
			cout << "Invalid trailing characters, try again: ";
			clearValue();
		}
		else if (nvalue < min || nvalue > max) {
			cout << "Invalid value (" << min <<"<=value<=" << max<< "), try again: ";
		}

		else {
			keeptrying = 0;
		}
	} while (keeptrying == 1);

	return nvalue;
}