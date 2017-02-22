#include <gtest/gtest.h>

#include "xmaho/math.hpp"

TEST(BaseModulo1Test, NullInput)
{
  xmaho::math::residue_system<1> residue_number {};
  ASSERT_EQ(residue_number, 0u);
}

TEST(BaseModulo1Test, LeastResidueNumber)
{
  xmaho::math::residue_system<1> residue_number {0};
  ASSERT_EQ(residue_number, 0u);
}


TEST(BaseModulo1Test, EqualModuloNumber)
{
  xmaho::math::residue_system<1> residue_number {1};
  ASSERT_EQ(residue_number, 0u);
}

TEST(BaseModulo1Test, OverModuloNumber)
{
  xmaho::math::residue_system<1> residue_number {2};
  ASSERT_EQ(residue_number, 0u);
}

TEST(BaseModulo1Test, Addition)
{
  xmaho::math::residue_system<1> num1 {};
  xmaho::math::residue_system<1> num2 {};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<1>{});
}

TEST(BaseModulo1Test, Subtraction)
{
  xmaho::math::residue_system<1> num1 {};
  xmaho::math::residue_system<1> num2 {};
  ASSERT_EQ(num1 - num2, xmaho::math::residue_system<1>{});
}

TEST(BaseModulo2Test, NullInput)
{
  xmaho::math::residue_system<2> residue_number {};
  ASSERT_EQ(residue_number, 0u);
}

TEST(BaseModulo2Test, LeastResidueNumber)
{
  xmaho::math::residue_system<2> residue_number {1};
  ASSERT_EQ(residue_number, 1u);
}


TEST(BaseModulo2Test, EqualModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {2};
  ASSERT_EQ(residue_number, 0u);
}

TEST(BaseModulo2Test, OverModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {3};
  ASSERT_EQ(residue_number, 1u);
}

TEST(BaseModulo2Test, NormalAddition)
{
  xmaho::math::residue_system<2> num1 {};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<2>{1});
}

TEST(BaseModulo2Test, OverAddition)
{
  xmaho::math::residue_system<2> num1 {1};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 + num2, xmaho::math::residue_system<2>{});
}

TEST(BaseModulo2Test, Subtraction)
{
  xmaho::math::residue_system<2> num1 {1};
  xmaho::math::residue_system<2> num2 {1};
  ASSERT_EQ(num1 - num2, xmaho::math::residue_system<2>{});
}
