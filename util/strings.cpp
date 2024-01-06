#include "util/strings.h"
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>

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

vector<string> split(const string &toSplit, const string &delimiter, const unsigned& limit = 1) {

}
} // namespace ev
