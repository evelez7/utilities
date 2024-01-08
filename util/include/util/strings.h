#ifndef UTIL_STRINGS_H
#define UTIL_STRINGS_H

#include <string>
#include <vector>

using namespace std;

namespace ev {
vector<string> split(const string &toSplit, const string &delimiter);

vector<string> split(const string &toSplit, const string &delimiter, const unsigned &limit);

string trim(string &target, const string &toFind, const unsigned &limit = 1);

string replace(string &target, const string &pattern,
               const string &replacement);

string strip(const string &target, const string &pattern);
} // namespace ev

#endif
