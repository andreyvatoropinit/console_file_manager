#include "stdafx.h"

#include <iostream>
#include <memory>
#include <vector>
#include "0_controller.h"
#include "1_model.h"
#include "2_viewer.h"
#include "4_unit_test.h"

void UNIT_TEST::TestFunction ()
{ 
   UNIT_TEST::TestSerialization ();

   UNIT_TEST::TestController ();

   UNIT_TEST::TestModel ();

   UNIT_TEST::TestViewer ();

   UNIT_TEST::PrintCertainPackage ();
}

void UNIT_TEST::PrintCertainPackage ()
{
    OBJECT object {};     std::string command{};

    command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2 package_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2 package_2_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2/package_2_2 package_2_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2/package_2_2 package_2_2_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_1 package_1_1_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_2 package_1_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_1 package_1_1_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    std::string certain_package_for_print = "print root_package/package_1 package_1_1";
	command = USER_COMMAND:: ProcessUserCommand (certain_package_for_print,object);
	PRINT_OBJECT::PrintCertainPackage(command, object); 

    certain_package_for_print = "print root_package package_2";
	command = USER_COMMAND:: ProcessUserCommand (certain_package_for_print,object);
	PRINT_OBJECT::PrintCertainPackage(command, object); 

    certain_package_for_print = "print root_package";
	command = USER_COMMAND:: ProcessUserCommand (certain_package_for_print,object);
	PRINT_OBJECT::PrintCertainPackage(command, object); 
}

void UNIT_TEST::TestViewer ()
{
    OBJECT object {};     std::string command{};

    command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2 package_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2 package_2_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2/package_2_2 package_2_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_2/package_2_2 package_2_2_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_1 package_1_1_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_2 package_1_2_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_1 package_1_1_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_2");
	USER_COMMAND:: ProcessUserCommand (command,object);

    PRINT_OBJECT :: PrintCertainPackage("root_package", object); // view database
}

void UNIT_TEST::TestSerialization ()
{
    OBJECT object {};

	std::string command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("test_serialization");
	USER_COMMAND:: ProcessUserCommand (command,object);
}

void UNIT_TEST::TestController ()
{
	std::string command{};

	command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
    if (command != "create root_package")           { std::cout << "Error 0" << std::endl; while (true);}

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
    if (command != "add root_package package_1")    { std::cout << "Error 1" << std::endl; while (true);}

	command = INPUT_USER_COMMAND::InputUserCommand ("add root_package//as df asdf"); // two slash
	if (command != "error")							{ std::cout << "Error 2 two slash" << std::endl; while (true); }

	command = INPUT_USER_COMMAND::InputUserCommand ("create !"); //  not permitted symbol
	if (command != "error")							{ std::cout << "Error 3 not permitted symbol" << std::endl; while (true); }

    command = INPUT_USER_COMMAND::InputUserCommand ("create root_pac kage package_1"); // free space
    if (command != "error")                         { std::cout << "Error two space" << std::endl; while (true);}

	command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1/package_1_1/package_1_1_1"); // name without space
	if (command != "error")							{ std::cout << "Error 4. Incorrect path" << std::endl; while (true); }

	command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_1/package_1_1_1"); // name with slash
	if (command != "error")							{ std::cout << "Error 5. Slash in name package" << std::endl; while (true); }

}

void UNIT_TEST::TestModel ()
{
    UNIT_TEST::TestAddDeleteRootPackage ();
    UNIT_TEST::TestAddDeletePackageWithOutSubPackage ();
    UNIT_TEST::TestAddDeletePackageWithSubPackage ();
    UNIT_TEST::TestAddDeletePackageWithLongPath ();
}

void UNIT_TEST::TestAddDeletePackageWithLongPath ()
{
    OBJECT object {};     std::string command{};

    command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command, object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1/package_1_1"
                                                    "/package_1_1_1 package_1_1_1_1");
	USER_COMMAND:: ProcessUserCommand (command, object);

    std::string root_package =  "root_package";
    std::string package_1_1_1 = "root_package/package_1/package_1_1/package_1_1_1 package_1_1_1_1";

    if (object.VectorPointers[zero_element] -> data () == root_package  &&
		object.VectorPointers[first_element]-> data () == package_1_1_1)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_7!" << std::endl;
        while (true);
    }

    command = INPUT_USER_COMMAND::InputUserCommand ("remove root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    if (object.VectorPointers[zero_element]->data() == root_package &&
        object.VectorPointers.size() == size_only_root_package)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_8!" << std::endl;
        while (true);
    }
}

void UNIT_TEST::TestAddDeleteRootPackage ()
{
     OBJECT object {};
	 std::string root_package = "root_package";

	 std::string command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	 USER_COMMAND:: ProcessUserCommand (command,object);

     if (object.VectorPointers[zero_element]->data() == root_package)
     {
         std::cout << "Test passed." << std::endl;
     }
     else
     {
         std::cout << "Test failed_1!" << std::endl;
         while (true);
     }

     command = INPUT_USER_COMMAND::InputUserCommand ("remove root_package");
	 USER_COMMAND:: ProcessUserCommand (command,object);

     if (object.VectorPointers.empty() == true)
     {
       std::cout << "Test passed." << std::endl;
     }
     else
     {
         std::cout << "Test failed_2!;" << std::endl;
         while (true);
     }
}

void UNIT_TEST::TestAddDeletePackageWithOutSubPackage ()
{
    OBJECT object {};

	std::string command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

	std::string root_package = "root_package";
	std::string package_1 = "root_package package_1";

    if (object.VectorPointers[zero_element] -> data () == root_package &&
		object.VectorPointers[first_element]-> data () == package_1)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_3!;" << std::endl;
        while (true);
    }

    command = INPUT_USER_COMMAND::InputUserCommand ("remove root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    if (object.VectorPointers[zero_element]->data () == root_package &&
        object.VectorPointers.size() == size_only_root_package)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_4!" << std::endl;
        while (true);
    }
}

void UNIT_TEST::TestAddDeletePackageWithSubPackage ()
{
    OBJECT object {};     std::string command;

    command = INPUT_USER_COMMAND::InputUserCommand ("create root_package");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    command = INPUT_USER_COMMAND::InputUserCommand ("add root_package/package_1 package_1_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

	std::string root_package = "root_package";
	std::string package_1 =    "root_package package_1";
	std::string package_1_1 =  "root_package/package_1 package_1_1";

    if (object.VectorPointers[zero_element]  -> data ()  == root_package  &&
		object.VectorPointers[first_element] -> data ()  == package_1     &&
		object.VectorPointers[second_element]-> data ()  == package_1_1)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_5!" << std::endl;
        while (true);
    }

    command = INPUT_USER_COMMAND::InputUserCommand ("remove root_package package_1");
	USER_COMMAND:: ProcessUserCommand (command,object);

    if (object.VectorPointers[zero_element]->data() == root_package &&
         object.VectorPointers.size() == size_only_root_package)
    {
        std::cout << "Test passed." << std::endl;
    }
    else
    {
        std::cout << "Test failed_6!" << std::endl;
        while (true);
    }
}
