#include <util/strings.h>
#include <gtest/gtest.h>

TEST(SplitTest, FullSplit) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two",
                      "three"};
  EXPECT_EQ(ev::split(testString, "."), results);
}

TEST(SplitTest, PartialSplit) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two.three"};
  EXPECT_EQ(ev::split(testString, ".", 1), results);
}

TEST(SplitTest, PartialSplitTwo) {
  std::string testString = "one.two.three.four";
  std::vector<std::string> results{"one", "two", "three.four"};
  EXPECT_EQ(ev::split(testString, ".", 2), results);
}

TEST(SplitTest, PartialSplitCorner) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two", "three"};
  EXPECT_EQ(ev::split(testString, ".", 2), results);
}
