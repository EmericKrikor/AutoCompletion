/*
** EPITECH PROJECT, 2021
** B-SYN-400-PAR-4-1-autoCompletion-emeric.keskin
** File description:
** correct
*/

#include "autocomp.hpp"

std::string switch_ad(std::string line)
{
    std::string tmp;
    std::string new_line;
    long unsigned int i = 0;

    for (; i < line.length(); i++) {
        if (line[i] == ',')
            break;
    }
    for (; i > 0; i--) {
        if (line[i] == ' ')
            break;
    }
    for (unsigned int j = 0; j < i; j++)
        tmp += line[j];
    for (i = i + 1; i < line.length(); i++)
        new_line += line[i];
    new_line += ' ';
    new_line += tmp;
    return new_line;
}

std::string rev_add(std::string line)
{
    std::string tmp;
    std::string new_line;
    std::regex type(tp);
    long unsigned int i = 0;
    long unsigned int j = 0;

    for (; i < line.length(); i++) {
        if (line[i] == ' ') {
            if (regex_match(tmp, type))
                break;
            else tmp = "";
        }
        else tmp += line[i];
    }
    i = i - (tmp.size() + 1);
    for (; j < line.length(); j++) {
        if (j > 0) {
            if (std::isdigit(line[j - 1]) && line[j] == ' ')
                break;
        }
        new_line += line[j];
    }
    new_line += ' ';
    new_line += tmp;
    for (; j < i; j++)
        new_line += line[j];
    return new_line;
}

std::string miss_coma(std::string line)
{
    std::string tmp;
    unsigned long int i = 0;

    for (; i < line.length(); i++) {
        if (std::isdigit(line[i]))
            break;
    }
    for (unsigned long int j = 0; j < i - 1; j++)
        tmp += line[j];
    tmp += ", ";
    for (; i < line.size(); i++)
        tmp += line[i];
    return tmp;
}

std::string place_number(std::string line, unsigned long int digit)
{
    std::string tmp;
    std::string new_line;

    for (unsigned long int i = digit; isdigit(line[i]); i++)
        tmp += line[i];
    for (unsigned long int i = 0; i != digit - 1; i++) {
        if (line[i] == ',') {
            new_line += ", ";
            new_line += tmp;
        }
        else new_line += line[i];
    }
    for (; isdigit(line[digit]); digit++);
    for (; digit < line.size(); digit++)
        new_line += line[digit];
    return new_line;
}

std::string correct(std::string line)
{
    std::string tmp;
    std::vector<std::string> tab;
    std::regex valid_adresse(valid);
    std::regex no_coma(coma);
    std::regex first_num(first);
    std::regex no_num(no);
    std::regex reverse(rev);
    std::regex no_coma_reverse(nothing);
    std::regex adress_before(before);

    if (std::regex_match(line, valid_adresse) == 1)
        return line;
    else if (std::regex_match(line, adress_before) == 1)
        line = switch_ad(line);
    else if (std::regex_match(line, no_coma_reverse) == 1)
        line = miss_coma(rev_add(line));
    else if (std::regex_match(line, no_coma) == 1)
        line = miss_coma(line);
    else if (std::regex_match(line, reverse) == 1)
        line = rev_add(line);
    for (unsigned long int i = 2; i < line.size(); i++) {
        if (isdigit(line[i]) && !isdigit(line[i - 1])) {
            if (line[i - 2] != ',' || line [i - 1] != ' ')
                line = place_number(line, i);
        }
    }
    return line;
}