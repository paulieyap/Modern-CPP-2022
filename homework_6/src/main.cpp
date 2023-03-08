#include "../include/homework_6.h"

int main() {
    // (1) Create image class : Image(int rows, int cols)
    // igg::Image image(512, 512);  // dec rows,cols
    igg::Image image;
    image.FillFromPgm("../tests/data/dummy_file.pgm");
    // image.FillFromPgm("../data/lena.ascii.pgm");
    const auto& image_ref = image;
    auto histogram = image_ref.ComputeHistogram(10);

    std::cout << histogram.front() << "First: " << histogram[0] << " "
              << "1:" << histogram[1] << " "
              << "2: " << histogram[2] << std::endl
              << " "
              << "3: " << histogram[3] << std::endl
              << " "
              << "4: " << histogram[4] << std::endl
              << " "
              << "5: " << histogram[5] << std::endl
              << " "
              << "6: " << histogram[6] << std::endl
              << " "
              << "7: " << histogram[9] << std::endl
              << " "
              << "8: " << histogram[8] << std::endl
              << " "
              << " "
              << "Histogram [9]: " << histogram[9] << std::endl
              << "Histogram [10]: " << histogram[10] << std::endl;
    return 0;
}