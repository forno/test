template<typename T>
T xmaho::input::get_value(std::istream& is)
{
  T v {};
  is >> v;
  return v;
}

template<typename C>
C xmaho::input::get_container(std::istream& is, typename C::size_type length)
{
  C v {};
  if (length != std::numeric_limits<typename C::size_type>::max())
    v.reserve(length);
  typename C::value_type e {};
  for (auto i {length}; i != 0 && is >> e; --i)
    v.push_back(std::move_if_noexcept(e));
  return v;
}
