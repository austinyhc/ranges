#include "ac/enumerate.hpp"
#include <catch2/catch.hpp>
#include <vector>
#include <iostream>

TEST_CASE("basic vector") {
  std::vector a{ 1, 2, 3 };
  int i = 0;
  for (auto&& [index, item] : a | ac::views::enumerate) {
    REQUIRE(index == i);
    REQUIRE(item == i + 1);
    ++i;
  }
}
