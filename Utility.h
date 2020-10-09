#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include "string"
#include "Types.h"
#include "vector"

// Prints the given text using an optional formatting flag as defined in Types.h
void prettyPrint(std::string input, PrettyPrint::Value flag = PrettyPrint::NONE);

// Prints a list of string values in a vector in a numbered format
void prettyPrintList(std::vector<std::string> listItems);

//Prints a promt followed by a new line, followed by a '>' character to let the user know an input's expected
void prettyPrintUIPrompt(std::string input);

// Formats the string with given args (replaces "{n}" with args[n]).
// std::string format(std::string str, void** args);

#endif