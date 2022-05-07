#include <iostream>
#include <vector>
#include "User.h"
#include "Database.h"

int main()
{
    bool loginSuccess = false;
    std::string username;

    // da natovari user basata danni ot file users.db
    std::vector<User> users;
    // pechati meniuto s 2 opcii - register i login i izhod
    char option;
    do
    {
        std::cout << "Enter the letter of your choice:";
        std::cin >> option;

        if (option == 'q')
        {
            return 0;
        }
        if (option == 'r')
        {
            // registraciq na potrebitel 
            // 1. chetem imeto
            // 2. proverqvame za veche sushtestvuvasht user (ako da - error)
            // 3. suzdavame nov user obekt i go zapisvame s dobavqne v users.db i v users promenliva
            // 4. pechati meniuto s 2 opcii - kachvane i tursene i izhod
        }
        else if (option == 'l')
        {
            // login na user
            // 1. chetem imeto
            // 2. proverqvame za susht user i pravilna parola
            // 3. ako uspee == true
            // 4. pechati meniuto s 2 opcii - kachvane i tursene i izhod
        }
        else if (option == 'f' && loginSuccess == true) //------------
        {
            // pokazvane na otzivi
            // 1. proverqvame dali loginsucc == true
            // 2. ako da - chetem za vseki user ot users mu otvarqme suotvetnata baza danni (ani123.db) i gi izchitame i pulnim vector db
            std::vector<Database> db;
            // 3. izpechatvame vsichki obekti ot db, koito sa s iskaniq grad
            // 4. subirame vsichki ocenki i broim kolko sa za sredna ocenka
            unsigned totalGrade;
            unsigned numberOfGrades;
            // 4. pechati meniuto s 2 opcii - kachvane i tursene i izhod
        }
        else if (option == 'a' && loginSuccess == true)
        {
            // dobavqne na otziv za grad
            // 1. dali login succ e true
            // 2. suzdavame nov datebase obekt
            // 3. zapisvame dobavqiki vuv faila za username (username.db)
            // 4. pechati meniuto s 2 opcii - kachvane i tursene i izhod
        }
        else
        {
            std::cout << "Invalid command!";
        }

    } while (true);
}
