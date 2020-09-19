#include "iostream"
#include "Utility.h"

void prettyPrint(std::string input, PrettyPrint::Value flag){
    int borderLength = input.length();

    std::string border = "";

    for (int i = 0; i < borderLength; i++)
    {
        border.append("-");
    }

    if (flag == PrettyPrint::OVERLINE || flag == PrettyPrint::BOTH) {
        std::cout << border << std::endl;
    }

    std::cout << input << std::endl;
    
    if (flag == PrettyPrint::UNDERLINE || flag == PrettyPrint::BOTH) {
        std::cout << border << std::endl;
    }

    std::cout << std::endl;

}

void prettyPrintList(std::vector<std::string> listItems){
    for (unsigned int i = 1; i < listItems.size() + 1; i++)
    {
        std::cout << i << ". " << listItems.at(i - 1) << std::endl;
    }

    std::cout << std::endl;
}