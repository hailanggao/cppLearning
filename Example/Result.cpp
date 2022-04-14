
// RESULT.CPP - Result class implementation
// Doxygen comments are placed .h files

#include "result.h"

Result::Result() { 
    m_marks = 0; 
}

Result::Result(Unit& unit, float marks, Date& date) {
    m_marks = marks;
    m_unit = unit;
    m_date = date;
}

Result::Result(const Result& other) {
    m_marks = other.m_marks;
    m_unit = other.m_unit;
    m_date = other.m_date;
}

Unit Result::GetUnit() { 
    return m_unit; 
}

void Result::SetUnit(Unit& unit) { 
    m_unit = unit; 
}

float Result::GetMarks() const { 
    return m_marks; 
}

void Result::SetMarks(float marks) { 
    m_marks = marks; 
}

Date Result::GetDate() const { 
    return m_date; 
}

void Result::SetDate(Date& date) { 
    m_date = date; 
}

unsigned Result::GetCredits() const { 
    return m_unit.GetCredits(); 
}

string Result::RoundMarksToOneDecPl() {
    string marks = to_string(m_marks);
    marks = marks.substr(0, marks.find(".") + 2);
    return marks;
}

string Result::ToString() {
    string output;
    output = m_unit.ToString();
    output += "Mark: " + RoundMarksToOneDecPl() + '\n';
    output += "Date: " + m_date.ToString() + '\n';
    return output;
}
