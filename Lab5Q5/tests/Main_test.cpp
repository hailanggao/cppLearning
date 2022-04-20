//#include the various .h file needed - Vector, Unit, Date
#include "../lib/Date.h"
#include "../lib/Time.h"
#include "../lib/Vector.h"
#include "../lib/ConvertData.h"
#include "../lib/Math.h"
//#include anything else you need – typically things in < >, like <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>

//forward declarations – the actual body of the routines are after main()

// each of these tests is self-sufficient – will open an appropriate data file and // load the Vector with the correct data.
// each method of Vector is tested in each routine and must make sense
// make sure you load the Vector with multiple data – Vector must contain many items

Bool testIntVec(Vector<int>& vec); // open int data file, and load Vector, write out  
								   // and compare

Bool testUnitVec(Vector<Unit>& vec); // open unit data file, and load Vector, write out  
									 // and compare. This unit data file contains only
									 // unit details for the registration exercise in 
									 // earlier labs.

Bool testDateVec(Vector<Date>& vec); // open Date data file, and load Vector, write out  
									 // and compare. This date data file contains just 
									 // dates in formatted as dd/mm/yyyy where d, m
									 // and y are digits representing day, month and year.
Template <class T>
void printVec(const Vector<T>& vec); 	// Prints the Vector to the screen
										// how would you make it flexible so that 
										// it can print to any stream
										// If you have a method of Vector that prints out the data, 
										//then you have made a design mistake unless it just temporary for debugging. 
										//Why would it be a design mistake?

Template <class T>
void printVec(Vector<T> vec);			// As above, but pass by value


int main() {

	Vector<int> intVec;
	Vector<Unit> unitVec; // Unit is from the Unit class from the earlier labs
	Vector<Date> dateVec; //Date is the Date class from earlier labs

	 // Call each of the test routines followed by printVec. Each test routine tests      // every public method of the Vector.  Use the testing approach shown in earlier
	// Topic PowerPoint notes.

	return 0;
}
