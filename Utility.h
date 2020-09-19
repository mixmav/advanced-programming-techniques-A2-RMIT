#include "string"
#include "Types.h"
#include "vector"

// Prints the given text using an optional formatting flag as defined in Types.h
void prettyPrint(std::string input, PrettyPrint::Value flag = PrettyPrint::NONE);

// Prints a list of string values in a vector in a numbered format
void prettyPrintList(std::vector<std::string> listItems);