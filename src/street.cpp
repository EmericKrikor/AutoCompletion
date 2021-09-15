/*
** EPITECH PROJECT, 2021
** B-SYN-400-PAR-4-1-autoCompletion-emeric.keskin
** File description:
** street
*/

#include "autocomp.hpp"

int one_city_two_adress(std::vector<std::string> tab, std::string city)
{
    std::vector<std::string> adr;
    std::vector<std::string> street;
    std::string name;
    std::string line;
    unsigned long int num = 0;
    unsigned long int pos = 0;

    for (long unsigned int i = 0; i < tab.size(); i++) {
        if (tab[i].find(city) < tab.size()) {
            for (; tab[i][pos] != ','; pos++);
            for(; isdigit(tab[i][pos]) == true; pos++);
            for (pos = pos + 2; tab[i][pos] != ' '; pos++);
            for (pos = pos + 1; pos < tab[i].size(); pos++)
                name += tab[i][pos];
            street.push_back(name);
            adr.push_back(tab[i]);
            name = "";
            pos = 0;
        }
    }
    for (unsigned long int i = 0; i < street.size(); i++) {
        if (street[i].find(street[0]) < street[i].size())
            num++;
    }
    if (num == street.size()) {
        for (unsigned long int i = 0; i < adr.size(); i++) {
            std::string maj = toUpper(adr[i]);
            if (i != 0)
                std::cout << " ";
            std::cout << "{" << i + 1 << " : ";
            for (unsigned long int j = 0; adr[i][j] != ','; j++)
                std::cout << maj[j];
            for (unsigned int l = adr[i].find(','); l < adr[i].size(); l++)
                std::cout << adr[i][l];
            std::cout << "}";
        }
        std::cout << std::endl;
        getline(std::cin, line);
        line = toLower(line);
        if (line.compare("abort") == 0)
            return 0;
        if (isdigit(line[0]) == true) {
            unsigned long int wichone = line[0] - 49;
            if (wichone >= adr.size()) {
                std::cerr << "Unknown address" << std::endl;
                return 84;
            }
            std::cout << "=> " << adr[wichone] << std::endl;
            return 0;
        }
        else {
            std::cerr << "Unknown address" << std::endl;
            return 84;
        }
    }
    return 2;
}

int print_street(std::vector<std::string> adr, std::string city)
{
    int dif = 0;
    std::vector<std::string> toprint;
    std::string parsed;
    std::string tmp;
    unsigned long int x = 0;
    int z = 0;
    int end = 0;

    if (adr.size() > 1) {
        for (; end == 0; x++) {
            if (x < adr[0].size()){
                tmp = adr[0][x];
            }
            for (unsigned long int i = 1; i < adr.size(); i++) {
                if (adr[i][x] != tmp[0]) {
                    dif = x;
                    end = 1;
                }
            }
        }
    }
    for (unsigned long int i = 0; i < adr.size(); i++) {
        tmp = toUpper(adr[i]);
        parsed += "{";
        parsed += toUpper(city);
        parsed += ", ";
        for (z = 0; z < dif; z++) {
            parsed += tmp[z];
        }
        tmp = toLower(adr[i]);
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

int choose_adr(std::vector<std::string> adr, std::string city, std::vector<std::string> tab)
{
    std::vector<std::string> nad;
    std::vector<std::string> ad;
    std::string line;
    std::string n;
    int dif = 0;
    int exit;

    exit = one_city_two_adress(tab, city);
    if (exit == 0)
        return 0;
    else if (exit == 84)
        return 84;
    for (unsigned long int i = 0; i < adr.size(); ++i)
        adr[i] = toLower(adr[i]);
    adr = sort_vec(adr);
    for (unsigned long int i = 0; i < adr.size(); ++i) {
        if (exist(nad, adr[i]) == true)
            nad.push_back(adr[i]);
    }
    dif = print_street(nad, city);
    getline(std::cin, line);
    line = toLower(line);
    if (line.compare("abort") == 0)
        return 0;
    if (line.size() > 1) {
        std::cerr << "Unknown adress" << std::endl;
        return 84;
    }
    if (valid_letter(line, adr, dif) != 1) {
        std::cerr << "Unknown address" << std::endl;
        return 84;
    }
    ad = city_to_look_for(adr, line);
    if(ad.size() == 1) {
        unsigned int f = 0;
        unsigned int k = 0;
        for (unsigned int i = 0; i < tab.size(); i++) {
            if (tab[i].find(city) < tab[i].size() && toLower(tab[i]).find(ad[0]) < tab[i].size()) {
                f++;
                k = i;
            }
        }
        if (f == 1) {
            std::cout << "=> " << tab[k] << std::endl;
            return 0;
        }
    }
    return 0;
}

int find_street(std::vector<std::string> tab, std::string city)
{
    std::string tmp;
    unsigned long int pos = 0;
    std::vector<std::string> adress;
    std::vector<std::string> cut;

    city[0] = toupper(city[0]);
    for (unsigned long int i = 0; i < tab.size(); ++i) {
        if (tab[i].find(city) < tab[i].size())
            adress.push_back(tab[i]);
    }
    for (unsigned long int i = 0; i < adress.size(); ++i) {
        for (pos = adress[i].find(',') + 2; pos < adress[i].size(); pos++) {
            if (isdigit(adress[i][pos]) == true) {
                for (; isdigit(adress[i][pos]) == true; pos++);
                pos++;
                for (; adress[i][pos] != ' '; pos++);
                pos = pos + 1;
            }
            tmp += adress[i][pos];
        }
        cut.push_back(tmp);
        tmp = "";
    }
    return choose_adr(cut, city, tab);
}