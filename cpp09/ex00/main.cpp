#include "BitcoinExchange.hpp"

bool    checkHeader(const std::string &line, const std::string &s1, char c, const std::string &s2)
{
    std::string     timestamp, val;
    char            del;

    std::stringstream ss(line);
    if (ss >> timestamp >> del >> val)
    {
        if (timestamp.compare(s1) != 0 || val.compare(s2) != 0 || del != c)
            return (std::cerr << "Error: wrong data format" << std::endl, false);
    }
    else
        return (std::cerr << "Error: wrong format" << std::endl, false);
    return (true);
}

int    processInput(std::ifstream &inF, BitcoinExchange *db)
{
    std::string line, date;
    char        del;
    float       value, total;

    std::getline(inF, line);
    if (!checkHeader(line, "date", '|', "value"))
        return (5);
    while (std::getline(inF, line))
    {
        std::stringstream ss(line);
        if (ss >> date >> del >> value)
        {
            try
            {
                total = db->calculateBtcRate(date, value);
                std::cout.precision(7);
                std::cout
                << date << " => "
                << value << " = "
                << total << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else
            std::cerr << "Error: bad input => " << line << std::endl;
    }
    return (0);
}

int main(int ac, char **av)
{
    std::string         filePath;
    BitcoinExchange     db("data.csv");

    if (ac == 1)
        return (std::cerr << "Error: could not open file." << std::endl, 2);
    filePath = av[1];
    std::ifstream       inF(filePath.c_str());
    if (inF.fail() || !inF.is_open())
        return (std::cerr << "Error: could not open file." << std::endl, 3);
    if (!db.loadDatabase())
        return (inF.close(), 4);
    if (processInput(inF, &db) != 0)
        return (inF.close(), 1);
    inF.close();
    return (0);
}
