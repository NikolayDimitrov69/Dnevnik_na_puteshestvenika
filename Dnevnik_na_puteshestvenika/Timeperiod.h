#ifndef __TIMEPERIOD_HPP
#define __TIMEPERIOD_HPP
#include <iostream>
#include <string>
#include <iterator>
#include "Date.h"

class Timeperiod {
private:
	Date start;

	Date end;
public:

	unsigned getStartYear() const {
		return start.getYear();
	};

	unsigned getEndYear() const {
		return end.getYear();
	};

	unsigned getStartDay() const {
		return start.getDay();
	};

	unsigned getEndDay() const {
		return end.getDay();
	};

	unsigned getStartMonth() const {
		return start.getMonth();
	};

	unsigned getEndMonth() const {
		return end.getMonth();
	};

	Timeperiod();

	Timeperiod(Date _start, Date _end);

	friend std::istream& operator >> (std::istream&, Timeperiod&);

	friend std::ostream& operator << (std::ostream&, const Timeperiod&);
};



#endif // __TIMEPERIOD_HPP
