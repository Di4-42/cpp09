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

    
    double nombre = 0;

    std::cout << a.isValidValue("42.5", nombre) << std::endl;
    std::cout << nombre << std::endl;
    std::cout << a.isValidValue("0", nombre) << std::endl;
    std::cout << a.isValidValue("-1", nombre) << std::endl;
    std::cout << a.isValidValue("1001", nombre) << std::endl;
    std::cout << a.isValidValue("abc", nombre) << std::endl;
    
    return 0;

}
