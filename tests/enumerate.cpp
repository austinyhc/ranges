#include <catch2/catch.hpp>
#include <vector>
#include <iostream>
#include "ac/enumerate.hpp"

TEST_CASE("enumerate") {
  std::vector a{ 1, 2, 3 };
  for (auto&& [index, item] : a | ac::views::enumerate) {
    std::cout << "At index " << index << ": " << item;
  }
}
