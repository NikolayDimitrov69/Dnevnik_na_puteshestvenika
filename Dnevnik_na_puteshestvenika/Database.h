#pragma once
#include<iostream>

using std::string;

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

	//! Мутатор за дестинация.
	void setDestination(string);

	//! Селектор за дестинация.
	string getDestination();

	//
	//to be added for timeperiod

	//! Мутатор за оценка.
	void setGrade(unsigned);

	//! Селектор за оценка.
	unsigned getGrade();

	//! Мутатор за коментар.
	void setComment(string);

	//! Селектор за коментар.
	string getComment();

	//! Мутатор за снимки.
	void setPhotos(string);

	//! Селектор за снимки.
	string getPhotos();

};

