#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <string>
#include <tuple>
#include <vector>

#include "../include/homework_5.h"

using namespace std;
using namespace cv;

namespace ipb::serialization::sifts {

void ConvertDataset(const std::filesystem::path &img_path) {
    // std::filesystem::path edit_path = img_path;
    // std::cout << edit_path << std::endl;
    // std::cout << img_path.parent_path().replace_filename("bin/") << std::endl;

    const std::filesystem::path bin = img_path.parent_path().replace_filename("bin/");
    std::filesystem::create_directory(bin);
    const std::string bin_path = bin.string();
    // if (img_path) {
    //     std::filesystem::is_empty(bin_path);
    //     std::cout << "Does not exist" << std::endl;
    //     EXIT_FAILURE;
    // }
    for (const auto &dirEntry : std::filesystem::directory_iterator(img_path)) {
        const auto &stem = dirEntry.path().stem().string();
        const auto &extension = dirEntry.path().extension();

        if (extension == ".png") {
            const auto &descriptors_filename = bin_path + stem + ".bin";
            const auto &image_forSift = dirEntry.path().string();
            // std::cout << descriptors_filename << std::endl;
            // std::cout << image_forSift << std::endl;

            auto [desc, keypts] = SIFT_comp(image_forSift);

            std::ofstream file(descriptors_filename, std::ios_base::out | std::ios_base::binary);

            int type = desc.type();
            int row = desc.rows;
            int columns = desc.cols;
            auto *data = desc.data;

            file.write(reinterpret_cast<char *>(&row), sizeof(int));      // rows
            file.write(reinterpret_cast<char *>(&columns), sizeof(int));  // cols
            file.write(reinterpret_cast<char *>(&type), sizeof(int));     // type
            file.write(reinterpret_cast<char *>(&data), sizeof(data));    // data

            // if (std::filesystem::exists(descriptors_filename)) {
            //     std::cout << "yes" << std::endl;
            // }
            // ipb::serialization::Serialize(desc, descriptors_filename);
        }
    }
}

std::tuple<cv::Mat, cv::Mat> SIFT_comp(const std::string &fileName) {
    const cv::Mat kInput = cv::imread(fileName, cv::IMREAD_GRAYSCALE);

    // detect key points
    auto detector = cv::SiftFeatureDetector::create();
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(kInput, keypoints);

    // present the keypoints on the image
    cv::Mat image_with_keypoints;
    drawKeypoints(kInput, keypoints, image_with_keypoints);

    // extract the SIFT descriptors
    cv::Mat descriptors;
    auto extractor = cv::SiftDescriptorExtractor::create();
    extractor->compute(kInput, keypoints, descriptors);

    return std::make_tuple(descriptors, image_with_keypoints);
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path &bin_path) {
    std::vector<cv::Mat> vector_of_matrices;

    for (const auto &binEntry : std::filesystem::directory_iterator(bin_path)) {
        // std::cout << binEntry << std::endl;
        if (filesystem::path(binEntry).extension() == ".bin") {
            const auto &bin_string = binEntry.path().string();

            // for (const auto &descriptor : binEntry_path) {
            // std::cout << bin_string << std::endl;
            // std::string bin_string{descriptor.string()};

            cv::Mat to_read = ipb::serialization::Deserialize(bin_string);

            // std::cout << to_read.size() << std::endl;

            vector_of_matrices.push_back(to_read);
        }

        else {
            EXIT_FAILURE;
        }
    }
    // std::cout << vector_of_matrices.size() << std::endl;
    return vector_of_matrices;
}
}  // namespace ipb::serialization::sifts