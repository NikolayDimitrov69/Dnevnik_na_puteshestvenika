#include <iostream>
#include "User.h"

using std::string;

User::User(string _username, string _password, string _email) 
    :username(_username), 
    password(_password), 
    email(_email) 
{}

//! Функция за валидация на мейл от стринг.
bool validate_email(string _email)
{
    int num_ats = 0;
    bool valid = true;
    //! Проверка дали не е празен, не започва с "@" и да не завършва с "@" или "." и тн.
    if (_email.size() == 0 || _email[0] == '@' || _email[0] == '.' || _email[_email.size()-1] == '@' || _email[_email.size() - 1] == '.'
        || _email[0] == '-' || _email[_email.size() - 1] == '-')
    {
        valid = false;
    }
    for (int i = 0; i < _email.size(); i++)
    {
        //! Сравнява в диапазон от а от z, които са една след като числа в ASCII таблицата.                
        if (_email[i] >= 'a' && _email[i] <= 'z')
        {
            continue;
        }
        //! Сравнява в диапазон от A от Z, които са една след като числа в ASCII таблицата. - аналогично.
        if (_email[i] >= 'A' && _email[i] <= 'Z')
        {
            continue;
        }
        //! Сравнява в диапазон от 0 от 9, които са една след като числа в ASCII таблицата. - аналогично.
        if (_email[i] >= '0' && _email[i] <= '9')
        {
            continue;
        }
        //! Позволява да са посредата.
        if (_email[i] == '_' || _email[i] == '-' || _email[i] == '.')
        {
            continue;
        }
        if (_email[i] == '@')
        {
            num_ats++;
            continue;
        }
        valid = false;
        break;
    }
    valid = valid && (num_ats == 1);
    if (!valid)
    {
        std::cout << "Invalid email.\n";
    }
    return valid;
}

//! Функция за валидация на потребителско име.


std::istream& operator >> (std::istream& is, User& user) {
    std::string _username;
    std::string _email;
    std::string _password;
    //! Проверява дали сме в конзолата
    if (is.rdbuf() == std::cin.rdbuf())
    {
        std::cout << "Enter username: ";
        is >> _username;
        do {
            std::cout << "Enter email: ";
            is >> _email;
        } while (!validate_email(_email));
        std::cout << "Enter password: ";
        //! https://en.cppreference.com/w/cpp/io/manip/ws - маха нежелани разстояния при въвеждане
        std::getline(is >> std::ws, _password);
    }
    //! Четем ред от users.db файла
    else
    {
        is >> _username >> _email;
        //! https://en.cppreference.com/w/cpp/io/manip/ws - чете заедно с "space" в една променлива при въвеждане във файла 
        std::getline(is >> std::ws, _password);
    }

    user = User(_username, _password, _email);

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

std::ostream& operator<<(std::ostream& os, const UsersDb& user)
{
    std::copy(user.begin(), user.end(), std::ostream_iterator<User>(os, "\n"));
    return os;
}



