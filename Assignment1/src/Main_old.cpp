#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>

#include "../lib/date.h"
#include "../lib/Time.h"
#include "../lib/vector.h"
#include "../lib/ConvertData.h"
#include "../lib/Math.h"

typedef struct {
    Date d;
    Time t;
    float speed;
} WindLogType;

typedef struct {
    unsigned year;
    unsigned month;
    float averageSpeed;
    float sd;
    std::string msg;
} yearData;

int main() {
    
    //open file, return -1 if the input file does not exist
    std::ifstream myFile;
    myFile.open("./data//MetData-31-3b_test.csv");
    if (!myFile) return -1;

    std::string line;
    const char comma = ',';
    const char colon = ':';
    const std::string WAST = "WAST";
    const std::string S = "S";
    int WAST_Index = -1, S_Index = -1;
    Vector<WindLogType> windlog;
    Vector<yearData> table;
    std::string sub;

    //Get the indexes of required columns at the first line
    std::getline(myFile, line);
    std::stringstream sstr(line);
    int index = 0;
    while (sstr.good()) {
        std::getline(sstr, sub, comma);
        if (sub == WAST) {
            WAST_Index = index;
        }else if(sub == S) {
            S_Index = index;
        }
        index++;
    }

    std::cout << "WAST INDEX: " << WAST_Index << std::endl;
    std::wcout << "S INDEX: " << S_Index << std::endl;
    //Get required data and store them into windlog
    while (std::getline(myFile, line)) {
        std::stringstream sstr(line);
        int i = 0;
        WindLogType wl;
        while (sstr.good()) {
            std::getline(sstr, sub, comma);
            if (i == WAST_Index) { //first column
                if (sub.empty()) break;
                Date date;
                Time time;
                std::tie(date, time) = splitDate(sub);
                wl.d = date;
                wl.t = time;
            }
            else if (i == S_Index) {
                //If the cell is empty or other non_digit value inside, then we set the cell to INF
                if (isNumber(sub)) {
                    float speed = std::stof(sub);
                    wl.speed = speed;
                }
                else {
                    constexpr float speed = std::numeric_limits<float>::infinity();
                    wl.speed = speed;
                }
            }
            i++;
        }
        //std::cout << wl.speed << std::endl;
        if (wl.d.GetYear() == 0000) continue;
        else { windlog.push(wl); }
        
    }
    //windlog input is completed
    //close the input file
    myFile.close();

    std::cout << "windlog input is completed" << std::endl;

    yearData yd;
    yd.year = windlog.get(0).d.GetYear();
    yd.month = windlog.get(0).d.GetMonth();

    std::cout << yd.month << yd.year << ": " << std::endl;
    Vector<float> speedArray;
    //get all speed value in windlog
    //transfer speed from m/s to km/h
    //and put them into speedArray
    for (auto& j : windlog) {
        if (yd.year == j.d.GetYear()) {
            if (yd.month == j.d.GetMonth()) {
                if (!isinf(j.speed)) {
                    float sKmh = msToKmh(j.speed);
                    speedArray.push(sKmh);
                }
            }
            else { //enter next month
                if (speedArray.getSize() == 0) { //no data
                    yd.msg = "No Data";
                    std::cout << yd.month << yd.year << ": " << yd.msg << std::endl;
                    table.push(yd);
                    yd = {};
                }
                else {
                    float averageSpeed = meanCal(speedArray, speedArray.getSize());
                    float sd = sdCal(speedArray, speedArray.getSize());
                    yd.averageSpeed = averageSpeed;
                    yd.sd = sd;
                    std::cout << yd.month << yd.year << ": " << std::endl;
                    std::cout << "Average speed: " << averageSpeed << "km/h" << std::endl;
                    std::cout << "Sample stdev: " << sd << std::endl;
                    table.push(yd);
                    yd = {};
                    speedArray.clear();

                    if (!isinf(j.speed)) {
                        float sKmh = msToKmh(j.speed);
                        speedArray.push(sKmh);
                    }
                }
                yd.month = j.d.GetMonth();
            }
            
        }
        else { //next year
            yd.year = j.d.GetYear();
            yd.month = j.d.GetMonth();
            
        }
        
    }

    ////output average and standard deviation
    //float averageSpeed = meanCal(speedArray, speedArray.getSize());
    //float sd = sdCal(speedArray, speedArray.getSize());
    //std::cout << "The Average Wind Speed are: " << averageSpeed << " KM/H." << std::endl;
    //std::cout << "The sample standard deviation(s): " << sd << std::endl;

    //print all values that match average value
    //and store all values into testoutput.csv file

    //std::ofstream ofile("testoutput.csv");
    //int count = 0;
    //for (auto& j : windlog) {
    //    float sKmh = msToKmh(j.speed);
    //    if (sKmh == averageSpeed) {
    //        std::cout << j.speed << std::endl;
    //        std::cout << j.d.ToString() << " " << j.t.ToString() << std::endl;
    //        count++;
    //    }
    //    ofile << j.d.ToString() << comma << j.t.ToString() << comma << j.speed << "\n";
    //}
    ////testoutput.csv input completed
    ////close output file
    //ofile.close();

    ////It is possible that no data matches the average
    //if (count == 0) {
    //    std::cout << "No data matches the Average." << std::endl;
    //}
}
