/*
** EPITECH PROJECT, 2021
** B-SYN-400-PAR-4-1-autoCompletion-emeric.keskin
** File description:
** sort
*/

#include "autocomp.hpp"

std::vector<std::string> sort_vec(std::vector<std::string> city)
{
    std::string occurances;
    std::string newoc;
    std::vector<std::string> newtab;
    int max = 0;
    char res;

    for (unsigned long int i = 0; i < city.size(); i++)
        occurances += city[i][0];
    std::sort(occurances.begin(), occurances.end());
    while (newtab.size() != city.size()) {
        for(unsigned long int i = 0; i < occurances.size(); i++) {
            int count = 0;
            for(unsigned long int j = 0; j < occurances.size(); j++) {
                if(occurances[j] == occurances[i])
                    count++;
            }
            if(count >  max) {
                max = count;
                res = occurances[i];
            }
        }
        for (unsigned long int i = 0; i < city.size(); i++) {
            if (city[i][0] == res)
                newtab.push_back(city[i]);
            }
        for (unsigned long int z = 0; z < occurances.size(); z++) {
            if (occurances[z] != res)
                newoc += occurances[z];
        }
        occurances = "";
        occurances = newoc;
        newoc = "";
        max = 0;
    }
    return newtab;
}