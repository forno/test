#include <iostream>
#include <iterator>

#include <Eigen/Dense>

enum class EC
{
  one,
  two
};

class C
{

};

std::ostream& operator<<(std::ostream& os, const EC& v) {
  os << static_cast<int>(v);
  return os;
}

int main()
{
  Eigen::Matrix<EC, 10, 10> field1 {};
  Eigen::Matrix<C, 10, 10> field2 {};

  std::copy(field1.data(),
            field1.data() + field1.size(),
            std::ostream_iterator<EC>(std::cout, " "));
  std::cout.put('\n');
}
