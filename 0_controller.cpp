#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include "0_controller.h"

std::string INPUT_USER_COMMAND :: InputUserCommand (std::string input_command_for_auto_test)
{
    std::string command{};

    if (input_command_for_auto_test == "") // work mode
    {
		int static counter_command{}; counter_command++;
		// if count command in console more - clean console
		if (counter_command >= const_count_command_in_one_console)
		{
			counter_command = 0;  system("pause"); system("cls");
		}

        std::cout << "Please write command: " << std::endl;

		// try read command from user
		try
		{
			std::getline(std::cin, command);
		}
		catch (...)
		{
			std::cout << "input error" << std::endl;
		}

    }
    else // unit test mode
        command = input_command_for_auto_test;

    // if error  true
    if (INPUT_USER_COMMAND :: CheckErrorInCommandExist (command) == true)
    {
		std::cout << "error command" << std::endl;
        return command = "error";
    }
    else 
        return command;
}

bool INPUT_USER_COMMAND :: CheckErrorInCommandExist(std::string input_command)
{
	// if command from user correspond exactly template command - return false. no error
	if (INPUT_USER_COMMAND :: CheckExactMatch (input_command) == true)     return false;

	// check unpermitted symbol. if unpermitted symbol in command exist return true - mistake exist 
	if (INPUT_USER_COMMAND :: CheckSpecialSymbol(input_command) == true)     return true;

	// if command from user correspond partial template command - check next:
	if (INPUT_USER_COMMAND :: PartialMatch (input_command) == true)
	{
		// if count space in command not equal 2 - return error
		if (INPUT_USER_COMMAND :: CheckCountSpace     (input_command) == true) return true;

		// if path included mistake - return error
		if (INPUT_USER_COMMAND :: CheckPathForMistake (input_command) == true) return true;

		// if mistake not exist return false - no mistake in command
		return false;
	}
	// if command from user not correspond exactly or partial template return error
	else
	{
		return true;
	}
}

bool INPUT_USER_COMMAND :: CheckExactMatch       (std::string input_command)
{
	if (input_command == "create root_package" || input_command == "remove root_package" ||
		input_command == "ser_to_file"         || input_command == "ser_from_file"       ||
		input_command == "test_serialization"  || input_command == "print root_package")
	{
		return true;
	}

	return false;
}

bool INPUT_USER_COMMAND :: PartialMatch          (std::string input_command)
{
	if (input_command.find ("remove root_package") != input_command.npos ||
		input_command.find ("add root_package")    != input_command.npos ||
		input_command.find ("print root_package")  != input_command.npos)
	{
		return true; 
	}

	return false;
}

bool INPUT_USER_COMMAND :: CheckSpecialSymbol    (std::string input_command)
{
    // check double space
    if (input_command.find("  ") != input_command.npos)
    {
		std::cout << "You can not use more than one space" << std::endl;
        return true;
    }
    // check double slash
    if (input_command.find("//") != input_command.npos)
    {
		std::cout << "You can not use more than one slash" << std::endl;
        return true;
    }
	// check slash and space
	if (input_command.find("/ ") != input_command.npos || input_command.find(" /") != input_command.npos)
	{
		std::cout << "You can not use slash and space together" << std::endl;
		return true;
	}

    // check unpermitted symbol
    for (auto index : input_command)
    {
		// if unpermitted symbol exist --- error
       if (permitted_symbol.find(index) == input_command.npos)
       {
		   std::cout << "Not permitted symbol" << std::endl;
           return true;
       }
    }

    return false;
}

bool INPUT_USER_COMMAND :: CheckCountSpace       (std::string input_command)
{
	int count_space_in_command{};

	// calculate count space in command
	for (auto index : input_command)
	{
		if (index == ' ')
		{
			count_space_in_command++;
		}
	}

	// command can have only free part which separate by space
	if (count_space_in_command > const_permitted_count_space_in_command)
	{
		std::cout << "Error. You should to use only two space in command" << std::endl;
		return true;
	}
	else
		return false;
}

bool INPUT_USER_COMMAND :: CheckPathForMistake   (std::string input_command) // true error
{
	std::string delimiter_space = " ";

	size_t pos{};

	// erase all except only name package for add
	while ((pos = input_command.find(delimiter_space)) != std::string::npos)
	{
		input_command.erase(0, pos + delimiter_space.length());
	}

	// if path have slash. path should to have space
	if (input_command.find(" ") == std::string::npos &&
		input_command.find("/") != std::string::npos)
	{
		std::cout << "Error. Path for add should have space" << std::endl;
		return true;
	}

	return false;
}

