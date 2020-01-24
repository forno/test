namespace xmaho
{
namespace math
{
namespace detail
{
constexpr typename std::common_type<T1, T2>::type gcd_impl(const T1& a, const T2& b) noexcept
{ return b ? gcd_impl(b, a%b) : a; }
}
}
}

template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type xmaho::math::gcd(const T1& a, const T2& b) noexcept
{ return a ? detail::gcd_impl(b, a%b) : a; }

template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type xmaho::math::lcm(const T1& a, const T2& b) noexcept
{ return a / gcd(a, b) * b; }
