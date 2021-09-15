/*
** EPITECH PROJECT, 2021
** B-SYN-400-PAR-4-1-autoCompletion-emeric.keskin
** File description:
** selecter
*/

#include "autocomp.hpp"

int valid_letter(std::string line, std::vector<std::string> city, int start_at)
{
    for (unsigned long int i = 0; i < city.size(); i++) {
        if (city[i][start_at] == line[0])
            return 1;
    }
    return 0;
}

int only_one(std::vector<std::string> newlist, std::vector<std::string> tab, std::string line)
{
    std::vector<std::string> newtab;
    int possibility = 0;
    int pos = 0;
    (void)line;

    if (newlist.size() > 1)
        return 1;
    for (unsigned int i = 0; i < tab.size(); i++)
        newtab.push_back(toLower(tab[i]));
    for (unsigned long int i = 0; i < newtab.size(); i++) {
        if (newtab[i].find(newlist[0]) == 0) {
            possibility++;
            pos = i;
        }
    }
    if (possibility == 1) {
        std::cout << "=> " << tab[pos] << std::endl;
        return 0;
    }
    return 1;
}

std::vector<std::string> city_to_look_for(std::vector<std::string> city, std::string line)
{
    std::vector<std::string> newlist;
    std::vector<std::string> final;
    unsigned long int dif = 0;
    int end = 0;
    std::string tmp;
    unsigned long int x = 0;

    if (city.size() > 1) {
        for (; end == 0; x++) {
            if (x < city[0].size()){
                tmp = city[0][x];
            }
            for (unsigned long int i = 1; i < city.size(); i++) {
                if (city[i][x] != tmp[0]) {
                    dif = x;
                    end = 1;
                }
            }
        }
    }
    for (unsigned long int i = 0; i < city.size(); i++) {
        if(city[i].find(line) == dif)
            newlist.push_back(city[i]);
    }
    for (unsigned long int i = 0; i < newlist.size(); i++) {
        if (exist(final, newlist[i]) == true)
            final.push_back(newlist[i]);
    }
    return final;
}

int print_city(std::vector<std::string> city)
{
    int dif = 0;
    std::vector<std::string> toprint;
    std::string parsed;
    std::string tmp;
    unsigned long int x = 0;
    int z = 0;
    int end = 0;

    if (city.size() > 1) {
        for (; end == 0; x++) {
            if (x < city[0].size()){
                tmp = city[0][x];
            }
            for (unsigned long int i = 1; i < city.size(); i++) {
                if (city[i][x] != tmp[0]) {
                    dif = x;
                    end = 1;
                }
            }
        }
    }
    for (unsigned long int i = 0; i < city.size(); i++) {
        tmp = toUpper(city[i]);
        parsed += "{";
        for (z = 0; z < dif; z++) {
            parsed += tmp[z];
        }
        tmp = toLower(city[i]);
        parsed += tmp[z];
        parsed += "}";
        if (exist(toprint, parsed) == true)
            toprint.push_back(parsed);
        parsed = "";
    }
    std::cout << toprint[0];
    for (unsigned long int i = 1; i < toprint.size() && i < 5; i++)
        std::cout << " " << toprint[i];
    std::cout << std::endl;
    return dif;
}

std::vector<std::string> sort_new_city(std::string line, std::vector<std::string> city)
{
    std::vector<std::string> newcity;

    for (unsigned long int i = 0; i < city.size(); i++) {
        if (city[i].find(line) == 0)
            newcity.push_back(city[i]);
    }
    return newcity;
}

int select_city(std::vector<std::string> city, std::vector<std::string> tab)
{
    std::string line;
    std::string n;
    std::vector<std::string> lower;
    std::vector<std::string> newchoice;
    int one = 0;
    long unsigned int end = 0;
    long unsigned int start = 0;
    int j = 0;
    int choice = 0;

    if (find_possible(city, n) != 1) {
        getline(std::cin, line);
        line = toLower(line);
        if (line.compare("abort") == 0)
            return 0;
        if (line.size() != 1) {
            std::cerr << "Unknown address" << std::endl;
            return 84;
        }
        n += line;
        for (unsigned long int i = 0; i < city.size(); i++) {
            if (city[i].find(n) == 0)
                j++;
        }
        if (j == 0) {
            std::cerr << "Unknown address" << std::endl;
            return 84;
        }
        city = sort_new_city(n, city);
        return select_city(city, tab);
    }
    else {
        for(unsigned long int i = 0; i < tab.size(); i++)
            lower.push_back(toLower(tab[i]));
        for(unsigned long int i = 0; i < lower.size(); i++) {
            if (lower[i].find(city[0]) < lower[i].find(',')) {
                newchoice.push_back(tab[i]);
            }
        }
        long int num = 0;
        long int where = 0;
        if (city.size() == 1) {
            for (unsigned long int i = 0; tab.size() > i; i++) {
                if (lower[i].find(city[0]) < lower[i].size()) {
                    num++;
                    where = i;
                }
            }
        }
        if (num == 1) {
            std::cout << "=> " << tab[where] << std::endl;
            return 0;
        }
        lower.clear();
        for(unsigned long int i = 0; i < newchoice.size(); i++)
            lower.push_back(toLower(newchoice[i]));
        for (unsigned long int i = 0; i < lower.size(); i++) {
            j = lower[i].find(',');
            for (int w = 0; w < j; w++) {
                if (lower[i][w] == ' ')
                    choice++;
            }
        }
        for (unsigned long int i = 0; lower[0][i] != ','; i++) {
            if (lower[0][i] == ' ')
                one++;
        }
        if (choice > 0 && one > 0) {
            for (unsigned long int i = 0; i < lower.size(); i++) {
                start = lower[i].find(city[0]);
                if (i == 0)
                    std::cout << "{";
                else std::cout << " {";
                std::cout << i + 1;
                std::cout << " : ";
                for (long unsigned int x = 0; x < lower[i].size(); x++) {
                    end = lower[i].find(',');
                    if (x == start) {
                        for(;lower[i][x] != ' ' && lower[i][x] != ','; x++) {
                            lower[i] = toUpper(lower[i]);
                            std::cout << lower[i][x];
                        }
                        if (lower[i][x] != ',')
                            std::cout << " ";
                        lower[i] = toLower(lower[i]);
                    }
                    else if (x < end) {
                        std::cout << lower[i][x];
                    }
                }
                std::cout << "}";
            }
            std::cout << std::endl;
            getline(std::cin, line);
            if (line.compare("abort") == 0)
                return 0;
            if (line.size() != 1) {
                std::cerr << "Unknown address" << std::endl;
                return 84;
            }
            if (isdigit(line[0]) == true) {
                unsigned long int wichone = line[0] - 49;
                if (wichone >= newchoice.size()) {
                    std::cerr << "Unknown address" << std::endl;
                    return 84;
                }
                std::cout << "=> " << newchoice[wichone] << std::endl;
                return 0;
            }
            else {
                std::cout << "Unknown address" << std::endl;
                return 84;
            }
        }
        return find_street(tab, city[0]);
    }
    return 0;
}