#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <iomanip> 
#include <cstring>
#include <string.h>
#include <sstream>

int main(int argc, char *argv[]) {

    // std::cout << "Check argc count " << argc << std::endl; Slide 37, Lecture 2

    if (argc != 3) {
    std::cout << "[ERROR] : Input two arguments only! \n" << std::endl;
    exit(EXIT_FAILURE);
      } 
      
    else {
    std::string file1, file2;
    file1 = argv[1];
    file2 = argv[2];
    std::stringstream file_1{file1};
    std::stringstream file_2{file2};
    std::string fn_string1, fn_string2;

    int filename1_integer;
    int filename2_integer;

    file_1 >> filename1_integer >> fn_string1;
    file_2 >> filename2_integer >> fn_string2;

    float mean;
    int sum;
    float modulo;

        if (fn_string1 == ".txt" && fn_string2 == ".txt"){
            sum = filename1_integer + filename2_integer;
            mean = sum/2;
            std::cout << mean << std::endl;
            return 0;

        }
        else if (fn_string1 == ".png" && fn_string2 == ".png") {
            sum = filename1_integer + filename2_integer;
            std::cout << sum << std::endl;
            return 0;
        }
        else if (fn_string1 == ".txt" && fn_string2 == ".png") {
            modulo = filename1_integer%filename2_integer;
            std::cout << modulo << std::endl;
            return 0;
        }
        else if (fn_string1.empty() || fn_string2.empty()) {
            std::cerr << "[ERROR]: Epty" << std ::endl;
            return 1;
            exit(EXIT_FAILURE);
        }
        else {
            std::cerr << "[ERROR]: Wrong file types!" << std ::endl;
            return 1;
            exit(EXIT_FAILURE);
        }
      }
}





