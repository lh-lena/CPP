#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <algorithm>
# include <exception>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <ctime>
# include <cstring>

class BitcoinExchange
{
public:
    BitcoinExchange(const std::string & dbCsv);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    class ExchangeException : public std::exception
    {
        public:
            ExchangeException(const std::string &message);
            const char *what() const throw();
            virtual ~ExchangeException() _NOEXCEPT {};
        private:
            std::string _msg;
    };

    bool            loadDatabase( void );
    float           getBtcRate(time_t &date);
    float           calculateBtcRate(std::string &date, float val);
    static time_t   parseDate(const std::string& dateString);
    void            printMap();

private:
    BitcoinExchange();
    std::map<time_t, float>    _database;
    std::string                _dbCsv;
};

bool    checkHeader(const std::string &line, const std::string &s1, char c, const std::string &s2);

#endif //BITCOINEXCHANGE_HPP
