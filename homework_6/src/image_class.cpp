#include "../include/image_class.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <string>
#include <vector>

namespace igg {

// int size_of_data(const std::vector<int>& data_) { return data_.size(); }

// int& Image::at(int row, int col) { return data_.at(row * rows_ + col); }
// const int& Image::at(int row, int col) const { return data_.at(row * rows_ + col); }

uint8_t& Image::at(int row, int col) { return data_[row * cols_ + col]; }
const uint8_t& Image::at(int row, int col) const { return data_[row * cols_ + col]; }

// convert to and from ImageData struct
bool Image::FillFromPgm(const std::string& file_name) {
    bool not_empty = true;

    io_tools::ImageData read_image_data = io_tools::ReadFromPgm(file_name);

    // not_empty = !read_image_data.data.empty();
    if (read_image_data.data.empty()) {
        not_empty = false;
    }

    rows_ = read_image_data.rows;
    cols_ = read_image_data.cols;
    max_val = read_image_data.max_val;
    data_.assign(read_image_data.data.begin(), read_image_data.data.end());

    return not_empty;
}
void Image::WriteToPgm(const std::string& file_name) {
    io_tools::ImageData image_data = {rows_, cols_, max_val, data_};
    io_tools::WriteToPgm(image_data, file_name);
}

std::vector<float> Image::ComputeHistogram(int bins) const {
    std::vector<float> comp_hist(bins);
    comp_hist.resize(bins);
    std::fill(comp_hist.begin(), comp_hist.end(), 0);
    std::cout << "the number of bins for this histogram is :" << bins << std::endl;

    for (const auto& pixel : data_) {
        int pixel_value = static_cast<int>(pixel);
        int bin = (((pixel_value - 1) * bins) / 255);
        // int bin = static_cast<int>(bin_float);
        std::cout << "The pixel value is   :" << pixel_value << std::endl
                  << "And i'm assigning bin: " << bin << std::endl;
        ++comp_hist[bin];
        // std::cout << "BIN: " << comp_hist[10] << std::endl;
    }

    auto size = static_cast<float>(data_.size());
    for (float& normalize : comp_hist) {
        normalize /= size;
        std::cout << "normalized: " << normalize << std::endl;
    }

    std::cout << "Histogram size :  " << comp_hist.size() << std::endl;
    return comp_hist;
}

void Image::DownScale(int scale) {
    int new_rows = rows_ / scale;
    int new_cols = cols_ / scale;

    std::vector<u_int8_t> data_new(static_cast<long>(new_rows) * new_cols, 0);

    for (int i = 0; i <= new_rows; i++) {
        for (int j = 0; j <= new_cols; j++) {
            data_new[i * new_cols + j] = at(i * scale, j * scale);
        }
    }

    rows_ = new_rows;
    cols_ = new_cols;
    data_.resize(static_cast<long>(rows_) * cols_);
    data_ = data_new;
}
// }

void Image::UpScale(int scale) {
    int total_size = rows_ * cols_;
    int new_rows_ = rows_ * scale;
    int new_cols_ = cols_ * scale;
    // constructor for the vector of new data whose size is that of the original size x
    // scale
    std::vector<u_int8_t> data_new(static_cast<long>(new_rows_) * new_cols_);

    for (int i = 0; i < total_size; ++i)

    {
        for (int j = 0; j < scale; ++j) {
            for (int k = 0; k < scale; ++k) {
                int originalRow = i / rows_;
                int originalCol = i % cols_;
                int new_row = originalRow * scale + j;
                int new_col = originalCol * scale + k;
                int new_data = new_row * scale * rows_ + new_col;
                data_new[new_data] = data_[originalRow * cols_ + originalCol];
            }

            // write newly generated data to original
        }
    }
    data_.resize(static_cast<long>(scale) * scale * total_size);
    rows_ *= scale;
    cols_ *= scale;
    data_ = data_new;
}

}  // namespace igg
