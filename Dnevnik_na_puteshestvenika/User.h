#pragma once
#include <iostream>

using std::string;

class User {
private:

	//! Променлива тип низ за потребителско име.
	string username;

	//! Променлива тип низ за парола.
	string password;

	//! Променлива тип низ за имейл.
	string email;

public:

	//! Мутатор за потребителско име.
	void setUsername(string);

	//! Селектор за потребилтеско име.
	string getName();

	//! Мутатор за потребителска парола.
	void setPassword(string);

	//! Селектор за потребителска парола.
	string getPassword();

	//! Мутатор за потрелбилски имейл адрес.
	void setEmail(string);

	//! Сeлектор за потрелбилски имейл адрес.
	string getEmail();

	//! Конструктор за "User".
	User(string username = "default", string password = "default", string email = "default");
};

