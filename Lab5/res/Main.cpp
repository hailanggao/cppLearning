// MAIN.CPP - Case Study, Student Registration

// Count the number of courses taken by the student, calculate total credits
// author KRI
//

#include <fstream>
#include <iostream>

#include "regist.h"  // Registration class declaration
#include "unit.h"    // Unit class declaration

int main() {
    ifstream infile("rinput.txt");

    Registration R;
    infile >> R;

    ofstream ofile("routput.txt");
    ofile << R << "Number of units = " << R.GetCount() << '\n'
          << "Total credits = " << R.GetCredits() << '\n';
}
