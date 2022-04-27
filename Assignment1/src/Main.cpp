#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include <algorithm>

#include "../lib/date.h"
#include "../lib/Time.h"
#include "../lib/vector.h"
#include "../lib/ConvertData.h"
#include "../lib/Math.h"

typedef struct {
    Date d;
    float value;
} LogType;

//Compapre two dates according to month in acending order
bool compareMonth(LogType l1, LogType l2) {
    return (l1.d.GetMonth() < l2.d.GetMonth());
}

int main() {
    //std::wcout << "is it a decimal: " << isDecimal("2.1") << std::endl;
    std::string fileName;
    std::ifstream myFile;
    std::string attr;
    std::string yearInput;
    std::string monthInput = "-1";
    unsigned year = 0000;
    unsigned month = 0;
    const std::string WAST = "WAST";
    const std::string S = "S";
    const std::string T = "T";
    const std::string SR = "SR";
    int WAST_Index = -1;
    int S_Index = -1;
    int T_Index = -1;
    int SR_Index = -1;

    std::string line;
    const char comma = ',';
    const char colon = ':';
    std::string sub;
    Vector<LogType> windlog;
    Vector<LogType> temperlog;
    Vector<LogType> radilog;

    for (int a = 0; a < 4; a++) {
        if (a == 3) {
            std::cout << "[ERROR] Invalid input multi times, program will exit..." << std::endl;
            std::cout << "Please press return key to exit." << std::endl;
            return 0;
        }
        std::cout << "Please input the file name: ";
        std::cin >> fileName;
        //open file
        std::string filePath = "./data/" + fileName;
        myFile.open(filePath);
        if (!myFile) {
            std::cout << "File does not exist" << std::endl;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            std::cout << "[ERROR] Invalid input multi times, program will exit..." << std::endl;
            std::cout << "Please press return key to exit." << std::endl;
            return 0;
        }
        std::cout << "Please choose an attribute you are interested in" << std::endl;
        std::cout << "  [S] :Wind Seed, [SR] : Solar Radiation, [T]Ambient Air), [ALL]: ";
        std::cin >> attr;
        std::transform(attr.begin(), attr.end(), attr.begin(), ::toupper);
        if (attr == "SR" || attr == "T" || attr == "ALL") {
            std::cout << "--------------" << std::endl;
            break;
        }
        else if (attr == "S") {
            std::cout << "--------------" << std::endl;
            for (int n = 0; n < 4; n++) {
                if (n == 3) {
                    std::cout << "[ERROR] Invalid input multi times, program will exit..." << std::endl;
                    std::cout << "Please press return key to exit." << std::endl;
                    return 0;
                }
                std::cout << "Please choose a month" << std::endl;
                std::cout << " [1] Jan, [2] Feb ... : ";
                std::cin >> monthInput;
                if (isNumber(monthInput)) {
                    month = std::stoi(monthInput);
                    if (month > 0 && month < 13) {
                        std::cout << "--------------" << std::endl;
                        break;
                    }
                    std::cout << "[ERROR] Invalid input" << std::endl;
                }
                else {
                    std::cout << "[ERROR] Invalid input" << std::endl;
                }
            }
            break;
        }
        else {
            std::cout << "[ERROR] Invalid input" << std::endl;
        }
    }
    for (int m = 0; m < 4; m++) {
        if (m == 3) {
            std::cout << "[ERROR] Invalid input multi times, program will exit..." << std::endl;
            std::cout << "Please press return key to exit." << std::endl;
            return 0;
        }
        std::cout << "Please input a year you are interested in: ";
        std::cin >> yearInput;
        if (isNumber(yearInput)) {
            year = std::stoi(yearInput);
            std::cout << "--------------" << std::endl;
            break;
        }
        else {
            std::cout << "[ERROR] Invalid input" << std::endl;
        }
    }

    //IO check completed
    //Get the indexes of required columns at the first line
    std::getline(myFile, line);
    std::stringstream sstr(line);
    int index = 0;
    while (sstr.good()) {
        std::getline(sstr, sub, comma);
        if (sub == WAST) WAST_Index = index;
        else if (sub == S) S_Index = index;
        else if (sub == T) T_Index = index;
        else if (sub == SR) SR_Index = index;
        index++;
    }
    
    while (std::getline(myFile, line)) {
        std::stringstream sstr(line);
        int i = 0;

        LogType wl;
        LogType tl;
        LogType rl;

        while (sstr.good()) {
            std::getline(sstr, sub, comma);
            if (i == WAST_Index) {
                if (sub.empty()) break;
                Date date;
                Time time;
                std::tie(date, time) = splitDate(sub);
                if ((date.GetYear()) == year) { // We only push the year we are interested in
                    wl.d = date;
                    tl.d = date;
                    rl.d = date;
                }
            }

            else if (i == S_Index) {
                if (isNumber(sub) || isDecimal(sub)) {
                    float speed = std::stof(sub);
                    wl.value = msToKmh(speed);
                }
                else {
                    constexpr float speed = std::numeric_limits<float>::infinity();
                    wl.value = speed;
                }
            }

            else if (i == T_Index) {
                if (isNumber(sub) || isDecimal(sub)) {
                    float temper = std::stof(sub);
                    tl.value = temper;
                }
                else {
                    constexpr float temper = std::numeric_limits<float>::infinity();
                    tl.value = temper;
                }
            }

            else if(i == SR_Index) {
                if (isNumber(sub) || isDecimal(sub)) {
                    float radi = std::stof(sub);
                    if(radi >= 100) rl.value = (radi * 1/6) / 1000;
                }
                else {
                    constexpr float radi = std::numeric_limits<float>::infinity();
                    rl.value = radi;
                }
            }
            i++;
        }

        if (wl.d.GetYear() != 0000) windlog.push(wl);
        if (tl.d.GetYear() != 0000) temperlog.push(tl);
        if (rl.d.GetYear() != 0000) radilog.push(rl);
    }
    //close the input file
    myFile.close();
    
    std::sort(radilog.begin(), radilog.end(), compareMonth);

    if (attr == S) {
        Date tmp;
        tmp.SetMonth(month);
        tmp.SetYear(year);
        auto itMonth = std::find_if(windlog.begin(), windlog.end(), [&month](const LogType& l) { return l.d.GetMonth() == month;});
        auto itYear = std::find_if(windlog.begin(), windlog.end(), [&year](const LogType& l) { return l.d.GetYear() == year;});
        if (itYear == windlog.end()) {
            std::cout << tmp.ConvertMonthToString() << " " << year << ": No Data" << std::endl;
            return 0;
        }
        if (itMonth == windlog.end() ) {
            std::cout << tmp.ConvertMonthToString() << " " << year << ": No Data" << std::endl;
            return 0;
        }
        //If we find the data, then we sort them regarding month
        std::sort(windlog.begin(), windlog.end(), compareMonth);

        Vector<float> speedArray;
        for (auto& wlog : windlog) {
            if ( wlog.d.GetMonth() == month) {
                if (!isinf(wlog.value)) {
                    speedArray.push(wlog.value);
                }
            }
            else if(wlog.d.GetMonth() > month) { 
                float averageSpeed = meanCal(speedArray, speedArray.getSize());
                float sdSpeed = sdCal(speedArray, speedArray.getSize());
                std::cout << tmp.ConvertMonthToString() << " " << year << ":" << std::endl;
                std::cout << "Average speed: " << averageSpeed << " km/h" << std::endl;
                std::cout << "Sample stdev: " << sdSpeed << std::endl;
                return 0;
            }
            else {
                continue;
            }
        }
        float averageSpeed = meanCal(speedArray, speedArray.getSize());
        float sdSpeed = sdCal(speedArray, speedArray.getSize());
        std::cout << tmp.ConvertMonthToString() << " " << year << ":" << std::endl;
        std::cout << "Average speed: " << averageSpeed << " km/h" << std::endl;
        std::cout << "Sample stdev: " << sdSpeed << std::endl;
    }
   
    if (attr == T) {
        Date temperDate;
        temperDate.SetYear(year);
        std::cout << year << std::endl;
        auto itYear = std::find_if(windlog.begin(), windlog.end(), [&year](const LogType& l) { return l.d.GetYear() == year;});
        if (itYear == windlog.end()) {
            for (int i = 1; i < 13; i++) {
                temperDate.SetMonth(i);
                std::cout << temperDate.ConvertMonthToString() << " : No Data" << std::endl;
            }
            return 0;
        }

        std::sort(temperlog.begin(), temperlog.end(), compareMonth);
        Vector<float> temperArray;
        unsigned int month = 1;

        Date t;
        //the first log month should be the least month
        //monthes before least month should have no data
        if (month < temperlog.get(0).d.GetMonth()) {
            for (int j = month; j < temperlog.get(0).d.GetMonth(); j++) {
                t.SetMonth(j);
                std::cout << t.ConvertMonthToString() << " : No Data" << std::endl;
            }
            month = temperlog.get(0).d.GetMonth();
        }
        for (auto& temperItem : temperlog) {
            if (temperItem.d.GetMonth() == month) {
                if (!isinf(temperItem.value)) temperArray.push(temperItem.value);
            }
            else {
                t.SetMonth(month);
                month++;
                float averageTemper = meanCal(temperArray, temperArray.getSize());
                float sdTemper = sdCal(temperArray, temperArray.getSize());
                std::cout << t.ConvertMonthToString() << ": average: " << averageTemper << " degrees C, stdev: " << sdTemper << std::endl;
                Vector<float> temperArray;
                while (month < temperItem.d.GetMonth()) {
                    t.SetMonth(month);
                    std::cout << t.ConvertMonthToString() << " : No Data" << std::endl;
                    month++;
                }
                if (temperItem.d.GetMonth() == month) {
                    if (!isinf(temperItem.value)) temperArray.push(temperItem.value);
                }
            }
        }
        t.SetMonth(month);
        float averageTemper = meanCal(temperArray, temperArray.getSize());
        float sdTemper = sdCal(temperArray, temperArray.getSize());
        std::cout << t.ConvertMonthToString() << ": average: " << averageTemper << " degrees C, stdev: " << sdTemper << std::endl;
        //If last month is not Dec, we continue to print no data
        while (++month < 13) {
            t.SetMonth(month);
            std::cout << t.ConvertMonthToString() << " : No Data" << std::endl;
        }
    }
    return 0;
}

