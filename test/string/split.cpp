#include <regex>
#include <string>
#include <utility>

#include <gtest/gtest.h>

#include "xmaho/string/split.hpp"

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
  auto result = xmaho::string::split(base, std::move(delimiter));
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(DelimiterForwardTest, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::string delimiter(",");
  auto result = xmaho::string::split(base, std::move(delimiter));
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringPointerTest, HandlesNullInput)
{
  auto base = "";
  auto delimiter = "";
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringPointerTest, HandleNormalInput)
{
  auto base = "a,b,c";
  auto delimiter = ",";
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringPointerForwardTest, HandlesNullInput)
{
  auto base = "";
  auto delimiter = "";
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringPointerForwardTest, HandleNormalInput)
{
  auto base = "a,b,c";
  auto delimiter = ",";
  auto result = xmaho::string::split(std::move(base), delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralTest, HandlesNullInput)
{
  const char base[] {""};
  const char delimiter[] {""};
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralTest, HandleNormalInput)
{
  const char base[] {"a,b,c"};
  const char delimiter[] {","};
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralTest, HandlesNoConstNullInput)
{
  char base[] {'\0'};
  auto delimiter = "";
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralTest, HandleNoConstNormalInput)
{
  std::string base_context("a,b,c");
  char base[6];
  std::copy(base_context.cbegin(), base_context.cend(), base);
  base[base_context.size()] = '\0';
  auto delimiter = ",";
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralTest, HandlesRawNullInput)
{
  const char delimiter[] {""};
  auto result = xmaho::string::split("", delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralTest, HandleRawNormalInput)
{
  const char delimiter[] {","};
  auto result = xmaho::string::split("a,b,c", delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralForwardTest, HandlesNullInput)
{
  const char base[] {""};
  const char delimiter[] {""};
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralForwardTest, HandleNormalInput)
{
  const char base[] {"a,b,c"};
  const char delimiter[] {","};
  auto result = xmaho::string::split(std::move(base), delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringLiteralForwardTest, HandlesNoConstNullInput)
{
  char base[] {'\0'};
  auto delimiter = "";
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringLiteralForwardTest, HandleNoConstNormalInput)
{
  std::string base_context("a,b,c");
  char base[6];
  std::copy(base_context.cbegin(), base_context.cend(), base);
  base[base_context.size()] = '\0';
  auto delimiter = ",";
  auto result = xmaho::string::split(std::move(base), delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}
