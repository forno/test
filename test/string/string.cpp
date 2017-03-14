#include <string>

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

TEST(StringStringCastToString, NormalConstruct)
{
  xmaho::string::basic_string<char, 10> s {};
  ASSERT_EQ(static_cast<std::string>(s), std::string{});
}

TEST(StringStringCastToString, ConstexprConstruct)
{
  constexpr xmaho::string::basic_string<char, 10> s{};
  ASSERT_EQ(static_cast<std::string>(s), std::string{});
}

TEST(StringStringCastToString, ConstexprConstructWithArgs)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge"};
  ASSERT_EQ(static_cast<std::string>(s), std::string{"hoge"});
}

TEST(StringStringCastToString, ConstexprConstructWithNullArgs)
{
  constexpr xmaho::string::basic_string<char, 10> s{"hoge\0hoge"};
  ASSERT_EQ(static_cast<std::string>(s), std::string{"hoge"});
}

TEST(StringStringCastToString, ConstexprConcat)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  ASSERT_EQ(static_cast<std::string>(s1 + s2), std::string{"hogenyan"});
}

TEST(StringStringCastToString, RuntimeConcat)
{
  xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  ASSERT_EQ(static_cast<std::string>(s1 + s2), std::string{"hogenyan"});
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

TEST(StringStringCompareMethod, Null)
{
  constexpr xmaho::string::basic_string<char, 10> s1{};
  constexpr xmaho::string::basic_string<char, 1> s2{};
  ASSERT_EQ(s1.compare(s2), 0);
}

TEST(StringStringCompareMethod, Normal)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge"};
  constexpr xmaho::string::basic_string<char, 5> s2{"hoge"};
  ASSERT_EQ(s1.compare(s2), 0);
}

TEST(StringStringCompareMethod, NullArg)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"hoge"};
  ASSERT_EQ(s1.compare(s2), 0);
}

TEST(StringStringCompareMethod, Difference)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  ASSERT_LT(s1.compare(s2), 0);
}

TEST(StringStringLessthanMethod, Null)
{
  constexpr xmaho::string::basic_string<char, 10> s1{};
  constexpr xmaho::string::basic_string<char, 1> s2{};
  ASSERT_FALSE(s1 < s2);
}

TEST(StringStringLessthanMethod, Normal)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge"};
  constexpr xmaho::string::basic_string<char, 5> s2{"hoge"};
  ASSERT_FALSE(s1 < s2);
}

TEST(StringStringLessthanMethod, NullArg)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"hoge"};
  ASSERT_FALSE(s1 < s2);
}

TEST(StringStringLessthanMethod, Difference)
{
  constexpr xmaho::string::basic_string<char, 10> s1{"hoge\0hoge"};
  constexpr xmaho::string::basic_string<char, 10> s2{"nyan\0nyan"};
  ASSERT_TRUE(s1 < s2);
}
