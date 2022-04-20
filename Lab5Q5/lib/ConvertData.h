
#ifndef CONVERTDATA_H_INCLUDED
#define CONVERTDATA_H_INCLUDED


#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
#include <sstream>

/**
* Convert string time (e.g., "hour:minute")
* @return tuple(hour, minute)
*/
std::tuple<unsigned, unsigned> convertTime(std::string rawTime) {
    std::string hour, minute;
    char colon = ':';
    std::stringstream sRawTime(rawTime);
    std::getline(sRawTime, hour, colon);
    std::getline(sRawTime, minute, colon);
    return std::make_tuple(std::stoi(hour), std::stoi(minute));
}

/**
* Convert string Date(e.g., "day/month/year")
* @return tuple(day, month, year)
*/
std::tuple<unsigned, unsigned, unsigned> convertDate(std::string rawDate) {
    std::string day, month, year;
    char slash = '/';
    std::stringstream sRawDate(rawDate);
    std::getline(sRawDate, day, slash);
    std::getline(sRawDate, month, slash);
    std::getline(sRawDate, year, slash);
    return std::make_tuple(std::stoi(day), std::stoi(month), std::stoi(year));

}

/**
* Convert string Date and Time (e.g., ""day/month/year hour:minute"
* @return tuple(Date class, TIme class)
*/
std::tuple<Date, Time> splitDate(std::string rawDateTime) {

    std::string tmp;
    unsigned hour, minute, day, month, year;
    char space = ' ';
    std::stringstream sRawDate(rawDateTime);
    std::getline(sRawDate, tmp, space);
    std::tie(day, month, year) = convertDate(tmp);
    Date date(day, month, year);
    std::getline(sRawDate, tmp, space);
    std::tie(hour, minute) = convertTime(tmp);
    Time time(hour, minute);
    return std::make_tuple(date, time);
}

/**
* check the string is number
* @return true if it is, otherwise false
*/
bool isNumber(const std::string& s) {
    if (s == "") return false;
    for (char const& ch : s) {
        if (std::isdigit(ch) == 0) return false;
    }
    return true;
}

#endif