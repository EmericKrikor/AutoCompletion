/*
** EPITECH PROJECT, 2021
** 
** File description:
** 
*/

#ifndef AUTOCOMP_AUTOCOMP_HPP
#define AUTOCOMP_AUTOCOMP_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#include <functional>
#include <set>
#include <string.h>
#include <sstream>
#include <regex>
#include <algorithm>

#define valid "^([\\w\\s]*), ([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define first "^([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+), ([\\w\\s]*)$"
#define no "^([\\w\\s]*), (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define rev "^([\\w\\s]*), ([\\d]+) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square)$"
#define coma "^([\\w\\s]*) ([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define nothing "^([\\w\\s]*) ([\\d]+) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square)$"
#define before "^(allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+) ([\\w\\s]*), ([\\d]+)$"
#define tp "(allée|avenue|boulevard|chemin|impasse|place|quai|rue|square)"

class adr {
    public:
        adr();
        ~adr();
        int parse_address(char *);

    private:
};

std::string toLower(std::string);
void print_vector(std::vector<std::string>);
void debug(int num);
int auto_loop(std::vector<std::string>, std::vector<std::string>);
int select_city(std::vector<std::string>, std::vector<std::string>);
int print_city(std::vector<std::string>);
int only_one(std::vector<std::string>, std::vector<std::string>, std::string);
std::vector<std::string> city_to_look_for(std::vector<std::string>, std::string);
int valid_letter(std::string, std::vector<std::string>, int);
int find_possible(std::vector<std::string> &, std::string &);
std::string toUpper(std::string);
std::string correct(std::string);
bool exist(std::vector<std::string>, std::string);
std::vector<std::string> sort_vec(std::vector<std::string>);
int find_street(std::vector<std::string>, std::string);
std::vector<std::string> select(std::vector<std::string>);
std::vector<std::string> sort_new_city(std::string, std::vector<std::string>);

#endif //AUTOCOMP_AUTOCOMP_HPP
