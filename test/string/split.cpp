#include <regex>
#include <string>
#include <utility>

#include <gtest/gtest.h>

#include "xmaho/string/split.hpp"

TEST(StringSplitOriginal, HandlesNullInput)
{
  std::string base {};
  std::regex delimiter {};
  auto start {base.begin()};
  auto end {base.end()};
  auto result = xmaho::string::split(start, end, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitOriginal, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::regex delimiter(",");
  auto start {base.begin()};
  auto end {base.end()};
  auto result = xmaho::string::split(start, end, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitBase, HandlesNullInput)
{
  std::string base {};
  std::regex delimiter {};
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitBase, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::regex delimiter(",");
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitDelimiterForward, HandlesNullInput)
{
  std::string base {};
  std::string delimiter {};
  auto result = xmaho::string::split(base, std::move(delimiter));
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitDelimiterForward, HandlesNormalInput)
{
  std::string base("a,b,c");
  std::string delimiter(",");
  auto result = xmaho::string::split(base, std::move(delimiter));
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringPointer, HandlesNullInput)
{
  auto base = "";
  auto delimiter = "";
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringPointer, HandleNormalInput)
{
  auto base = "a,b,c";
  auto delimiter = ",";
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringPointerForward, HandlesNullInput)
{
  auto base = "";
  auto delimiter = "";
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringPointerForward, HandleNormalInput)
{
  auto base = "a,b,c";
  auto delimiter = ",";
  auto result = xmaho::string::split(std::move(base), delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringLiteral, HandlesNullInput)
{
  const char base[] {""};
  const char delimiter[] {""};
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringLiteral, HandleNormalInput)
{
  const char base[] {"a,b,c"};
  const char delimiter[] {","};
  auto result = xmaho::string::split(base, delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringLiteral, HandlesNoConstNullInput)
{
  char base[] {'\0'};
  auto delimiter = "";
  auto result = xmaho::string::split(base, delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringLiteral, HandleNoConstNormalInput)
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

TEST(StringSplitStringLiteral, HandlesRawNullInput)
{
  const char delimiter[] {""};
  auto result = xmaho::string::split("", delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringLiteral, HandleRawNormalInput)
{
  const char delimiter[] {","};
  auto result = xmaho::string::split("a,b,c", delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringLiteralForward, HandlesNullInput)
{
  const char base[] {""};
  const char delimiter[] {""};
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringLiteralForward, HandleNormalInput)
{
  const char base[] {"a,b,c"};
  const char delimiter[] {","};
  auto result = xmaho::string::split(std::move(base), delimiter);
  std::vector<std::string> ans {"a", "b", "c"};
  ASSERT_EQ(result, ans);
}

TEST(StringSplitStringLiteralForward, HandlesNoConstNullInput)
{
  char base[] {'\0'};
  auto delimiter = "";
  auto result = xmaho::string::split(std::move(base), delimiter);
  ASSERT_EQ(result, std::vector<std::string>{""});
}

TEST(StringSplitStringLiteralForward, HandleNoConstNormalInput)
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
