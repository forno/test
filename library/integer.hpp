namespace xmaho
{
inline namespace integer
{
template<typename C>
constexpr auto ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type;
template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept;
}
}
