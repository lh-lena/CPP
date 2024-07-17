#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string & dbCsv) : _dbCsv(dbCsv) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _dbCsv(src._dbCsv) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (&src != this)
        _dbCsv = src._dbCsv;
    return (*this);
}

/*
** --------------------------------- EXCEPTION -------------------------------
*/

BitcoinExchange::ExchangeException::ExchangeException(const std::string &message) : _msg(message) {};

const char *BitcoinExchange::ExchangeException::what() const throw()
{
    return (_msg.c_str());
}

BitcoinExchange::ExchangeException::~ExchangeException() throw() {};

/*
** --------------------------------- METHODS ----------------------------------
*/

// function to parse a date or time string.
time_t BitcoinExchange::parseDate(const std::string &dateString)
{
    time_t time;
    struct tm tmStruct;
    memset(&tmStruct, 0, sizeof(struct tm));
    if (strptime(dateString.c_str(), "%Y-%m-%d", &tmStruct) == 0)
        throw ExchangeException("Error: invalid date.");
    tmStruct.tm_isdst = -1;
    time = mktime(&tmStruct);
    if (time == -1)
        throw ExchangeException("Error: invalid date.");
    return (time);
}

bool BitcoinExchange::loadDatabase( void )
{
    std::string     line, date;
    float           value = 0.00f;
    time_t          timestamp = -1;

    std::ifstream   file(_dbCsv.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Failed to open file: " << _dbCsv << std::endl;
        return false;
    }
    std::getline(file, line);
    if (line.empty())
    {
        std::cerr << "Error: file is empty" << std::endl;
        file.close();
        return false;
    }
    while (std::getline(file, date, ',') && std::getline(file, line))
    {
        try
        {
            timestamp = BitcoinExchange::parseDate(date);
            std::istringstream iss(line);
            iss >> value;
            if (iss.fail())
                std::cerr << "Conversion failed" << std::endl;
            _database[timestamp] = value;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;;
        }
    }
    file.close();
    return true;
}

float BitcoinExchange::calculateBtcRate(std::string &date, float val)
{
    time_t dt = BitcoinExchange::parseDate(date);
    float   rate, total;
    if (val < 0)
        throw ExchangeException("Error: not a positive number.");
    if (val > 1000)
        throw ExchangeException("Error: too large a number.");
    if (dt == -1)
        throw ExchangeException("Error: wrong date.");
    rate = this->getBtcRate(dt);
    total = rate * val;
    return (total);
}

void    BitcoinExchange::printMap()
{
    std::map<time_t, float>::iterator it;
    it = _database.begin();
    while (it != _database.end())
    {
        std::cout 
        << "Key: " 
        << it->first 
        << ", Value: " 
        << it->second
        << std::endl;
        it++;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float BitcoinExchange::getBtcRate(time_t &date)
{
    std::map<time_t, float>::iterator it;

    it = _database.begin();
    if (it->first > date)
        throw BitcoinExchange::ExchangeException("Error: the date not found.");
    for(; it != _database.end() && it->first <= date; it++) {}
    if (it->first > date)
        it--;
    return (it->second);
}


/* ************************************************************************** */