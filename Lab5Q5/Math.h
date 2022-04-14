#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <iostream>
#include "Vector.h"

/**
* Calculate sum of values
* skip if the value is INF
* @return sum
*/
float sumCal(Vector<float> dataArray, int len) {
	float sum = 0.0;
	if (len == 0) return sum;
	for (int i = 0; i < len; i++) {
		if (!std::isinf(dataArray.get(i))) {
			sum += dataArray.get(i);
		}
	}
	return sum;
}

/**
* Calculate mean of values
* @return mean
*/
float meanCal(Vector<float> dataArray, int len) {
	if (len == 0) return 0.0;
	float sum = sumCal(dataArray, len);
	return sum / len;
}

/**
* Calculate standard deviation
* @return sd
*/
float sdCal(Vector<float> dataArray, int len) {
	if (len == 0) return 0.0;
	float mean = meanCal(dataArray, len);

	float sum = 0.0;
	for (int i = 0; i < len; i++) {
		if (!std::isinf(dataArray.get(i))) {
			sum += (dataArray[i] - mean) * (dataArray[i] - mean);
		}
	}
	float sd_sq = sum / (len - 1);
	return std::sqrt(sd_sq);
}

/**
* Convert speed from m/s to km/h
*/
float msToKmh(const float s){
	float speed = (float) 3.6 * s;
	return speed;
}

//print func
void log(unsigned int count, float mean, float sd) {
	std::cout << "The number of floating point values(N) : " << count << std::endl;
	std::cout << "The mean of the floating point values : " << mean << std::endl;
	std::cout << "The sample standard deviation (s):  " << sd << std::endl;
}

#endif
