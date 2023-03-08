#include <algorithm>
#include <iostream>
#include <numeric>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    // Grayscale image
    Mat1b img = imread("path_to_image", IMREAD_GRAYSCALE);

    // Compute histogram
    vector<int> hist(256, 0);
    for (int r = 0; r < img.rows; ++r)
        for (int c = 0; c < img.cols; ++c) {
            ++hist[img(r, c)]
        };

    cout << "number of 0: " << hist[0] << endl;
    cout << "number of 1: " << hist[1] << endl;
    // etc...

    // Sort according to frequency

    vector<int> indices(256);
    iota(indices.begin(), indices.end(), 0);  // 0, 1, ... 255
    sort(indices.begin(), indices.end(),
         [&hist](int lhs, int rhs) { return hist[lhs] > hist[rhs]; });

    cout << "1st frequent number: " << indices[0] << " with N: " << hist[indices[0]] << endl;
    cout << "2nd frequent number: " << indices[1] << " with N: " << hist[indices[1]] << endl;
    // etc

    return 0;
}