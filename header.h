#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <regex>

using std::cout;
using std::endl;
using std::string;

#define filename "data.txt"

string wordFix (string);
bool fileExists (const string);
void printWords (std::map<string, std::pair< std::set<int>, int >>);
void printLinks (std::set<string>);

#endif