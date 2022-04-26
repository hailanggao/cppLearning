#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>
class Time {

public:
	Time();
	Time(unsigned h, unsigned m);
	Time(const Time& time);
	/**
	* Get hour of class
	* @return unsigned
	*/
	unsigned GetHour() const;
	/**
	* Get minute of class
	* @return unsigned
	*/
	unsigned GetMinute() const;
	/**
	 * Print time output
	 * @return string
	 */
	std::string ToString();

private:
	unsigned hour;
	unsigned minute;

};

#endif