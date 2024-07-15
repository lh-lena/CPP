#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <algorithm>
# include <exception>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>


class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    // class ExchangeException : public std::exception
    // {
    //     public:
    //         ExchangeException(const std::string &message);
    //         const char *what() const throw();
    //     private:
    //         std::string _msg;
    // };

private:
    std::map<int, float>    _database;
};



#endif //BITCOINEXCHANGE_HPP
