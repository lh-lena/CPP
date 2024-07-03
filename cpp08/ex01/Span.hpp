#ifndef SPAN_HPP
# define SPAN_HPP
# include <exception>
# include <string>

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
    unsigned int    _nSize;
    int             *_arr;
    int               idx;
};


#endif