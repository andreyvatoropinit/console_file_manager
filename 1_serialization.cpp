#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "1_model.h"
#include "1_serialization.h"


void SERIALIZATION :: Serialization(OBJECT& object, std::string input_command)
{
	if (input_command == "ser_to_file")
	{
		SERIALIZATION :: SerializationToFile(object);
	}
	else if (input_command == "ser_from_file")
	{
		SERIALIZATION :: SerializationFromFile(object);
	}
	else if (input_command == "test_serialization")
	{
		SERIALIZATION :: SerializationUnitTest(object);
	}
}

void SERIALIZATION :: SerializationToFile(OBJECT& object)
{
	// file for write
	std::ofstream fout{};

	try
	{
		fout.open(const_file_name, std::ios_base::out);
	}
	catch (...)
	{
		std::cout << "error open file" << std::endl;
	}


	// add to string every names of packages
	for (auto& index : object.VectorPointers)
	{
		fout << index->data();
		fout << '\n';
	}

	fout.close();

	std::cout << "serialization to file completed" << std::endl;
}

void SERIALIZATION :: SerializationFromFile (OBJECT& object)
{
	// clean all packages
	object.VectorPointers.clear();

	// file fo read
	try
	{
		std::ifstream fin(const_file_name, std::ios_base::in);
		std::string string_from_file{};

		//read all line and put it to packages
		while (getline(fin, string_from_file))
		{
			std::unique_ptr <std::string> unique_pointer(new std::string);
			unique_pointer->assign(string_from_file);
			object.VectorPointers.push_back(std::move(unique_pointer));
		}

		fin.close();
	}
	catch (...)
	{
		std::cout << "Error open file" << std::endl;
	}

	std::cout << "serialization from file completed" << std::endl;
}

void SERIALIZATION :: SerializationUnitTest(OBJECT& object)
{
	std::ofstream fout{};
	fout.open(const_file_name_test, std::ios_base::out);

	// add to string every names of packages
	for (auto& index : object.VectorPointers)
	{
		fout << index->data(); fout << '\n';
	}

	fout.close();

	// file fo read
	std::ifstream fin(const_file_name_test, std::ios_base::in); 
	std::string string_from_file{};
	OBJECT object_read_from_file{};

	//read all line and put it to packages
	while (getline(fin, string_from_file))
	{
		std::unique_ptr <std::string> unique_pointer(new std::string);
		unique_pointer->assign(string_from_file);
		object_read_from_file.VectorPointers.push_back(std::move(unique_pointer));
	}
	fin.close();

	for (size_t i = 0; i < object.VectorPointers.size(); i++)
	{
		std::string left_string = object.VectorPointers[i]->data();
		std::string right_string = object_read_from_file.VectorPointers[i]->data();

		if (left_string != right_string)
		{
			std::cout << "Error serialization!" << std::endl;
			while (true);
		}
	}
	std::cout << "serialization test completed" << std::endl;
}



