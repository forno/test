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

TEST(StringStringOriginal, ConstexprConstructWithNullArgs)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge\0hoge"};
}

TEST(StringStringOriginal, ConstexprConcat)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  s1 + s2;
}

TEST(StringStringOriginal, RuntimeConcat)
{
  xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  s1 + s2;
}

TEST(StringStringSizeMethod, Null)
{
  constexpr xmaho::string::basic_string<char, 10> s{};
  ASSERT_EQ(s.size(), 0ul);
}

TEST(StringStringSizeMethod, Normal)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge"};
  ASSERT_EQ(s.size(), 4ul);
}

TEST(StringStringSizeMethod, NullArg)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge\0hoge"};
  ASSERT_EQ(s.size(), 4ul);
}

TEST(StringStringSizeMethod, Concat)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  constexpr auto s {s1 + s2};
  ASSERT_EQ(s.size(), 8ul);
}

TEST(StringStringIteratorMethod, Normal)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge"};
  ASSERT_EQ(*s.begin(), 'h');
  ASSERT_EQ(*s.end(), '\0');
}
