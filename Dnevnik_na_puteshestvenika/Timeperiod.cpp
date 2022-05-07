#include <iostream>
#include "Timeperiod.h"

unsigned Timeperiod::getStartYear() const {
	return start.getYear();
}

unsigned Timeperiod::getEndYear() const {
	return end.getYear();
}

unsigned Timeperiod::getStartDay() const {
	return start.getDay();
}

unsigned Timeperiod::getEndDay() const {
	return end.getDay();
}

unsigned Timeperiod::getStartMonth() const {
	return start.getMonth();
}

unsigned Timeperiod::getEndMonth() const {
	return end.getMonth();
}

Timeperiod::Timeperiod() {
	
}

Timeperiod::Timeperiod(Date _start, Date _end):start(_start),end(_end) {

}

std::istream& operator >> (std::istream& is, Timeperiod& period) {	
	return is >> period.start >> period.end;
}

std::ostream& operator << (std::ostream& os, const Timeperiod& period) {
	return os << period.start << '\n' << period.end;
}



