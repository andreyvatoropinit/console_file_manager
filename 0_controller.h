#ifndef INPUT_USER_COMMAND_H
#define INPUT_USER_COMMAND_H

// class for getting command from user
class INPUT_USER_COMMAND
{
   public:

   static std::string InputUserCommand (std::string);

   static bool CheckErrorInCommandExist (std::string);

   static bool CheckExactMatch(std::string);

   static bool PartialMatch(std::string);

   static bool CheckSpecialSymbol (std::string);

   static bool CheckPathForMistake(std::string);

   static bool CheckCountSpace (std::string);
};

// user can use only permitted symbol
const std::string permitted_symbol = "\"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz/_0123456789 ";

const int const_permitted_count_space_in_command = 2;

const int const_count_command_in_one_console = 7;

#endif // INPUT_USER_COMMAND_H
