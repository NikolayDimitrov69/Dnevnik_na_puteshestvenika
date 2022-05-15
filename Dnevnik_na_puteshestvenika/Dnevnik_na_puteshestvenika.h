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

    //! Конструктор, изчита потребителите.
	DNP() {
		loadUsersDb();
	}

    //! Фунцкия за четене на всички потребители в UserDb веткора.
	void loadUsersDb() {
		std::ifstream usersDbFileStream(USERDB_FILE);
		usersDbFileStream >> usersDb;
	}
    //! Записване на UserDb ветора във файл.
	void saveUsersDb()
	{
		std::ofstream usersDbFile(USERDB_FILE);
		usersDbFile << usersDb;
	}

    void commandLogin()
    {
        std::string _username;
        std::cout << "Username: ";
        std::cin >> _username;

        User* userIt = nullptr;
        //! Проверка дали съществува потребителя.
        for (int i = 0; i < usersDb.size(); ++i)
        {
            //! Ако е намерен break;
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
            //! Паролата може да съдържа спейс, чете до натискане на ентър.
            std::getline(std::cin >> std::ws, password);

            if (password == userIt->getPassword())
            {
                std::cout << "login success\n";
                //! Ако username не е празен низ означава че сме потребителят е оторизиран.
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
        //! Това ще извика стрийм операторите написани за User типа.
        std::cin >> newUser;

        
        User* userIt = nullptr;
        //! Проверка дали съществува потребителя.
        for (int i = 0; i < usersDb.size(); ++i)
        {
            //! Ако е намерен break;
            if (usersDb[i].getName() == newUser.getName())
            {
                userIt = &usersDb[i];
                break;
            }
        }

        if (userIt != nullptr)
        {
            std::cout << "error: username already exists\n";
            return;
        }
        //! Ако потребителят не съществува добавяне към вектор UserDb
        usersDb.push_back(newUser);
        //! Записване на разширения вектор във файла.
        saveUsersDb();
    }

    void commandPrintReviews()
    {
        std::string destination;
        std::cout << "Destination: ";
        std::cin >> destination;

        //! Променлива тип беззнаков за статиска на ревюта.
        unsigned totalGrade = 0;
        //! Променлива тип беззнаков за статиска на ревюта.
        unsigned numberOfGrades = 0;

        //! Цикъл за всеки един потребител.
        for (User& user : usersDb)
        {
            DatabaseDb databaseDb;

            //! Отваряне и изчитане на базата с коментарите за текущия потребител като името на базата е името на потребителя + ".db".
            std::ifstream databaseDbFile(user.getName() + ".db");
            databaseDbFile >> databaseDb;
            //! Цикъл за всеки един коментар
            for (Database& database : databaseDb)
            {
                //! Ако този на този коментар е за исканата дестинация да се изпечатва.
                if (database.getDestination() == destination)
                {
                    //! Брой на намерени коментари.
                    numberOfGrades++;
                    std::cout << "review[" << numberOfGrades << "]: "
                        << "user: " << user.getName() << " "
                        << database
                        << std::endl;
                    //! Сума на всички оценки от намерените коментари.
                    totalGrade += database.getGrade();
                }
            }
        }

        float averageGrade = 0.0;

        if (numberOfGrades > 0)
        {
            averageGrade = (float)totalGrade / (float)numberOfGrades;
        }
        std::cout << "Found " << numberOfGrades << " grades. "
            << "Average grade " << averageGrade
            << std::endl;
    }

    void commandAddReview()
    {
        Database database;
        //! Това ще извика стрийм операторите написани за Database типа.
        std::cin >> database;

        //! Изчитаме всички ревюта за текущия потребител от неговия файл.
        DatabaseDb databaseDb;
        std::ifstream reviewsDbFile(username + ".db");
        reviewsDbFile >> databaseDb;

        //! Добавяме новото ревю отзад във вектора DatabaseDb.
        databaseDb.push_back(database);

        //! Запис на вектор DatabaseDb обратно във файла на потребителя.
        std::ofstream reviewsDbUpdateFile(username + ".db");
        reviewsDbUpdateFile << databaseDb;
    }

    //! Функция за принтиране на главното меню.
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

    //! Чете и проверава за валидна команда.
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