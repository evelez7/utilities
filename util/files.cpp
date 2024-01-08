#include "util/files.h"
#include "include/util/strings.h"
#include "util/strings.h"
#include <fstream>

namespace ev {
optional<vector<string>> parse(const string &filename, const char &delimiter) {
  ifstream input;
  input.open(filename);
  if (!input.is_open())
    return nullopt;
  string line;

  vector<string> lines;
  while (getline(input, line, delimiter)) {
    auto newlinePosition = line.find('\n');
    if (newlinePosition != string::npos) {
      for (auto elem : ev::split(line, "\n"))
        lines.push_back(elem);
      continue;
    }
    lines.push_back(line);
  }
  return lines;
}
} // namespace ev
