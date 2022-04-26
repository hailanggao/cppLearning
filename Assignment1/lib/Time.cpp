#include "Time.h"
#include <string>

Time::Time() {
	hour = 0;
	minute = 0;
}

Time::Time(unsigned h, unsigned m) {
	hour = h;
	minute = m;
}

Time::Time(const Time& time) {
	hour = time.hour;
	minute = time.minute;
}


unsigned Time::GetHour() const{
	return hour;
}

unsigned Time::GetMinute() const{
	return minute;
}

std::string Time::ToString() {
	return std::to_string(hour) + ":" + std::to_string(minute);
}