#ifndef UNIT_TEST_H
#define UNIT_TEST_H

class UNIT_TEST
{
    public:

    static void TestFunction ();

    static void TestController ();

    static void TestModel ();

    static void TestAddDeleteRootPackage ();

    static void TestAddDeletePackageWithOutSubPackage ();

    static void TestAddDeletePackageWithSubPackage ();

    static void TestSerialization ();

    static void TestAddDeletePackageWithLongPath();

    static void TestViewer ();

    static void PrintCertainPackage ();
};

// number elements packages in vector
enum ELEMENTS
{
  zero_element,
  first_element,
  second_element
};

// size vector of packages when we have only one root_package in vector
const int size_only_root_package = 1;

#endif // UNIT_TEST_H
