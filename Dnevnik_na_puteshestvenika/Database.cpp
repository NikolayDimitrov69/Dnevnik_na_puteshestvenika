#include<iostream>
#include "Database.h"

using std::string;

//! Входен оператор за DatabaseDb
std::istream& operator>>(std::istream& is, Database& database) {
	std::string destination;
	Timeperiod time;
	unsigned grade;
	Photos photos;
	std::string comment;
	//! Проверка дали сме в конзола.
	if (is.rdbuf() == std::cin.rdbuf()) {
		std::cout << "Enter destination: ";
		is >> destination;
		is >> time;
		do {
			std::cout << "Enter grade: ";
			is >> grade;
			//! Проверка за оценка до 5 включително.
		} while (grade > 5);
		is >> photos;
		std::cout << "Enter comment: ";
		//! https://en.cppreference.com/w/cpp/io/manip/ws
		std::getline(is >> std::ws, comment);
	}
	//! Влиза тук, когато сме във файлов поток. Елементите са разделени със спейс, коментара го четем като всичко останало до края на реда включително спейсове.
	else
	{
		is >> destination >> time >> grade >> photos;
		//! https://en.cppreference.com/w/cpp/io/manip/ws
		std::getline(is >> std::ws, comment);
	}

	database = Database(destination, time, grade, comment, photos);

	return is;
}
//! Изходен оператор за DatabaseDb
std::ostream& operator<<(std::ostream& os, const Database& database) {
	if (os.rdbuf() == std::cout.rdbuf()) {
		os << "Destination: " << database.getDestination() << ' '
		   << database.getTimeperiod() << ' '
		   << "Grade: " << database.getGrade() << ' '
		   << "Comment: " << database.getComment() << ' '
		   << database.getPhotos();
	}
	//! Влиза тук, когато сме във файлов поток. Важно е коментарът да е последен защото четем всички последни спейсове като част от коментара. Всички елементи преди коментара не трябва да съдържат спейсове.
	else
	{
		os << database.getDestination() << ' '
			<< database.getTimeperiod() << ' '
			<< database.getGrade() << ' ' 
			<< database.getPhotos() << ' '
			<< database.getComment();
		   
	}
	return os;
}

//! Входен оператор за вектора "DatabaseDb"
std::istream& operator>>(std::istream& is, DatabaseDb& database) {
	//! Кодът е взаимстван: Четем от входния поток посредством итератори, които четата от потока обекти от тип Database. Copy чете докато не свърши входния поток. Всеки прочетен Database обект се записва във вектора DatabaDb посредством итератор, който вика push_back метод.
	std::copy(std::istream_iterator<Database>(is), std::istream_iterator<Database>(), std::back_inserter(database));
	return is;
}
//! Изходен оператор за вектора "DatabaseDb"
std::ostream& operator<<(std::ostream& os, const DatabaseDb& database) {
	//! Кодът е взаимстван: Копира всеки Databse елемент от DatabaseDb като copy го записва в изходящия поток посредством итератор и разделя всеки Database елемент с нов ред.
	std::copy(database.begin(), database.end(), std::ostream_iterator<Database>(os, "\n"));
	return os;
}