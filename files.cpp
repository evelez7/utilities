#include <ranges>
#include <iostream>
#include <iomanip>
#include <string>
#include "files.h"

using namespace std;

namespace ev {
  vector<string> split(const string& toSplit, const string& delimiter) {
    string_view toSplitView(toSplit);
    string_view delimiterView(delimiter);

    vector<string> tokens;
    int i = 0;
    for (const auto& elem : views::split(toSplitView, delimiterView))
      tokens.push_back(string(string_view(elem)));
    return tokens;
  }
}
