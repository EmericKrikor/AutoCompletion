/*
** EPITECH PROJECT, 2021
** autocompletion
** File description:
** autocompletion
*/

#ifndef auto_H
#define auto_H

#define hlp_msg "USAGE\n\t./autoCompletion dictionary\n\n\
DESCRIPTION\n\tdictionary\tfile containing one address per line, \
as knowledge base"

#define valid_adresss "^([\\w\\s]*), ([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define error_case1 "^([\\w\\s]*) ([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define error_case2 "^([\\d]+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+), ([\\w\\s]*)$"
#define error_case3 "^([\\w\\s]*), (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+)$"
#define error_case4 "^([\\w\\s]*) ([\\d]+) ([\\w\\s-zàâçéèêëîïôûùüÿñæœ']+) (allée|avenue|boulevard|chemin|impasse|place|quai|rue|square)$"

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

enum algo { 
    first,
    city,
    number,
    street,
    streetnumber,
    address_name
};

/*
*
* Basic functions
*
*/ 

int helpmsg(void);
std::string toLower(std::string str);
std::string toUpper(std::string str);

/*
*
* Parsing elements
*
*/

int parsefile(char *filepath, std::vector<std::string> *cities, std::vector<std::string> *streetnames);
void checkcities(std::vector<std::string> *cities, std::string inputString);
void checkstreet();
void checkaddress_name();

#endif /* !auto_H */
