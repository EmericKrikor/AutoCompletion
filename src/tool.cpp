/*
** EPITECH PROJECT, 2021
** autocomp
** File description:
** tool
*/

#include "autocomp.hpp"

std::string toLower(std::string str)
{
    std::string newstr(str);
    std::transform(newstr.begin(), newstr.end(), newstr.begin(), ::tolower);
    return newstr;
}

std::string toUpper(std::string str)
{
    std::string newstr(str);
    std::transform(newstr.begin(), newstr.end(), newstr.begin(), ::toupper);
    return newstr;
}

void print_vector(std::vector<std::string> list)
{
    for (long unsigned int i = 0; i < list.size(); i++)
        std::cout << list[i] << std::endl;
}

void debug(int num)
{
    std::cout << num << std::endl;
}