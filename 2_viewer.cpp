#include "stdafx.h"

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "1_model.h"
#include "2_viewer.h"

// sort package before printing
void PRINT_OBJECT :: SortPackage (OBJECT& object)
{
	// vector for temprory store name which changed
	std::vector <std::string> name_package_were_changed{};

    // change space to slash for sorted
	for (size_t i = 0; i < object.VectorPointers.size(); i++)
    {
        if (object.VectorPointers[i]->find("/") == object.VectorPointers[i]->npos) // if path not include slash
        {		
			if (object.VectorPointers[i]->find(" ") != object.VectorPointers[i]->npos) // looking for space
			{
				// and change from space to slash
				object.VectorPointers[i]->replace(object.VectorPointers[i]->find(" "), const_one_symbol, "/");

				// add to temp storage
				name_package_were_changed.push_back(object.VectorPointers[i]->data());
			}
        }
    }

    // sorted
    std::sort(object.VectorPointers.begin(), object.VectorPointers.end(), PREDICATE());

	// return first conditional of name which changed
	for (size_t i = 0; i < object.VectorPointers.size(); i++)
	{
		for (size_t j = 0; j < name_package_were_changed.size(); j++)
		{
			std::string left_string = object.VectorPointers[i]->data();
			std::string right_string = name_package_were_changed[j].data();

			if (left_string == right_string)
				object.VectorPointers[i]->replace(object.VectorPointers[i]->find("/"), const_one_symbol, " ");
		}
	}
}

void PRINT_OBJECT :: PrintRootPackage (OBJECT& object)
{
	for (auto& index : object.VectorPointers)
			std::cout << index->data() << std::endl;

	std::cout << "" << std::endl; system("pause"); std::cout << "" << std::endl;
}

void PRINT_OBJECT :: PrintCertainPackage (std::string certain_package_for_print, OBJECT& object)
{
    if (certain_package_for_print == "") return; 

    // if vector empty - return;
	if (object.VectorPointers.empty() == true)
		{ std::cout << "root_package_not_exist" << std::endl; return; }

	// sort vector
    PRINT_OBJECT::SortPackage(object);

	if (certain_package_for_print == "root_package")
	{
		PrintRootPackage(object); return;
	}

	// print included package
    for (auto& index: object.VectorPointers)
    {
		std::string name_package = index->data();
        // if package for print exist - print it
		if (name_package.find(certain_package_for_print) != certain_package_for_print.npos)
			std::cout << name_package << std::endl;
    }

	// change space to slash
	if (certain_package_for_print.find(" ") != certain_package_for_print.npos) 
		certain_package_for_print.replace(certain_package_for_print.find(" "), const_one_symbol, "/"); 

	for (auto& index : object.VectorPointers)
	{
		std::string name_package = index->data();
		// if package for print exist - print it
		if (name_package.find(certain_package_for_print) != certain_package_for_print.npos)
			std::cout << name_package << std::endl;
	}
	std::cout << "" << std::endl; system ("pause"); std::cout << "" << std::endl;
}
