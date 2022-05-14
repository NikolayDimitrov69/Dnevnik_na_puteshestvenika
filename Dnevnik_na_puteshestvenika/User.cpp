#include <iostream>
#include "User.h"

using std::string;

User::User(string _username, string _password, string _email) 
    :username(_username), 
    password(_password), 
    email(_email) 
{}

std::istream& operator >> (std::istream& is, User& user) {
    std::string _username;
    std::string _email;
    std::string _password;
    //! Проверява дали сме в конзолата
    if (is.rdbuf() == std::cin.rdbuf())
    {
        std::cout << "enter username: ";
        is >> _username;
        std::cout << "enter email: ";
        is >> _email;
        std::cout << "enter password: ";
        //! https://en.cppreference.com/w/cpp/io/manip/ws - маха нежелани разстояния при въвеждане
        std::getline(is >> std::ws, _password);
    }
    else
    {
        is >> _username >> _email;
        //! https://en.cppreference.com/w/cpp/io/manip/ws - маха нежелани разстояния при въвеждане
        std::getline(is >> std::ws, _password);
    }

    user = User(_username, _email, _password);

    return is;
}

std::ostream& operator << (std::ostream & os, const User& user) {
    //! Проверява дали сме в конзолата
    if (os.rdbuf() == std::cout.rdbuf())
    {
         os << "username: " << user.getName() << " "
            << "email: " << user.getEmail() << " "
            << "password: " << user.getPassword();
    }
    else
    {
        os << user.getName() << " " << user.getEmail() << " " << user.getPassword();
    }
    return os;
}

std::istream& operator>>(std::istream& is, UsersDb& user)
{
    std::copy(std::istream_iterator<User>(is),
              std::istream_iterator<User>(),
              std::back_inserter(user));
    return is;
}

std::ostream& operator<<(std::ostream& os, const UsersDb& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<User>(os, "\n"));
    return os;
}

