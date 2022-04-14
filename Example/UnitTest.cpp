#include "Unit.h"
#include <iostream>

int main() {

	Unit U1;
	Unit U2;

	std::string emptyName = "No Unit Name yet";
	std::string emptyId = "No Unit Id yet";
	int ZeroCredit = 0;


	std::string name1 = U1.GetUnitName();
	std::string id1 = U1.GetUnitId();
	int credit = U1.GetCredits();

	std::string unit2Id = "Unit2Id";
	std::string unit2Name = "Unit2Name";
	U2.SetCredits(6);
	U2.SetUnitId(unit2Id);
	U2.SetUnitName(unit2Name);

	std::string name2 = U2.GetUnitName();
	std::string id2 = U2.GetUnitId();
	int credit2 = U2.GetCredits();

	Unit U3(U2);

	if (emptyName.compare(name1) == 0 &&
		emptyId.compare(U1.GetUnitId()) == 0 &&
		credit == ZeroCredit) {
		std::cout << "Init Name passed!" << std::endl;
		std::cout << "Init Id passed!" << std::endl;
		std::cout << "Init Credit passed!" << std::endl;
		std::cout << "----------------------------" << std::endl;
	}

	if (unit2Id.compare(id2) == 0 &&
		unit2Name.compare(name2) == 0 &&
		credit2 == 6) {
		std::cout << "Unit Name passed!" << std::endl;
		std::cout << "Unit Id passed!" << std::endl;
		std::cout << "Unit Credit passed!" << std::endl;
		std::cout << "----------------------------" << std::endl;
	}

	if (U3.GetCredits() == credit2 && U3.GetUnitId().compare(id2) == 0 && U3.GetUnitName().compare(name2) == 0) {
		std::cout << "Unit3 Name passed!" << std::endl;
		std::cout << "Unit3 Id passed!" << std::endl;
		std::cout << "Unit3 Credit passed!" << std::endl;
		std::cout << "----------------------------" << std::endl;
	
	}
	std::cin.get();
	return 0;
}
