#ifndef SERIALIZATION_H
#define SERIALIZATION_H

static const char* const const_file_name = "package_archive.bin";

static const char* const const_file_name_test = "package_archive_test.bin";

class SERIALIZATION
{
    public:

    static void Serialization         (OBJECT&, std::string);

	static void SerializationUnitTest (OBJECT&);

	static void SerializationToFile   (OBJECT&);

	static void SerializationFromFile (OBJECT&);
};

#endif // SERIALIZATION_H
