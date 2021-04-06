#include "Parking.h"
#include "vld.h"
#include <iostream>
using namespace sdds;

int main() {
	Parking P("ParkingData.cvs"), bad1(nullptr), bad2("");
	
	bad1.run();
	bad2.run();
	P.run();
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	P.run();
	
	return 0;

}