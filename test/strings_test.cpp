#include <util/strings.h>
#include <gtest/gtest.h>

TEST(StringsTest, FullSplit) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two",
                      "three"};
  EXPECT_EQ(ev::split(testString, "."), results);
}

TEST(StringsTest, PartialSplit) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two.three"};
  EXPECT_EQ(ev::split(testString, ".", 1), results);
}

TEST(StringsTest, PartialSplitTwo) {
  std::string testString = "one.two.three.four";
  std::vector<std::string> results{"one", "two", "three.four"};
  EXPECT_EQ(ev::split(testString, ".", 2), results);
}

TEST(StringsTest, PartialSplitCorner) {
  std::string testString = "one.two.three";
  std::vector<std::string> results{"one", "two", "three"};
  EXPECT_EQ(ev::split(testString, ".", 2), results);
}

TEST(StringsTest, TrimNewline) {
  std::string testString = "one\n";
  EXPECT_EQ(ev::trim(testString, "\n"), "one");
}

TEST(StringsTest, TrimUntilLimit) {
  std::string test = ".one.two.three.";
  EXPECT_EQ(ev::trim(test, ".", 2), "onetwo.three.");
}

TEST(StringsTest, ReplaceAllInstances) {
  std::string testString = "one&&two&&three";
  EXPECT_EQ(ev::replace(testString, "&&", ".."), "one..two..three");
}

TEST(StringsTest, TrimAllWhitespaces) {
  std::string testString = " onetwo three ";
  EXPECT_EQ(ev::replace(testString, " ", ""), "onetwothree");
}

TEST(StringsTest, Strip) {
  std::string test = " one twothree fourfive ";
  EXPECT_EQ(ev::strip(test, " "), "onetwothreefourfive");
}
