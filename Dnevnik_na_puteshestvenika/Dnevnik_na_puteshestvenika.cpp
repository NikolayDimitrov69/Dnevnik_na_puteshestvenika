#include <iostream>
#include "Dnevnik_na_puteshestvenika.h"

int main()
{
    DNP app;

    do
    {
        char command = app.nextCommand();

        switch (command)
        {
        case 'l':
        {
            app.commandLogin();
            break;
        }
        case 'n':
        {
            app.commandCreateNewUser();
            break;
        }
        case 'p':
        {
            app.commandPrintReviews();
            break;
        }
        case 'a':
        {
            app.commandAddReview();
            break;
        }
        case 'q':
        {
            std::cout << "bye...\n";
            return 0;
        }
        }
    } while (true);

}
