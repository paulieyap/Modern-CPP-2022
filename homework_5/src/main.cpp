#include <cstdlib>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>
#include <tuple>
#include <vector>

#include "../include/homework_5.h"
using namespace std;

int main() {
    // Serialize
    // cv::Mat lenna = cv::imread("../data/lenna.png", cv::IMREAD_GRAYSCALE);
    // ipb::serialization::Serialize(lenna, "../data/lenna.bin");

    // // Convert Data Set
    std::filesystem::path img_path = "../data/freiburg/images/";
    ipb::serialization::sifts::ConvertDataset(img_path);

    // Load Data
    std::filesystem::path bin_path = "../data/freiburg/bin/";
    std::vector<cv::Mat> loaded_bins = ipb::serialization::sifts::LoadDataset(bin_path);

    std::cout << loaded_bins.size() << std::endl;

    cv::Mat concat;
    cv::vconcat(loaded_bins, concat);

    std::cout << concat.size << std::endl;

    // Deserialize
    cv::Mat lenna_bin = ipb::serialization::Deserialize("../data/lenna.bin");

    // if (lenna_bin.empty()) {
    //     std::cerr << "No image data \n";
    //     return EXIT_FAILURE;
    // }

    // std::filesystem::remove_all(bin_path);
    return 0;
}
