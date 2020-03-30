#include "stdafx.h"

#include <vector>
#include <memory>
#include <iostream>
#include "0_controller.h"
#include "1_model.h"
#include "2_viewer.h"
#include "4_unit_test.h"

class PRINT_FIRST_SCREEN
{
    public:

    static void PrintFirstScreen ()
    {
		std::cout << "Welcome to program" << std::endl;
		std::cout << "" << std::endl;

        std::cout << "For create root_package use command: \"create root_package\"" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "For add new package in root_package use command: \"add path\"" << std::endl;
        std::cout << "Example: \"add root_package package_1\"" << std::endl;
        std::cout << "Or: \"add root_package/package_1 package_1_1\"" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "You can not use \"space\" in the name of package" << std::endl;
        std::cout << "For separate path of package you should to use '/' " << std::endl;

        std::cout << "" << std::endl;
        std::cout << "For remove package use command \"remove path\"" << std::endl;
        std::cout << "Example: \"remove root_package\"" << std::endl;
        std::cout << "Example: \"remove root_package/package_1 package_1_1\"" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "For print certain package use command \"print path\"" << std::endl;
        std::cout << "Example: \"print root_package\"" << std::endl;
        std::cout << "Example: \"print root_package package_1\"" << std::endl;
        std::cout << "Example: \"print root_package/package_1 package_1_1\"" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "For serialization to (from) file use command \"ser_to_file\" or \"ser_from_file\"" << std::endl;

        std::cout << "" << std::endl;
        std::cout << "Every command you should to use without \"\"." << std::endl;
        std::cout << "" << std::endl;
		system("pause");
        system("cls");
    }
};

int main ()
{
    static OBJECT object {};

    UNIT_TEST :: TestFunction ();

    system ("cls");
    std::cout << "All unit tests passed." << std::endl; system ("pause");
    system ("cls");

    PRINT_FIRST_SCREEN :: PrintFirstScreen ();

    // loop where we getting command and execute it
    // MVC pattern
    while (true)
    {
       std::string command = INPUT_USER_COMMAND::InputUserCommand (""); // getting command from user

	   std::string package_for_print = USER_COMMAND:: ProcessUserCommand (command,object); // process command

       PRINT_OBJECT :: PrintCertainPackage (package_for_print, object);
    }

}
