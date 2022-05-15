#ifndef __DNP_H
#define __DNP_H

#include <fstream>
#include "User.h"
#include "Database.h"

class DNP {
private:
	UsersDb usersDb;
	std::string username;
public:
	static constexpr char USERDB_FILE[] = "users.db";

	DNP() {
		loadUsersDb();
	}

	void loadUsersDb() {
		std::ifstream usersDbFileStream(USERDB_FILE);
		usersDbFileStream >> usersDb;
	}

	void saveUsersDb()
	{
		std::ofstream usersDbFile(USERDB_FILE);
		usersDbFile << usersDb;
	}

    void commandLogin()
    {
        std::string _username;
        std::cout << "username: ";
        std::cin >> _username;

        User* userIt = nullptr;
        for (int i = 0; i < usersDb.size(); ++i)
        {
            if (usersDb[i].getName() == _username)
            {
                userIt = &usersDb[i];
                break;
            }
        }

        if (userIt != nullptr)
        {
            std::string password;
            std::cout << "password: ";
            std::cin >> password;

            if (password == userIt->getPassword())
            {
                std::cout << "login success\n";
                username = _username;
            }
            else
            {
                std::cout << "error: wrong password\n";
            }
        }
        else
        {
            std::cout << "error: unknown username\n";
        }
    }

    void commandCreateNewUser()
    {
        User newUser;
        std::cin >> newUser;

        UsersDb::const_iterator userIt = std::find_if(usersDb.begin(), usersDb.end(),
            [&](const User& user) {
                return user.getName() == newUser.getName();
            });

        if (userIt != usersDb.end())
        {
            std::cout << "error: username already exists\n";
            return;
        }

        usersDb.push_back(newUser);
        saveUsersDb();
    }

    void commandPrintReviews()
    {
        std::string destination;
        std::cout << "Destination: ";
        std::cin >> destination;

        unsigned totalGrade = 0;
        unsigned numberOfGrades = 0;

        // all reviews from all users
        for (User& user : usersDb)
        {
            DatabaseDb databaseDb;

            std::ifstream databaseDbFile(user.getName() + ".db");
            databaseDbFile >> databaseDb;

            for (Database& database : databaseDb)
            {
                if (database.getDestination() == destination)
                {
                    numberOfGrades++;
                    std::cout << "review[" << numberOfGrades << "]: "
                        << "user: " << user.getName() << " "
                        << database
                        << std::endl;
                    totalGrade += database.getGrade();
                }
            }
        }

        float averageGrade = 0.0;
        if (numberOfGrades > 0)
        {
            averageGrade = (float)totalGrade / (float)numberOfGrades;
        }
        std::cout << "found " << numberOfGrades << " grades. "
            << "Average grade " << averageGrade
            << std::endl;
    }

    void commandAddReview()
    {
        Database database;
        std::cin >> database;

        if (!database.validate()) return;

        // all reviews for the current user
        DatabaseDb databaseDb;
        std::ifstream reviewsDbFile(username + ".db");
        reviewsDbFile >> databaseDb;

        databaseDb.push_back(database);

        std::ofstream reviewsDbUpdateFile(username + ".db");
        reviewsDbUpdateFile << databaseDb;
    }

    void printMenu()
    {
        std::cout << std::endl;

        if (isLoginSuccess())
        {
            std::cout << "Select an action by typing the character:\n"
                "a: add review\n"
                "p: print reviews\n"
                "q: quit\n"
                "> ";
        }
        else
        {
            std::cout << "Select an action by typing the character:\n"
                "n: create new user\n"
                "l: login\n"
                "q: quit\n"
                "> ";
        }
    }

    char nextCommand()
    {
        printMenu();

        char command;
        std::cin >> command;

        if (isLoginSuccess())
        {
            if (command != 'a' && command != 'p' && command != 'q')
            {
                std::cout << "error: invalid command\n";
                return ' ';
            }
        }
        else
        {
            if (command != 'n' && command != 'l' && command != 'q')
            {
                std::cout << "error: invalid command\n";
                return ' ';
            }
        }

        return command;
    }

    bool isLoginSuccess()
    {
        return !username.empty();
    }
};



#endif // __DNP_H