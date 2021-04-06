/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
 //I have done all the coding by myself and only copied the code that my profes-sor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "Marks.h"
#include "Utils.h"

using namespace std;

void sorting(int* list, int nofmarks) {
	int i, j, m;
	int temp;
	
	for (i = 0; i < nofmarks; i++) {
		m = i;
		for ( j = i + 1; j < nofmarks; j++)
			if (list[j] > list[m]) {
				m = j;
			}
		if (m != i) {
			temp = list[i];
			list[i] = list[m];
			list[m] = temp;
		}
	}
}

void passing(int* nofmarks, int* marks) {
	double av = 0;
	int passed = 0, i;

	for (i = 0; i < *nofmarks; i++) {
		if (i == 0) {
			cout << marks[i];
		}
		else {
			cout << ", " << marks[i];
		}
		if (marks[i] >= 50) {
			passed += 1;
		}
		av += marks[i];
	}
	av /= *nofmarks;

	cout.setf(ios::fixed);

	cout << endl << setprecision(1) << "Average: " << av << endl;
	cout << "Number of Passing Marks: " << passed << endl;
}

void markstat() {
	struct evaluation eval;
	int i;

	cout << "Mark Stats Program." << endl << endl;

	cout << "Please enter the assessment name: ";
	cin.getline(eval.title, 100);

	cout << "Please enter the number of marks: ";
	eval.nmarks = numMarks(MIN_NMARKS, MAX_NMARKS);

	cout << "Please enter " << eval.nmarks << " marks (0<=Mark<=100):" << endl;

	for (i = 0; i < eval.nmarks; i++) {
		cout << i + 1 << "> ";
		eval.mark[i] = numMarks(MIN_MARK, MAX_MARK);
	}
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << eval.title << endl;
	cout << "----------------" << endl;

	sorting(eval.mark, eval.nmarks);
	passing(&eval.nmarks, eval.mark);

}

