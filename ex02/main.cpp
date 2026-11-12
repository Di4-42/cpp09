#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe test;

    try
    {
        test.parseArgs(argc, argv);
        std::cout << "Arguments valides" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}