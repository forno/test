#include <regex>
#include <string>

#include <gtest/gtest.h>

#include "xmaho/string.hpp"

TEST(BaseTest, HandlesNullInput)
{
  std::string base {};
  std::regex delimiter {};
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(BaseTest, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::regex delimiter(",");
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(DelimiterForwardTest, HandlesNullInput)
{
  std::string base {};
  std::string delimiter {};
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(DelimiterForwardTest, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::string delimiter(",");
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralTest, HandlesNullInput)
{
  auto base = "";
  auto delimiter = "";
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralTest, HandleNormalInput)
{
  auto base = "a,b,c";
  auto delimiter = ",";
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}
