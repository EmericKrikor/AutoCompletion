/*
** EPITECH PROJECT, 2021
** autocompletion
** File description:
** tools
*/

#include "../includes/autocompletion.hpp"

std::string toLower(std::string str)
{
    std::string newstr(str);
    std::transform(newstr.begin(), newstr.end(), newstr.begin(), ::tolower);
    return newstr;
}


std::string toUpper(std::string str)
{
    std::string newstr(str);
    std::transform(newstr.begin(), newstr.end(),newstr.begin(), ::toupper);
    return newstr;
}