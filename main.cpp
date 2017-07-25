#include <boost/network/protocol/http/client.hpp>

int main()
{
  using namespace boost::network;
  using namespace boost::network::http;
  client::request request_("http://s2707-1:3000/api/v0/users");
  request_ << header("Authorization", "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfX3YiOjAsInZhbHVlIjoiWUV3OVNKZEFvV1NQVzhycnBEQ0Qza1QxaXBhQnRoWHFuUWxnZVFuYXVOQ0lqRUp1MGlFYzg1UjN3cVF1N1c1RWxHejlya0E0d0dXbWJJZmQ0RW5uUFNDVE8xd1dQWUwyMXJzU0xwNzdKc0Fnc0xmS0N5ZUQ2QTV2dDc2dERtSmd0Y2dZNmNtOW9LeUxtc2R3a2RVSVk0amx5aEMyVmhjaVNIaU5kTWN1SnlIM2tXQ2VYMnNBZnJSVnlTamZtcFZBaEJOUU5oQzNuZ0hmb3NpRzdoVHFVWnlhb3VRWWltMUFjclVMaHQ0VnpaRDUzNlVhRURUMGV2S2V0eVJ2WUluOCIsImNsaWVudF9pZCI6IjU5NzVhMjlmMjg5NmE5NDg5YTc5NzExZiIsInVzZXJfaWQiOiI1OTc1YTI5MzI4OTZhOTQ4OWE3OTcxMWUiLCJfaWQiOiI1OTc2ZmJhODRiNjRiNTEzYzZkZjRkZGEifQ.758y7VQi2RyjwvOr3rVMUHhSJGum-Mro1bE2lzwD2BM");
  client client_;
  client::response response_ = client_.get(request_);
  std::string body_ = body(response_);
  std::cout << body_;
}
