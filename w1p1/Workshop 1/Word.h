/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
//I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#ifndef SDDS_WORD_H
#define SDDS_WORD_H
// compliation safeguards
// Your header file content goes here
namespace sdds{
	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;
	const int SORT_BY_OCCURANCE = 1;
	const int SORT_ALPHABETICALLY = 0;

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};
	void programTitle();
	void wordStats();
}
#endif