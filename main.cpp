#include <iostream>

using namespace std;

void func(int a, int b)
{
  cout << a << ' ' << b << '\n';
}

int main(int argc, char** argv)
{
  func({}, {});
}
