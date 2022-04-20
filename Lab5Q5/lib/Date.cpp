
// Doxygen comments are placed .h files

#include "date.h"
#include <string>

Date::Date() {
    m_day = 1;
    m_month = 1;
    m_year = 0000;
}

Date::Date(unsigned day, unsigned month, unsigned year) {
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::Date(const Date& other) {
    m_day = other.m_day;
    m_month = other.m_month;
    m_year = other.m_year;
}

unsigned Date::GetDay() const {
    return m_day; 
}

void Date::SetDay(unsigned day) { 
    m_day = day; 
}

unsigned Date::GetMonth() const { 
    return m_month; 
}

void Date::SetMonth(unsigned month) { 
    m_month = month; 
}

unsigned Date::GetYear() const { 
    return m_year; 
}

void Date::SetYear(unsigned year) {
    m_year = year; 
}

std::string Date::ToString() {
    return std::to_string(m_day) + " " + ConvertMonthToString() + 
        " " + std::to_string(m_year);
}

std::string Date::ConvertMonthToString() {
    std::string result;
    switch (m_month) {
        case 1:
            result = "January";
            break;
        case 2:
            result = "February";
            break;
        case 3:
            result = "March";
            break;
        case 4:
            result = "April";
            break;
        case 5:
            result = "May";
            break;
        case 6:
            result = "June";
            break;
        case 7:
            result = "July";
            break;
        case 8:
            result = "August";
            break;
        case 9:
            result = "September";
            break;
        case 10:
            result = "October";
            break;
        case 11:
            result = "November";
            break;
        case 12:
            result = "December";
            break;
        default:
            result = "January";
            break;
    }
    return result;
}
