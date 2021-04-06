/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef JUN_MARKS_H // header guard
#define JUN_MARKS_H

#define MIN_NMARKS 5
#define MAX_NMARKS 50

#define MIN_MARK 0
#define MAX_MARK 100



void sorting(int*, int);
void passing(int*, int*);
void markstat();

struct evaluation {
	char title[50];
	int mark[50];
	int nmarks;
};

#endif