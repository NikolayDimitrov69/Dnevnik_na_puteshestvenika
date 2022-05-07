#include <iostream>
#include "User.h"

using std::string;

void User::setUsername(string _username) {
	username = _username;
}
string User::getName() {
	return username;
}

void User::setPassword(string _password) {
	password = _password;
}
string User::getPassword() {
	return password;
}

void User::setEmail(string _email) {
	email = _email;
}
string User::getEmail() {
	return email;
}

User::User(string _username, string _password, string _email) :username(_username), password(_password), email(_email) {

}
