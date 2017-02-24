#include <gtest/gtest.h>

#include "xmaho/math/residue_system.hpp"

TEST(MathResidueSystemBaseModulo1, NullInput)
{
  xmaho::math::residue_system<1> null_number {};
  xmaho::math::residue_system<1> once_again {};
  ASSERT_EQ(null_number, once_again);
}

TEST(MathResidueSystemBaseModulo1, LeastResidueNumber)
{
  xmaho::math::residue_system<1> zero_number {0};
  xmaho::math::residue_system<1> once_again {0};
  ASSERT_EQ(zero_number, once_again);
}


TEST(MathResidueSystemBaseModulo1, EqualModuloNumber)
{
  xmaho::math::residue_system<1> modulo_number {1};
  xmaho::math::residue_system<1> least_residue_number {0};
  ASSERT_EQ(modulo_number, least_residue_number);
}

TEST(MathResidueSystemBaseModulo1, OverModuloNumber)
{
  xmaho::math::residue_system<1> residue_number {2};
  xmaho::math::residue_system<1> least_residue_number {0};
  ASSERT_EQ(residue_number, least_residue_number);
}

TEST(MathResidueSystemBaseModulo1, Addition)
{
  xmaho::math::residue_system<1> num1 {};
  xmaho::math::residue_system<1> num2 {};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<1>{});
}

TEST(MathResidueSystemBaseModulo1, Subtraction)
{
  xmaho::math::residue_system<1> num1 {};
  xmaho::math::residue_system<1> num2 {};
  ASSERT_EQ(num1 - num2, xmaho::math::residue_system<1>{});
}

TEST(MathResidueSystemBaseModulo2, EqualModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {2};
  xmaho::math::residue_system<2> least_residue_number {0};
  ASSERT_EQ(residue_number, least_residue_number);
}

TEST(MathResidueSystemBaseModulo2, OverModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {3};
  xmaho::math::residue_system<2> least_residue_number {1};
  ASSERT_EQ(residue_number, least_residue_number);
}

TEST(MathResidueSystemBaseModulo2, NormalAddition)
{
  xmaho::math::residue_system<2> num1 {};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<2>{1});
}

TEST(MathResidueSystemBaseModulo2, OverAddition)
{
  xmaho::math::residue_system<2> num1 {1};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<2>{});
}

TEST(MathResidueSystemBaseModulo2, Subtraction)
{
  xmaho::math::residue_system<2> num1 {1};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 - num2, xmaho::math::residue_system<2>{});
}

TEST(MathResidueSystemBaseModulo2, NormalPrefixIncrement)
{
  xmaho::math::residue_system<2> residue_number {};
  ++residue_number;
  ASSERT_EQ(residue_number, xmaho::math::residue_system<2>{1});
}

TEST(MathResidueSystemBaseModulo2, OverPrefixIncrement)
{
  xmaho::math::residue_system<2> residue_number {1};
  ++residue_number;
  ASSERT_EQ(residue_number, xmaho::math::residue_system<2>{});
}

TEST(MathResidueSystemBaseModulo2, NormalPrefixDecrement)
{
  xmaho::math::residue_system<2> residue_number {1};
  --residue_number;
  ASSERT_EQ(residue_number, xmaho::math::residue_system<2>{});
}

TEST(MathResidueSystemBaseModulo2, UnderPrefixDecrepemt)
{
  xmaho::math::residue_system<2> residue_number {};
  --residue_number;
  ASSERT_EQ(residue_number, xmaho::math::residue_system<2>{1});
}
