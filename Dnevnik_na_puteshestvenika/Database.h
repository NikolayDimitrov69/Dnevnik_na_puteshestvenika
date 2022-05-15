#ifndef __DATABASE_HPP
#define __DATABASE_HPP
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include "Timeperiod.h"
#include "Photos.h"

using std::string;

class Database;

//! Колекция от множество датабаза обекти. Тази колекция е динамична, резервира сама памет колкото е необходимо.
using DatabaseDb = std::vector<Database>;

class Database {
private:
	//! Променлива тип низ за дестинация.
	string destination;

	//! Променлива тип времевипериод за времеви период.
	Timeperiod time;

	//! Променлива тип беззнаков за оценка между 0 и 5.
	unsigned grade;

	//! Променлива тип низ за коментар.
	string comment;

	//! Променлива тип снимки за снимки.
	Photos photos;

public:
	//! Селектор за дестинация.
	const string getDestination() const {
		return destination;
	};

	//! Селектор за времеви период.
	const Timeperiod& getTimeperiod() const {
		return time;
	}

	//! Селектор за оценка.
	unsigned getGrade() const {
		return grade;
	}

	//! Селектор за коментар.
	const string getComment() const {
		return comment;
	};

	//! Селектор за снимки.
	const Photos& getPhotos() const
	{
		return photos;
	}

	Database() {

	}
	//! Конструктор за база данни.
	Database(string _destination, const Timeperiod& _time, unsigned _grade, string _comment, const Photos& _photos)
		:destination(_destination),
		time(_time),
		grade(_grade),
		comment(_comment),
		photos(_photos)
	{}

};

std::istream& operator>>(std::istream&, Database&);

std::ostream& operator<<(std::ostream&, const Database&);

std::istream& operator>>(std::istream&, DatabaseDb&);

std::ostream& operator<<(std::ostream&, const DatabaseDb&);

#endif // __DATABASE_HPP