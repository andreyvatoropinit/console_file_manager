#ifndef PROCESS_USER_COMMAND_H
#define PROCESS_USER_COMMAND_H

class OBJECT
{
    public:

    std::vector < std::unique_ptr< std::string >> VectorPointers;

    static bool CheckExistRootPackage      (OBJECT&);

    static void CreateRootPackage          (OBJECT&);

    static bool ParseExistPackage          (std::string, OBJECT&);

    static void AddObject                  (std::string, OBJECT&);

    static void AddUniquePtrToVector       (OBJECT&, std::string);

    static void DeletePackage              (std::string, OBJECT&);
};

class USER_COMMAND
{
	public:

	static std::string ProcessUserCommand(std::string, OBJECT&);

	static std::pair <std::string, std::string> SeparateStringToPair (std::string);
};

// it means count symbol in word with space. create --- 7
const unsigned int const_count_symbol_in_word_create_with_space = 7;
const unsigned int const_count_symbol_in_word_add_with_space = 4;
const unsigned int const_count_symbol_in_word_remove_with_space = 7;
const unsigned int const_count_symbol_in_word_print_with_space = 6;

const unsigned int search_from_first_symbol = 0;

#endif // PROCESS_USER_COMMAND_H
