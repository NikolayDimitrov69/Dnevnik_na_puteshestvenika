#ifndef __DATE_HPP
#define __DATE_HPP

class Date {
private:
	//! Променлива тип беззнакова за дни от 1 до 28/30/31 в зависимост от месеца.
	unsigned day;

	//! Променлива тип беззнакова за месеци от 1 до 12.
	unsigned month;

	//! Променлива тип беззнакова за години.
	unsigned year;
public:
	//! Селектор за дни.
	unsigned getDay() const {
		return day;
	};

	//! Селектор за месеци.
	unsigned getMonth() const {
		return month;
	};

	//! Селектор за години.
	unsigned getYear() const {
		return year;
	};

	//! Конструктор за дата.
	Date(unsigned _year = 0, unsigned _month = 1, unsigned _day = 1);

	friend std::istream& operator >> (std::istream&, Date&);
};

std::ostream& operator << (std::ostream&, const Date&);

#endif // __DATE_HPP