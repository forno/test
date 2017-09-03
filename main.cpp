#include <iostream>
#include <type_traits>
#include <valarray>

template<typename T>
class valmatrix : private std::valarray<T>
{
public:
  //! Value type of valarray
  using std::valarray<T>::value_type;
  //! Size type for access to values.
  using size_type = std::size_t;
  //! Specific position type for two dimention.
  using position_type = std::pair<size_type, size_type>;

  /**
   * @brief Default contructor.
   */
  valmatrix() = default;

  //! Define default copy assign operator to avoid forward
  valmatrix& operator=(const valmatrix&) = default;
  //! Define default move assign operator to avoid forward
  valmatrix& operator=(valmatrix&&) = default;

  using std::valarray<T>::operator=;
};

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  valmatrix<int> vec;
  static_assert(std::is_same<decltype(vec = std::valarray<int>{}), std::valarray<int>&>::value, "super type...");
  static_assert(std::is_same<valmatrix<int>::value_type, std::valarray<int>::value_type>::value, "only using value_type");
}
