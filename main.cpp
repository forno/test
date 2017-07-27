#include <ab_connector.hpp>

int main()
{
  AbilityBankConnector connector {"http://s2707-1:3000/api/v0/"};
  connector.set_key("eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfX3YiOjAsInZhbHVlIjoiWUV3OVNKZEFvV1NQVzhycnBEQ0Qza1QxaXBhQnRoWHFuUWxnZVFuYXVOQ0lqRUp1MGlFYzg1UjN3cVF1N1c1RWxHejlya0E0d0dXbWJJZmQ0RW5uUFNDVE8xd1dQWUwyMXJzU0xwNzdKc0Fnc0xmS0N5ZUQ2QTV2dDc2dERtSmd0Y2dZNmNtOW9LeUxtc2R3a2RVSVk0amx5aEMyVmhjaVNIaU5kTWN1SnlIM2tXQ2VYMnNBZnJSVnlTamZtcFZBaEJOUU5oQzNuZ0hmb3NpRzdoVHFVWnlhb3VRWWltMUFjclVMaHQ0VnpaRDUzNlVhRURUMGV2S2V0eVJ2WUluOCIsImNsaWVudF9pZCI6IjU5NzVhMjlmMjg5NmE5NDg5YTc5NzExZiIsInVzZXJfaWQiOiI1OTc1YTI5MzI4OTZhOTQ4OWE3OTcxMWUiLCJfaWQiOiI1OTc2ZmJhODRiNjRiNTEzYzZkZjRkZGEifQ.758y7VQi2RyjwvOr3rVMUHhSJGum-Mro1bE2lzwD2BM");
  std::cout << connector.get("users") << '\n';
  std::cout << connector.get("/scores",
                             R"({"score_type_id": "5975a2fd2896a9489a797122",
                                 "user_id": "5975a2932896a9489a79711e",
                                 "value": 1})") << '\n';

}
