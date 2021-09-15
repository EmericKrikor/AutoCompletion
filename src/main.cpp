/*
** EPITECH PROJECT, 2021
** Autocompletion
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "../includes/autocompletion.hpp"

int main(int ac, char **argv)
{
    int exitstatus = 0;
    std::vector<std::string> cities;
    std::vector<std::string> streetnames;
    std::vector<int> streetnumber;

    if (strcmp(argv[1], "-h") == 0)
        exitstatus = helpmsg();
    else
        exitstatus = parsefile(argv[1], &cities, &streetnames);
    return exitstatus;
}