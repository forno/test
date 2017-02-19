#include <iostream>

using Int3Array = int[3];
using Int3ArrayP = Int3Array*;

template<typename T>
void view_type(T);

template<typename S>
S& operator<<(S& stream, const Int3Array& value)
{
  stream << value[0] << value[1] << value[2] << std::endl;
  return stream;
}

int main(int argc, char** argv) {
  Int3Array a {1, 2, 3};
  Int3ArrayP p {&a}; // OK
  Int3ArrayP p {new Int3Array}; // Error
}
