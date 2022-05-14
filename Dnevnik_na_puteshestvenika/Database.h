#ifndef __DATABASE_HPP
#define __DATABASE_HPP
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include "Timeperiod.h"

using std::string;

class Database;

using DatabaseDb = std::vector<Database>;

class Database {
private:
	//! Променлива тип низ за дестинация.
	string destination;

	Timeperiod time;

	//! Променлива тип беззнаков за оценка между 0 и 5.
	unsigned grade;

	//! Променлива тип низ за коментар.
	string comment;

	//! Променлива тип низ за снимки.
	string photos;

public:
	//! Селектор за дестинация.
	string getDestination() const {
		return destination;
	};

	//
	//to be added for timeperiod

	//! Селектор за оценка.
	unsigned getGrade() const {
		return grade;
	}

	//! Селектор за коментар.
	string getComment() const {
		return comment;
	};

	//! Селектор за снимки.

	Database();

	Database(string _destination, Timeperiod _time, unsigned _grade, string _comment, string _photos);

};

std::ostream& operator<<(std::ostream&, const Database&);

std::istream& operator>>(std::istream&, Database&);

std::ostream& operator<<(std::ostream&, const DatabaseDb&);

std::istream& operator>>(std::istream&, DatabaseDb&);


#endif // __DATABASE_HPP