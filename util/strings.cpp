#include "util/strings.h"
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

using namespace std;

namespace ev {
vector<string> split(const string &toSplit, const string &delimiter) {
  string_view toSplitView(toSplit);
  string_view delimiterView(delimiter);

  vector<string> tokens;
  int i = 0;
  for (const auto &elem : views::split(toSplitView, delimiterView))
    tokens.push_back(string(string_view(elem)));
  return tokens;
}

vector<string> split(const string &toSplit, const string &delimiter,
                     const unsigned &limit) {
  vector<string> partiallySplitString;
  for (auto elem : toSplit | views::split(delimiter) | views::take(limit))
    partiallySplitString.push_back(string(string_view(elem)));

  string rejoinedString;
  for (auto elem : toSplit | views::split(delimiter) | views::drop(limit) |
                       views::join_with(delimiter))
    rejoinedString += elem;
  partiallySplitString.push_back(rejoinedString);
  return partiallySplitString;
}

string trim(string &target, const string &toFind, const unsigned &limit) {
  for (unsigned i = 0; i < limit; ++i) {
    auto pos = target.find(toFind);
    if (pos == string::npos)
      return target;
    target.erase(pos, toFind.length());
  }
  return target;
}

string replace(string &target, const string &pattern,
               const string &replacement) {
  string result;
  for (auto elem :
       target | views::split(pattern) | views::join_with(replacement))
    result += elem;
  return result;
}

string strip(const string &target, const string &pattern) {
  string result;
  for (auto elem : target | views::split(pattern) | views::join)
    result += elem;
  return result;
}
} // namespace ev
