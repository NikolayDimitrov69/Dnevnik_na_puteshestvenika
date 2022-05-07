#include <iostream>
#include "Date.h"

void Date::setDay(unsigned _day) {
	if (_day <= 31 && _day >= 1)
		day = _day;
}

unsigned Date::getDay() const {
	return day;
}

void Date::setMonth(unsigned _month) {
	if (_month <= 12 && _month >= 1)
		month = _month;
}

unsigned Date::getMonth() const {
	return month;
}

void Date::setYear(unsigned _year) {
	year = _year;
}

unsigned Date::getYear() const {
	return year;
}

Date::Date(unsigned _year, unsigned _month, unsigned _day) :day(_day), month(_month), year(_year) {

}

std::istream& operator >> (std::istream& is, Date& date) {
	char placeHold;
	return is >> date.year >> placeHold >> date.month >> placeHold >> date.day;
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