#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::string         filePath;
    std::string         line;
    std::stringstream  ss;

    if (ac == 1)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    filePath = av[1];
    std::ifstream       inF(filePath.c_str());
    if (inF.fail() || !inF.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (2);
    }
    while (std::getline(inF, line, '|'))
    {
        std::cout << line << std::endl;
    }
    inF.close();
    std::cout << filePath << std::endl;
    return (0);
}
