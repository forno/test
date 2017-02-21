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
