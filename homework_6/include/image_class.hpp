#ifndef IGG_IMAGE_CLASS_
#define IGG_IMAGE_CLASS_

#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "io_tools.hpp"

namespace igg {

class Image {
public:
    Image() = default;

    Image(int rows, int cols) : rows_{rows}, cols_{cols} {
        // data_.reserve((static_cast<int>(rows)) * cols);
        data_.resize(static_cast<long>(rows_) * cols_);
    };

    // auto size_of_data() const { return data_.size(); }

    int rows() const { return rows_; }
    int cols() const { return cols_; }

    u_int8_t& at(int row, int col);
    const u_int8_t& at(int row, int col) const;

    // A.2
    bool FillFromPgm(const std::string& file_name);       // do in cpp
    void WriteToPgm(const std::string& file_name);        // do in cpp
                                                          // A.3
    std::vector<float> ComputeHistogram(int bins) const;  // do in cpp
    // A.4
    void DownScale(int scale);  // do in cpp
    void UpScale(int scale);    // do in cpp

private:
    int rows_ = 0;
    int cols_ = 0;
    uint8_t max_val = 255;
    std::vector<uint8_t> data_;
};

}  // namespace igg

#endif  // IGG_IMAGE_CLASS