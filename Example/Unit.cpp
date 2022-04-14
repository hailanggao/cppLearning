// UNIT.CPP - Unit class implementation
// Doxygen comments are placed .h files

#include "unit.h"
#include <string>

Unit::Unit() {
    unitId = "No Unit Id yet";
    unitName = "No Unit Name yet";
    credits = 0;
}
Unit::Unit(std::string& id, std::string& nam, unsigned cred) {
    unitId = id;
    unitName = nam;
    credits = cred;
}
Unit::Unit(const Unit& other) {
    unitId = other.unitId;
    unitName = other.unitName;
    credits = other.credits;
}
std::string Unit::GetUnitId() const {
    return unitId; 
}
void Unit::SetUnitId(std::string& id) {
    unitId = id; 
}

std::string Unit::GetUnitName() const {
    return unitName; 
}
void Unit::SetUnitName(std::string& name) {
    unitName = name; 
}

unsigned Unit::GetCredits() const { 
    return credits; 
}
void Unit::SetCredits(unsigned cred) {
    credits = cred; 
}

std::string Unit::ToString() {
    std::string output;
    output = "Unit ID: " + unitId + '\n';
    output += "Unit Name: " + unitName + '\n';
    output += "Credits: " + std::to_string(credits) + '\n';
    return output;
}

std::ostream& operator << (std::ostream& os, Unit& U) {
    os << U.ToString();
    return os;
}
