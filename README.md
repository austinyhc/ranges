# ranges
Implementations of ranges that didn't make C++20.

## Features

- Many range adaptors that are not available in C++20, such as `enumerate`, `cartesian_product`, and `chunk`.
- `tl::basic_iterator` which simplifies the creation of your own range adaptors.
- `tl::to` for converting a range into a container.
- Several functional programming utilities to simplify ranges implementation, like `compose` and `bind_back`.

## Examples

### Range Adaptors

```cpp
for (auto&& [index, element] : my_vector | tl::views::enumerate) {
  //use both index and element
}

template <class F, std::ranges::forward_range... Vs>
requires(std::regular_invocable<F, 
          std::ranges::range_reference_t<Vs>...>)
auto find_tuples_satisfying(F f, Vs&&... vs) {
  return tl::views::cartesian_product(std::forward<Vs>(vs)...) 
    | std::views::filter(tl::uncurry(f))
    | tl::to<std::vector>();
}
```
