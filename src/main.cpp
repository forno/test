namespace xmaho::si
{

template<int M, int K, int S>
struct Unit {
  enum {m = M, kg=K, s=S};
};

using M    = Unit<1,0,0>;
using Kg   = Unit<0,1,0>;
using S    = Unit<0,0,1>;
using MpS  = Unit<1,0,-1>;
using MpS2 = Unit<1,0,-2>;

template<typename U1, typename U2>
struct Uplus {
  using type = Unit<U1::m+U2::m, U1::kg+U2::kg, U1::s+U2::s>;
};

template<typename U1, typename U2>
using Unit_plus = typename Uplus<U1, U2>::type;

template<typename U1, typename U2>
struct Uminus {
  using type = Unit<U1::m-U2::m, U1::kg-U2::kg, U1::s-U2::s>;
};

template<typename U1, typename U2>
using Unit_minus = typename Uplus<U1, U2>::type;

template<typename U, typename T = double>
struct Quantity {
  T val;
  explicit constexpr Quantity(double f) : val{f} {}
};

template<typename U, typename T>
constexpr Quantity<U> operator+(Quantity<U, T> lhs, Quantity<U, T> rhs) {
  return Quantity<U>{lhs.val + rhs.val};
}

template<typename U, typename T>
constexpr Quantity<U, T> operator-(Quantity<U, T> lhs, Quantity<U, T> rhs) {
  return Quantity<U, T>{lhs.val - rhs.val};
}

template<typename U1, typename U2, typename T>
constexpr Quantity<Unit_plus<U1, U2>> operator*(Quantity<U1, T> lhs, Quantity<U2, T> rhs) {
  return Quantity<Unit_plus<U1, U2>>{lhs.val * rhs.val};
}

template<typename U1, typename U2, typename T>
constexpr Quantity<Unit_minus<U1, U2>> operator/(Quantity<U1, T> lhs, Quantity<U2, T> rhs) {
  return Quantity<Unit_minus<U1, U2>>{lhs.val / rhs.val};
}

template<typename U, typename T>
constexpr Quantity<U, T> operator*(Quantity<U, T> lhs, T rhs) {
  return Quantity<U, T>{lhs.val * rhs};
}

template<typename U, typename T>
constexpr Quantity<U, T> operator*(T lhs, Quantity<U, T> rhs) {
  return Quantity<U, T>{lhs * rhs.val};
}

template<typename U, typename T>
constexpr Quantity<U, T> operator/(Quantity<U, T> lhs, T rhs) {
  return Quantity<U, T>{lhs.val / rhs};
}

template<typename U, typename T>
constexpr Quantity<U, T> operator/(T lhs, Quantity<U, T> rhs) {
  return Quantity<U, T>{lhs / rhs.val};
}

}

namespace xmaho::literals
{
inline namespace si_literals
{

constexpr si::Quantity<si::M, double> operator""_m(long double d) { return si::Quantity<si::M, double>{static_cast<double>(d)}; }
constexpr si::Quantity<si::Kg, double> operator"" _kg(long double d) { return si::Quantity<si::Kg, double>{static_cast<double>(d)}; }
constexpr si::Quantity<si::S, double> operator"" _s(long double d) { return si::Quantity<si::S, double>{static_cast<double>(d)}; }

}
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  return 0;
}
