#include "stdafx.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "1_model.h"
#include "1_serialization.h"
#include "2_viewer.h"

std::string USER_COMMAND:: ProcessUserCommand (std::string command_from_user, OBJECT& object)
{
  if (command_from_user == "error") return "";

  // separate command to task and path
  std::pair <std::string, std::string> task_and_path = USER_COMMAND:: SeparateStringToPair (command_from_user);

  if (task_and_path.first == "create" && task_and_path.second == "root_package")
  {
    OBJECT :: CreateRootPackage (object); return "";
  }
  else if (task_and_path.first == "add")
  {
    OBJECT :: AddObject (task_and_path.second,object); return "";
  }
  else if (task_and_path.first == "remove")
  {
    OBJECT :: DeletePackage (task_and_path.second,object); return "";
  }
  else if (task_and_path.first == "ser_to_file") 
  {
    SERIALIZATION :: Serialization(object, "ser_to_file"); return "";
  }
  else if (task_and_path.first == "ser_from_file")
  {
	SERIALIZATION :: Serialization(object, "ser_from_file"); return "";
  }
  else if (task_and_path.first == "test_serialization")
  {
    SERIALIZATION :: Serialization(object, "test_serialization"); return "";
  }
  else if (task_and_path.first == "print")
  {
    return task_and_path.second;
  }
  else if (task_and_path.first == "error_command")
  {
    std::cout << "error_command" << std::endl; return "";
  }

  return "";
}

// separate command from user to pair. first part - command. second part path
std::pair <std::string, std::string> USER_COMMAND:: SeparateStringToPair (std::string command_from_user)
{
    std::pair<std::string, std::string> separate_command_from_user{};
    if (command_from_user.find("create ") != command_from_user.npos)
    {
        separate_command_from_user.first = "create";
		command_from_user.erase(search_from_first_symbol, const_count_symbol_in_word_create_with_space);
        separate_command_from_user.second = command_from_user;
    }
    else if (command_from_user.find("add ") != command_from_user.npos)
    {
        separate_command_from_user.first = "add";
		command_from_user.erase(search_from_first_symbol, const_count_symbol_in_word_add_with_space);
        separate_command_from_user.second = command_from_user;
    }
    else if (command_from_user.find("remove ") != command_from_user.npos)
    {
        separate_command_from_user.first = "remove";
		command_from_user.erase(search_from_first_symbol, const_count_symbol_in_word_remove_with_space);
        separate_command_from_user.second = command_from_user;
    }
    else if (command_from_user.find("print ") != command_from_user.npos)
    {
        separate_command_from_user.first = "print";
		command_from_user.erase(search_from_first_symbol, const_count_symbol_in_word_print_with_space);
        separate_command_from_user.second = command_from_user;
    }
    else if (command_from_user.find("test_serialization") != command_from_user.npos)
        separate_command_from_user.first = "test_serialization";

	else if (command_from_user.find("ser_to_file") != command_from_user.npos)
		separate_command_from_user.first = "ser_to_file";

	else if (command_from_user.find("ser_from_file") != command_from_user.npos)
		separate_command_from_user.first = "ser_from_file";

    else separate_command_from_user.first = "error_command";

    return separate_command_from_user;
}

bool OBJECT :: CheckExistRootPackage (OBJECT& object)
{
    // if root_package not exist --- exit
    if (object.VectorPointers.empty() == true)
    {
        std::cout << "Root_package - not exist. Create root_package" << std::endl;
        return false;
    }

    return true;
}

void OBJECT :: CreateRootPackage (OBJECT& object)
{
    // if vector empty add root_package
    if (object.VectorPointers.empty() == true)
    {
        OBJECT ::AddUniquePtrToVector(object, "root_package");
		std::cout << "Root_package created" << std::endl;
    }
    else // or show error
    {
		std::cout << "root_package\" already exist" << std::endl;
    }
}

bool OBJECT :: ParseExistPackage (std::string name_package_for_adding, OBJECT& object)
{
    for (auto& index : object.VectorPointers) 
    {
	   // if name already exist -- error
       if (index->data() == name_package_for_adding)
       {
		  std::cout << "Already exist" << std::endl;
          return true;
       }
    }
    return false;
}

void OBJECT :: AddObject (std::string name_package_for_adding, OBJECT& object)
{
    bool flag_exist_package = CheckExistRootPackage (object);

    // if root package not exist - return;
    if (flag_exist_package == false) return;

	flag_exist_package = OBJECT :: ParseExistPackage (name_package_for_adding, object);

    // if package with this name alredy exist - return
    if (flag_exist_package == true) return;
	
	// add package to vector of pointer
    OBJECT ::AddUniquePtrToVector (object, name_package_for_adding);
}

void OBJECT :: AddUniquePtrToVector(OBJECT& object, std::string name_package_for_adding)
{
    // create unique_ptr and add to vector of unique_ptr
    std::unique_ptr <std::string> unique_pointer(new std::string);

    unique_pointer -> assign (name_package_for_adding);

    object.VectorPointers.push_back (std::move (unique_pointer) );

    std::cout << "Package added" << std::endl;
}

void OBJECT :: DeletePackage (std::string name_for_delete, OBJECT& object)
{
	if (name_for_delete == "root_package")
	{
		if (object.VectorPointers.empty() == true)
		{
			std::cout << "root_package not exist" << std::endl; return;
		}
		else
		{
			object.VectorPointers.clear();
			std::cout << "root_package deleted" << std::endl; return;
		}
	}

    // search package without slash
	for (size_t i = 0; i < object.VectorPointers.size(); i++)
    {
        if (object.VectorPointers[i]->data() == name_for_delete)
        {
			std::cout << object.VectorPointers[i]->data() << " - deleted" << std::endl;
			object.VectorPointers.erase(object.VectorPointers.begin() + i);
        }
    }

	// change space to slash
	if (name_for_delete.find(" ") != name_for_delete.npos) 
		name_for_delete.replace(name_for_delete.find(" "), const_one_symbol, "/");

    // search package with slash
	for (size_t i = 0; i < object.VectorPointers.size(); i++)
	{
		if (object.VectorPointers[i]->find(name_for_delete) != name_for_delete.npos)
		{
			std::cout << object.VectorPointers[i]->data() << " - deleted" << std::endl;
			object.VectorPointers.erase (object.VectorPointers.begin() + i);
		}
	}
}
