#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange be;     
    BitcoinExchange beTwo(be);  
    beTwo = be;                 

    std::cout << be.isValidDate("2024-02-29") << std::endl;
    std::cout << be.isValidDate("2025-02-29") << std::endl;
    std::cout << be.isValidDate("2024-04-31") << std::endl;
    std::cout << be.isValidDate("2024-04-00") << std::endl;

    
    double nombre = 0;

    std::cout << be.isValidValue("42.5", nombre) << std::endl;
    std::cout << nombre << std::endl;
    std::cout << be.isValidValue("0", nombre) << std::endl;
    std::cout << be.isValidValue("-1", nombre) << std::endl;
    std::cout << be.isValidValue("1001", nombre) << std::endl;
    std::cout << be.isValidValue("abc", nombre) << std::endl;

    be._db["2024-01-01"] = 100;
    be._db["2024-01-03"] = 120;
    be._db["2024-01-05"] = 150;

    try
    {
        std::cout << be.getRateForDate("2024-01-03") << std::endl; // 120
        std::cout << be.getRateForDate("2024-01-04") << std::endl; // 120
        std::cout << be.getRateForDate("2024-01-06") << std::endl; // 150
        std::cout << be.getRateForDate("2023-12-31") << std::endl;
    }
    catch (const std::runtime_error& error)
    {  
        std::cout << error.what() << std::endl;
    }          
    
    return 0;

}
