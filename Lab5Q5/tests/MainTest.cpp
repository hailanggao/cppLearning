//#include anything else you need – typically things in < >, like <iostream>
#include <iostream>
#include <fstream>
#include <string>
//#include the various .h file needed - Vector, Unit, Date
#include "../lib/Vector.h"



//forward declarations – the actual body of the routines are after main()

// each of these tests is self-sufficient – will open an appropriate data file and // load the Vector with the correct data.
// each method of Vector is tested in each routine and must make sense
// make sure you load the Vector with multiple data – Vector must contain many items

// open int data file, and load Vector, write out  and compare
bool testIntVec(Vector<int>& vec) {

	std::ifstream myFile("tests/int.txt");
	if (!myFile) {
		std::cout << "No data file found" << std::endl;
		return false;
	}
	Vector<int> data;
	std::string line;
	while (std::getline(myFile, line)) {
		data.push(std::stoi(line));
	}
	return std::equal(data.begin(), data.end(), vec.begin());
	
}

int main() {

	Vector<int> intVec;
	intVec.push(1);
	intVec.push(3);
	intVec.push(2);
	bool testInt = testIntVec(intVec);
	if (testInt) {
		std::cout << "test int passed" << std::endl;
	}
	
	//Vector<Unit> unitVec; // Unit is from the Unit class from the earlier labs
	//Vector<Date> dateVec; //Date is the Date class from earlier labs

	 // Call each of the test routines followed by printVec. Each test routine tests      // every public method of the Vector.  Use the testing approach shown in earlier
	// Topic PowerPoint notes.

	std::cin.get();
}