
#ifndef NAMED_VECTOR_H_
#define NAMED_VECTOR_H_
#include <algorithm>
#include <boost/core/demangle.hpp>
#include <cstddef>
#include <cstdlib>
#include <experimental/iterator>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace ipb {
template <typename T>
struct named_vector {
    std::string string_value;
    std::vector<T> my_vector;

    std::string name() { return string_value; }
    std::vector<T> vector() { return my_vector; }

    size_t size() { return my_vector.size() + string_value.size(); }
    size_t capacity() { return my_vector.capacity(); }
    bool empty() { return my_vector.empty() || string_value.empty(); }
    auto begin() { return my_vector.begin(); }
    auto end() { return my_vector.end(); }
    auto cbegin() const { return my_vector.cbegin(); }
    auto cend() const { return my_vector.cend(); }

    void resize(int count) { return my_vector.resize(count); }

    void reserve(size_t n) { return my_vector.reserve(n); }
};

}  // namespace ipb
#endif  // NAMED_VECTOR_H_
