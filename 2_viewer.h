#ifndef PRINT_OBJECT_H
#define PRINT_OBJECT_H

class PRINT_OBJECT
{
    public:

    static void PrintCertainPackage (std::string, OBJECT&);

    static void SortPackage         (OBJECT&);

	static void PrintRootPackage(OBJECT&);
};

class PREDICATE
{
    public:

    // operator for compare name of package
    bool operator() (const std :: unique_ptr <std :: string> & left_pointer,
		             const std :: unique_ptr <std :: string> & right_pointer)
    {
		std::string left_string = left_pointer->data();
		std::string right_string = right_pointer->data();

        // left string bigger than right
        if (left_string > right_string)
            return false;
        else
            return true;
    }
};

const int const_one_symbol = 1;

#endif // PRINT_OBJECT_H
