/*
** EPITECH PROJECT, 2021
** autocompletion
** File description:
** autocompletion
*/


#include "../includes/autocompletion.hpp"

std::string chekcchoice(std::vector<std::string> *cities,
std::vector<std::string> *streetnames, std::string inputString, algo choice)
{
    switch (choice)
    {
        case first :
            checkcities(cities, inputString);
            break;
        case street :
            checkstreet();
            break;
        case address_name :
            checkaddress_name();
    }
    return "{m} {l} {p} {s} {d}";
}

int loop_completion(std::vector<std::string> *cities, std::vector<std::string> *streetnames)
{
    bool finished = false;
    std::string inputString;
    algo choice = first;
    std::string tabselections = "{m} {l} {p} {s} {d}";

    do {
        std::cout << tabselections << std::endl;
        getline(std::cin, inputString);
        if (inputString == "ABORT")
            return 0;
        toLower(inputString);
        tabselections = chekcchoice(cities, streetnames, inputString, choice);
    } while (finished == false);
    return 0;
}

int parsefile(char *filepath, std::vector<std::string> *cities, std::vector<std::string> *streetnames)
{
    std::string line;
    std::ifstream dictionary(filepath);
    std::regex address_type(valid_adresss);
    std::regex error1_address(error_case1);
    std::regex error2_address(error_case2);
    std::regex error3_address(error_case3);
    std::regex error4_address(error_case4);
    std::smatch match;

    if (dictionary.is_open()) {
        while (getline(dictionary, line)) {
            if (regex_search(line, match, address_type)) {
                cities->push_back(match[1].str());
                streetnames->push_back(match[4].str());
                //atoi(match[2].str().c_str());
            } else if (regex_search(line, match, error1_address))
                std::cout << line << std::endl;
            else if (regex_search(line, match, error2_address))
                std::cout << line << std::endl;
            else if (regex_search(line, match, error3_address))
                std::cout << line << std::endl;
            else if (regex_search(line, match, error4_address))
                std::cout << line << std::endl;
        }
    } else {
        std::cout << "Invalid argument" << std::endl;
        return 84;
    }

    std::cout << cities[0] << streetnames[0] << std::endl;
    return loop_completion(cities, streetnames);
}