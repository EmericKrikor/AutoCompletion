/*
** EPITECH PROJECT, 2021
** autocompletion
** File description:
** check
*/

#include "../includes/autocompletion.hpp"

void checkcities(std::vector<std::string> *cities, std::string inputString)
{
    std::string test;
    std::size_t found;
    std::string str3;

    if (inputString.length() == 1 && inputString != "d")
        inputString = toUpper(inputString);
    for(unsigned int i = 0; i < cities->size(); i++)
    {
        if (cities->at(i).find(inputString) != std::string::npos)
            if (inputString.length() != 1)
                std::cout << cities->at(i).substr(0, inputString.length()) << std::endl;
            else
                std::cout << cities->at(i).substr(0, (inputString.length() + 1)) << std::endl;
    }
}

void checkstreet(){}

void checkaddress_name(){};