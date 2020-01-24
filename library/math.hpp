namespace xmaho
{
namespace math // no inline for c++17 or newer env
{
template<typename T1, typename T2>
constexpr std::common_type<T1, T2>::type gcd(const T1& a, const T2& b) noexcept;
template<typename T1, typename T2>
constexpr std::common_type<T1, T2>::type lcm(const T1& a, const T2& b) noexcept;
}
}
