#include "util/files.h"
#include <gtest/gtest.h>

TEST(FilesTest, ParseFile) {
  vector<string> example{"124",  "923",  "213",  "314", "134",
                         "1234", "1234", "1234", "1"};
  EXPECT_EQ(ev::parse("test/resources/test_parse.txt", '&').value(), example);
}
