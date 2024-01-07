#ifndef UTIL_STRINGS_H
#define UTIL_STRINGS_H

#include <string>
#include <string_view>
#include <vector>

using namespace std;

namespace ev {
vector<string> split(const string &toSplit, const string &delimiter);

vector<string> split(const string &toSplit, const string &delimiter, const unsigned &limit);
} // namespace ev

#endif
