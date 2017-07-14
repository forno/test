#include <iomanip>
#include <iostream>
#include <limits>

constexpr long double PIld {3.141592653589793238L};
constexpr double PId       {3.141592653589793};
constexpr float PIf        {3.1415927};

int main(void){

  std::cout << std::setprecision(std::numeric_limits<long double>::max_digits10) <<
    PIld << '\n' <<
    PId << '\n' <<
    PIf << '\n';

  return 0;
}

