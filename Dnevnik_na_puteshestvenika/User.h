#ifndef __USER_HPP
#define __USER_HPP
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using std::string;

class User;

using UsersDb = std::vector<User>;

class User {
private:

	//! Променлива тип низ за потребителско име.
	string username;

	//! Променлива тип низ за парола.
	string password;

	//! Променлива тип низ за имейл.
	string email;

public:
	//! Селектор за потребилтеско име.
	string getName() const {
		return username;
	};

	//! Селектор за потребителска парола.
	string getPassword() const {
		return password;
	};

	//! Сeлектор за потрелбилски имейл адрес.
	string getEmail() const {
		return email;
	};

	User()
	{};

	//! Конструктор за "User".
	User(string username = "default", string password = "default", string email = "default");

	bool validate()
	{
		return true;
	}

};

std::istream& operator >> (std::istream&, User&);

std::ostream& operator << (std::ostream&, const User&);

std::istream& operator >> (std::istream&, UsersDb&);

std::ostream& operator << (std::ostream&, const UsersDb&);

#endif // __USER_HPP