#include<iostream>
#include "Database.h"

using std::string;

Database::Database() {
	destination = "empty";
	grade = 5;
	comment = "empty";
	photos = "none";
}

Database::Database(string _destination, Timeperiod _time, unsigned _grade, string _comment, string _photos)
	:destination(_destination),
	grade(_grade),comment(_comment),
	photos(_photos) 
{}

