template<typename C>
constexpr auto ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type
{ return c.size(); }

template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept
{ return N; }
