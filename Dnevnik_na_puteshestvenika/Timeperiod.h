#ifndef __TIMEPERIOD_HPP
#define __TIMEPERIOD_HPP
#include <iostream>
#include "Date.h"

class Timeperiod {
private:
	Date start;

	Date end;
public:

	unsigned getStartYear() const;

	unsigned getEndYear() const;

	unsigned getStartDay() const;

	unsigned getEndDay() const;

	unsigned getStartMonth() const;

	unsigned getEndMonth() const;

	Timeperiod();

	Timeperiod(Date _start, Date _end);

	friend std::istream& operator >> (std::istream&, Timeperiod&);

	friend std::ostream& operator << (std::ostream&, const Timeperiod&);
};



#endif // __TIMEPERIOD_HPP
