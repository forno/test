#include <gtest/gtest.h>

#include "xmaho/math.hpp"

TEST(BaseModulo1Test, NullInput)
{
  xmaho::math::residue_system<1> null_number {};
  xmaho::math::residue_system<1> once_again {};
  ASSERT_EQ(null_number, once_again);
}

TEST(BaseModulo1Test, LeastResidueNumber)
{
  xmaho::math::residue_system<1> zero_number {0};
  xmaho::math::residue_system<1> once_again {0};
  ASSERT_EQ(zero_number, once_again);
}


TEST(BaseModulo1Test, EqualModuloNumber)
{
  xmaho::math::residue_system<1> modulo_number {1};
  xmaho::math::residue_system<1> least_residue_number {0};
  ASSERT_EQ(modulo_number, least_residue_number);
}

TEST(BaseModulo1Test, OverModuloNumber)
{
  xmaho::math::residue_system<1> residue_number {2};
  xmaho::math::residue_system<1> least_residue_number {0};
  ASSERT_EQ(residue_number, least_residue_number);
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

TEST(BaseModulo2Test, EqualModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {2};
  xmaho::math::residue_system<2> least_residue_number {0};
  ASSERT_EQ(residue_number, least_residue_number);
}

TEST(BaseModulo2Test, OverModuloNumber)
{
  xmaho::math::residue_system<2> residue_number {3};
  xmaho::math::residue_system<2> least_residue_number {1};
  ASSERT_EQ(residue_number, least_residue_number);
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
