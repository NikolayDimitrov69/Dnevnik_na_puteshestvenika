#include<iostream>
#include "Database.h"

using std::string;

void Database::setDestination(string _destination) {
	destination = _destination;
}

string Database::getDestination() {
	return destination;
}

/*
to be added for time period
*/

void Database::setGrade(unsigned _grade) {
	grade = _grade;
}

unsigned Database::getGrade() {
	return grade;
}

void Database::setComment(string _comment) {
	comment = _comment;
}

string Database::getComment() {
	return comment;
}

void Database::setPhotos(string _photos) {
	photos = _photos;
}

string Database::getPhotos() {
	return photos;
}
