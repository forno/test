#include <chrono>
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

template<typename T>
struct Base
{
};

template<template<typename...> typename T>
struct X
{
};

template struct Base<int>;

template struct X<Base>;

int main()
{
  std::shared_timed_mutex count_mtx {};

  auto count {0};

  std::thread w {[&count, &count_mtx](){
    for (auto i {3}; i > 0; --i) {
      {
        std::lock_guard<std::shared_timed_mutex> count_lock {count_mtx};
        ++count;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds{1});
    }
  }};

  std::mutex cout_mtx {};

  auto reader {[&count, &cout_mtx, &count_mtx](){
    for (auto i {10}; i > 0; --i) {
      {
        std::shared_lock<std::shared_timed_mutex> count_lock {count_mtx};
        std::lock_guard<std::mutex> cout_lock {cout_mtx};
        std::cout << count << '\n';
      }
      std::this_thread::sleep_for(std::chrono::milliseconds{1});
    }
  }};

  std::vector<std::thread> r {};
  for (auto i {3}; i > 0; --i)
    r.emplace_back(reader);

  w.join();
  for (auto& e : r)
    e.join();
}
