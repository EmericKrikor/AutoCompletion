/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#include "autocomp.hpp"

adr::adr()
{
}

int auto_loop(std::vector<std::string> city, std::vector<std::string> tab)
{
    std::string line;
    std::vector<std::string> newlist;
    std::string tofind;
    int start_at = 0;
    std::vector<std::string> sortcity;

    city = sort_vec(city);
    for (unsigned long int i = 0; i < city.size(); i++) {
        if (exist(sortcity, city[i]) == true)
            sortcity.push_back(city[i]);
    }
    if (sortcity.size() == 1) {
        sortcity[0][0] = toupper(sortcity[0][0]);
        return find_street(tab, sortcity[0]);
    }
    start_at = print_city(sortcity);
    getline(std::cin, line);
    line = toLower(line);
    if (line.compare("abort") == 0)
        return 0;
    if (line.size() > 1) {
        std::cerr << "Unknown adress" << std::endl;
        return 84;
    }
    if (valid_letter(line, sortcity, start_at) != 1) {
        std::cerr << "Unknown address" << std::endl;
        return 84;
    }
    newlist = city_to_look_for(sortcity, line);
    if (only_one(newlist, tab, line) == 0)
        return 0;
    return select_city(newlist, tab);
}

int split_tab(std::vector<std::string> tab)
{
    std::vector<std::string> city;
    std::string tmp;

    for (unsigned long int i = 0; i < tab.size(); i++) {
        for (unsigned long int j = 0; tab[i][j] != ','; j++) {
            if (tab[i][j] == ' ') {
                tmp = toLower(tmp);
                city.push_back(tmp);
                tmp = "";
            }
            else tmp += tab[i][j];
        }
        tmp = toLower(tmp);
        city.push_back(tmp);
        tmp = "";
    }
    std::sort(city.begin(), city.end());
    return auto_loop(city, tab);
}

int adr::parse_address(char *file)
{
    std::regex first_num(first);
    std::regex no_num(no);
    std::regex reverse(rev);
    std::smatch string;
    std::string line;
    std::ifstream book(file);
    std::vector<std::string> tab;

    if (book.is_open()) {
        while (getline(book, line)) {
            line = correct(line);
            if (line.find(',') == std::string::npos)
                std::cerr << line << std::endl;
            else if (regex_search(line, string, first_num))
                std::cerr << line << std::endl;
            else if (regex_search(line, string, no_num))
                std::cerr << line << std::endl;
            else if (regex_search(line, string, reverse))
                std::cerr << line << std::endl;
            else tab.push_back(line);
        }
        if (tab.size() == 0) {
            std::cerr << "Unknown adress" << std::endl;
            return 84;
        }
        else if (tab.size() == 1) {
            std::cout << "=> " << tab[0] << std::endl;
            return 0;
        }
    }
    else {
        std::cerr << "Invalid argument" << std::endl;
        return 84;
    }
    return split_tab(tab);
}

adr::~adr(){}
