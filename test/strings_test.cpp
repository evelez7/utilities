#include <util/strings.h>
#include <gtest/gtest.h>

TEST(SplitTest, FullSplit) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two",
                      "three"};
  EXPECT_EQ(ev::split(testString, "."), results);
}
