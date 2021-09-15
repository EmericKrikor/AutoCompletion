/*
** EPITECH PROJECT, 2021
** autocomp
** File description:
** main
*/

#include <iostream>
#include "autocomp.hpp"

int main(int ac, char **av)
{
    int exit_status = 0;
    adr *oto = 0;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        std::cout << "USAGE\n\t./autoCompletion dictionary\n\nDESCRIPTION\n"
            "\tdictionary\tfile containing one address per line, as knowledge base" << std::endl;
        return 0;
    }
    if (ac == 2)
        exit_status = oto->parse_address(av[1]);
    else {
        std::cout << "Invalid argument" << std::endl;
        return 84;
    }
    return exit_status;
}
