
#include "../api/homework_3.h"

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    const image_browser::ScoredImage img1{"../web_app/data/000000.png", 0.98};
    const image_browser::ScoredImage img2{"../web_app/data/000100.png", 0.96};
    const image_browser::ScoredImage img3{"../web_app/data/000200.png", 0.88};

    const image_browser::ScoredImage img4{"../web_app/data/000300.png", 0.87};
    const image_browser::ScoredImage img5{"../web_app/data/000400.png", 0.80};
    const image_browser::ScoredImage img6{"../web_app/data/000500.png", 0.79};

    const image_browser::ScoredImage img7{"../web_app/data/000600.png", 0.76};
    const image_browser::ScoredImage img8{"../web_app/data/000700.png", 0.75};
    const image_browser::ScoredImage img9{"../web_app/data/000800.png", 0.20};
    const image_browser::ImageRow triad_1{img1, img2, img3};
    const image_browser::ImageRow triad_2{img4, img5, img6};
    const image_browser::ImageRow triad_3{img7, img8, img9};

    const std::string title = "Image Browser";
    const std::string stylesheet = "../web_app/style.css";
    std::vector<image_browser::ImageRow> images_rows = {triad_1, triad_2, triad_3};

    image_browser::CreateImageBrowser(title, stylesheet, images_rows);

    return 0;
}
