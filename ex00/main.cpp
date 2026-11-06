#include "BitcoinExchange.hpp"

int main()

{
    BitcoinExchange a;     
    BitcoinExchange b(a);  
    b = a;                 

    std::cout << a.isValidDate("2024-02-29") << std::endl;
    std::cout << a.isValidDate("2025-02-29") << std::endl;
    std::cout << a.isValidDate("2024-04-31") << std::endl;
    std::cout << a.isValidDate("2024-04-00") << std::endl;

    return 0;

}
