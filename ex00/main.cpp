#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: expected an input file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange be;

        be.loadDatabase("data.csv");
        be.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;  
}
