#include <algorithm>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>
#include <tuple>
#include <vector>

#include "../include/homework_5.h"

namespace ipb::serialization {
void Serialize(const cv::Mat &m, const std::string &filename) {
    std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);
    int type = m.type();
    int row = m.rows;
    int columns = m.cols;
    auto *data = m.data;
    file.write(reinterpret_cast<char *>(&row), sizeof(row));          // rows
    file.write(reinterpret_cast<char *>(&columns), sizeof(columns));  // cols
    file.write(reinterpret_cast<char *>(&type), sizeof(type));        // type
    file.write(reinterpret_cast<char *>(&data), sizeof(data));        // data
}

cv::Mat Deserialize(const std::string &filename) {
    std::ifstream file(filename, std::fstream::binary);

    if (!file) {
        EXIT_FAILURE;
    }

    int row = 0;
    int columns = 0;
    int type = 0;
    uchar *data = nullptr;

    file.read(reinterpret_cast<char *>(&row), sizeof(row));          // rows
    file.read(reinterpret_cast<char *>(&columns), sizeof(columns));  // cols
    file.read(reinterpret_cast<char *>(&type), sizeof(type));        // type
    file.read(reinterpret_cast<char *>(&data), sizeof(data));        // data

    // Data
    cv::Mat deserialized_mat(row, columns, type, data);
    return deserialized_mat;
}

}  // namespace ipb::serialization