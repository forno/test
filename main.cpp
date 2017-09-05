#include <valarray>

class C : std::valarray<int>
{
public:
  using std::valarray<int>::valarray;
  using std::valarray<int>::operator+;
};

int main(int argc, char** argv)
{
  C o {0, 1};
  std::valarray<int> test {+o};
  // C test {+o}; // compile error
}
