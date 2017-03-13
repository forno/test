#include <gtest/gtest.h>

#include "xmaho/string/string.hpp"

TEST(StringStringOriginal, NormalConstruct)
{
  xmaho::string::basic_string<char, 10>{};
}

TEST(StringStringOriginal, ConstexprConstruct)
{
  constexpr xmaho::string::basic_string<char, 10> s{};
}

TEST(StringStringOriginal, ConstexprConstructWithArgs)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge"};
}

TEST(StringStringSizeMethod, Null)
{
  constexpr xmaho::string::basic_string<char, 10> s{};
  ASSERT_EQ(s.size(), 0ul);
}

TEST(StringStringSizeMethod, Normal)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge"};
  ASSERT_EQ(s.size(), 5ul);
}
