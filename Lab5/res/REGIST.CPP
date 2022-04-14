
// REGIST.CPP - Registration class implementation.
// Doxygen comments are placed .h files

#include "regist.h"
Registration::Registration() { 
    count = 0; 
}

Registration::Registration(long id, unsigned sem, unsigned co) {
    studentId = id;
    semester = sem;
    count = co;
}

Registration::Registration(const Registration& other) {
    studentId = other.studentId;
    semester = other.semester;
    count = other.count;
}

long Registration::GetStudentId() const { 
    return studentId; 
}
void Registration::SetStudentId(long id) { 
    studentId = id; 
}

unsigned Registration::GetSemester() const { 
    return semester; 
}
void Registration::SetSemester(unsigned sem) { 
    semester = sem; 
}

unsigned Registration::GetCredits() const {
    unsigned sum = 0;
    for (unsigned i = 0; i < count; i++) { 
        sum += results.get(i).GetCredits();
    }
    return sum;
}

unsigned Registration::GetCount() const { 
    return count; 
}
void Registration::SetCount(unsigned co) { 
    count = co; 
}

void Registration::AddResult(Result& result, unsigned index) {
    results.push(result);
}

string Registration::ToString() {
    string output;
    output = "Student ID: " + to_string(studentId) + '\n';
    output += "Semester: " + to_string(semester) + '\n';
    for (unsigned i = 0; i < count; i++) {
        output += results.get(i).ToString() + '\n';
    }
    return output;
}

istream& operator >> (istream& input, Registration& R) {
    input >> R.studentId >> R.semester >> R.count;

    string unitID, unitName;
    unsigned credit, day, month, year;
    float marks;

    for (int i = 0; i < (int) R.count; i++) {
        input >> unitID;
        input.ignore();  // discard new line
        getline(input, unitName);
        input >> credit >> marks >> day >> month >> year;
        Unit U(unitID, unitName, credit);
        Date D(day, month, year);
        Result result(U, marks, D);
        R.AddResult(result, i);
    }
    return input;
}

ostream& operator<<(ostream& os, Registration& R) {
    os << R.ToString();
    return os;
}
