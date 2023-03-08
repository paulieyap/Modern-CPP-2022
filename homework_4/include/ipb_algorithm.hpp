#ifndef IPB_ALGORITHM_H_
#define IPB_ALGORITHM_H_

#include <algorithm>
#include <numeric>

#include "named_vector.hpp"
namespace ipb {

template <typename T>
T accumulate(const ipb::named_vector<T>& v) {
    return std::accumulate(v.cbegin(), v.cend(), 0);
}

template <typename T>
T count(const ipb::named_vector<T>& v, T n) {
    return std::count(v.cbegin(), v.cend(), n);
}

inline bool even(int i) { return i % 2 == 0; };

template <typename T>
bool all_even(const ipb::named_vector<T>& v) {
    bool all_even = all_of(v.cbegin(), v.cend(), even);
    return all_even;
}

template <typename T>
void clamp(ipb::named_vector<T>& v, T kMin, T kMax) {
    for (auto& v_elem : v.my_vector) {
        v_elem = std::clamp(v_elem, kMin, kMax);
    }
}

template <typename T>
void fill(ipb::named_vector<T>& v, const T& n) {
    std::fill(v.begin(), v.end(), n);
}

template <typename T>
T find(const ipb::named_vector<T>& v, T n) {
    return *std::find(v.cbegin(), v.cend(), n);
}

template <typename T>
void print(const ipb::named_vector<T>& v) {
    std::for_each(v.cbegin(), v.cend(), [](const auto& e) { std::cout << e << " "; });
}
inline auto UpperCase(char c) { return std::toupper(c); }
template <typename T>
void toupper(ipb::named_vector<T>& v) {
    std::transform(v.string_value.begin(), v.string_value.end(), v.string_value.begin(), UpperCase);
}

template <typename T>
void sort(ipb::named_vector<T>& v) {
    std::sort(v.begin(), v.end());
}

template <typename T>
void rotate(ipb::named_vector<T>& v, T n) {
    std::rotate(v.begin(), v.begin() + n, v.end());
}

template <typename T>
void reverse(ipb::named_vector<T>& v) {
    std::reverse(v.begin(), v.end());
}
}  // namespace ipb
#endif  // IPB_ALGORITHM_H_
