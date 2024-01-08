#ifndef UTIL_FILES_H
#define UTIL_FILES_H

#include <optional>
#include <string>
#include <vector>

using namespace std;

namespace ev {
optional<vector<string>> parse(const string &filename, const char &delimiter);
}

#endif
