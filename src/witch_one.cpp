/*
** EPITECH PROJECT, 2021
** B-SYN-400-PAR-4-1-autoCompletion-emeric.keskin
** File description:
** witch_one
*/

#include "autocomp.hpp"

bool exist(std::vector<std::string> vec, std::string element)
{
    if (std::find(vec.begin(), vec.end(), element) == vec.end())
        return true;
    return false;
}

std::vector<std::string> select(std::vector<std::string> city)
{
    std::vector<std::string> final_city;

    for (unsigned long int i = 0; i < city.size(); i++) {
        if (i == 0)
            final_city.push_back(city[i]);
        else if (exist(final_city, city[i]) == true)
            final_city.push_back(city[i]);
    }
    return final_city;
}

int find_possible(std::vector<std::string> &city, std::string &gen)
{
    int dif = 0;
    int z = 0;
    std::string tmp;
    std::string parsed;
    std::vector<std::string> final_city;
    std::vector<std::string> toprint;
    unsigned long int x = 0;

    final_city = select(city);
    if (final_city.size() > 1) {
        for (; dif == 0; x++) {
            if (x < city[0].size()){
                tmp = city[0][x];
            }
            for (unsigned long int i = 1; i < final_city.size(); i++) {
                if (final_city[i][x] != tmp[0]) {
                    dif = x;
                }
            }
        }
    }
    for (unsigned long int i = 0; i < final_city.size(); i++) {
        tmp = toUpper(final_city[i]);
        parsed += "{";
        gen = "";
        for (z = 0; z < dif; z++) {
            parsed += tmp[z];
        }
        tmp = toLower(final_city[i]);
        parsed += tmp[z];
        parsed += "}";
        if (exist(toprint, parsed) == true)
            toprint.push_back(parsed);
        for (unsigned long int i = 1; i < parsed.size() - 2; i++)
            gen += tolower(parsed[i]);
        parsed = "";
    }
    city = final_city;
    if (final_city.size() == 1) {
        return 1;
    }
    std::cout << toprint[0];
    for (unsigned long int i = 1; i < toprint.size(); i++)
        std::cout << " " << toprint[i];
    std::cout << std::endl;
    return 0;
}