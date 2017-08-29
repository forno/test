#include <Eigen/Dense>

enum class EC
{
  one,
  two
};

class C
{

};

int main()
{
  Eigen::Matrix<EC, 10, 10> field1;
  Eigen::Matrix<C, 10, 10> field2;
}
