#ifndef EV_UTIL_STRINGS_H
#define EV_UTIL_STRINGS_H

#include <vector>
#include <string>
#include <string_view>

using namespace std;

namespace ev {
  vector<string> split(const string& toSplit, const string& delimiter);
}

#endif
