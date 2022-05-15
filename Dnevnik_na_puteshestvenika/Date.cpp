#include <iostream>
#include "Date.h"

bool validate(Date& date) {
	bool isLeap{
		date.getYear() % 4 == 0 && (date.getYear() % 400 == 0 || !(date.getYear() % 100 == 0))
	};
	bool invalidYear1{
		date.getDay() >= 29 && date.getMonth() == 2 && !isLeap
	};

	bool invalidYear2{
		(date.getMonth() == 4 || date.getMonth() == 6 || date.getMonth() == 9 || date.getMonth() == 11) && (date.getDay() > 30)
	};

	if (invalidYear1 || invalidYear2 || date.getDay() > 31 || date.getMonth() > 12)
	{
		std::cout << "Invalid date.\n";
		return false;
		
	}
	else
	{
		return true;
	}
}

Date::Date(unsigned _year, unsigned _month, unsigned _day) 
	:day(_day),
	month(_month),
	year(_year) 
{}

std::istream& operator >> (std::istream& is, Date& date) {
	char placeHold;
	do {
		is >> date.year >> placeHold >> date.month >> placeHold >> date.day;
	} while (!validate(date));
	return is;
}

std::ostream& operator << (std::ostream& os, const Date& _date) {
	if (_date.getDay() < 10 && _date.getMonth() < 10)
		return os << _date.getYear() << "-0" << _date.getMonth() << "-0" << _date.getDay();
	else if (_date.getDay() < 10 && _date.getMonth() >= 10)
		return os << _date.getYear() << "-" << _date.getMonth() << "-0" << _date.getDay();
	else if (_date.getDay() >= 10 && _date.getMonth() < 10)
		return os << _date.getYear() << "-0" << _date.getMonth() << "-" << _date.getDay();
	else if (_date.getDay() >= 10 && _date.getMonth() >= 10)
		return os << _date.getYear() << "-" << _date.getMonth() << "-" << _date.getDay();
}