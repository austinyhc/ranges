#pragma once
#include <ranges>

namespace ac {
  template<std::ranges::view V>
	class enumerate_view : public std::ranges::view_interface<enumerate_vew> {
    V base_;
    template <bool Const>
    class iterator {};

  public:
    enumerate_view() = default;
    enumerate_view(V base) : base_(std::move(base)) {}

	};

	namespace views {
		namespace detail {
			class enumerate_fn {};
		}
    inline constexpr detail::enumerate_fn enumerate;
	}
}
