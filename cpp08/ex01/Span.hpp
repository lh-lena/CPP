#ifndef SPAN_HPP
# define SPAN_HPP
# include <exception>
# include <string>
# include <vector>
# include <algorithm>
# include <iostream>
# include <ctime>        // std::time
# include <cstdlib>      // std::rand, std::srand
# include <climits>

class Span
{
public:
    Span(unsigned int n);
    Span & operator=(const Span & src);
    Span(const Span & src);
    ~Span();

    void    addNumber(int n);
    int     shortestSpan();
    int     longestSpan();
    void    print();
    void    addRandomNumbers();
    void    addNumbersRange(int first, int n, const int & val);

    class SpanException : public std::exception
    {
        public:
            SpanException(const std::string & msg);
            const char *what() const throw();

        private:
            std::string _msg;
    };

private:
    Span();
    unsigned int      _nSize;
    std::vector<int>       _vec;
    int               idx;
};


#endif