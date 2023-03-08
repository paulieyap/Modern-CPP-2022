#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
#include <string>


int random_number_generator(void) {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0,99);


    int random_number = distribution(rd);
    std::cout << random_number << '\n';

    return random_number;
}

int main() {
    int correct_random_number = random_number_generator();   
    int guess_number = -1;
    std ::cout << "Please input any number " << std ::endl;
    std ::cin >> guess_number;

    if(std ::cin.fail())
    {
        std::cerr << "Error encountered, exiting...\n";
        return 1;
        exit(EXIT_FAILURE);
    }

    //new 

        else {

	do
	{
    std ::cout << "Please input any number " << std ::endl;
    std ::cin >> guess_number;

		if ( guess_number < correct_random_number && guess_number < 99)
		{
			std::cout << "It should be larger" << std ::endl;
		}
		else if ( guess_number > correct_random_number && guess_number < 99 )
		{
			std::cout << "It should be smaller" << std ::endl;    
		}
        else if (guess_number > 99) {

                std::cerr << "[WARNING] : Number must be between 0 and 99" << std ::endl;
                return 1;
                exit(EXIT_FAILURE);

        }
		else if ( guess_number == correct_random_number )
		{
                std::cout << "You have won" << std ::endl;
                return 0;
                exit(EXIT_SUCCESS);
		}

	} while ( guess_number != correct_random_number );
	


    }

    std::cout << "The random number was " << correct_random_number << std ::endl;

    return 0;

}




