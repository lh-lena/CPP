#include "Span.hpp"

Span::Span(unsigned int n) : _nSize(n), idx(0)
{
    _vec.reserve(_nSize);
}

Span::Span(const Span &src) : _nSize(src._nSize), idx(src.idx), _vec(src._vec) {}

Span &Span::operator=(const Span &src)
{
    if (&src != this)
    {
        _nSize = src._nSize;
        idx = src.idx;
        _vec = src._vec;
    }
    return (*this);
}

Span::SpanException::SpanException(const std::string &msg) : _msg(msg) {}

const char *Span::SpanException::what() const throw()
{
    return (_msg.c_str());
}

void Span::addNumber(int n)
{
    if (idx == _nSize)
        throw(SpanException("Reached max of elements"));
    _vec.push_back(n);
    idx = _vec.size();
    std::sort(_vec.begin(), _vec.end());
}
int RandomNumber() { return (std::rand() % 100); }

void Span::addRandomNumbers()
{
    std::generate(_vec.begin(), _vec.end(), RandomNumber);
}

int Span::shortestSpan()
{
    if (idx == 0 || idx == 1)
        throw(SpanException("Not enought elements. No span can be found"));
    std::vector<int>::iterator low, next_low;
    low = std::min_element(_vec.begin(), _vec.end());
    next_low = std::upper_bound(_vec.begin(), _vec.end(), *low);
    std::cout << "LOw: " << *low << std::endl;
    std::cout << "next_lw: " << *next_low << std::endl;
    return (*next_low - *low);
}
int Span::longestSpan()
{
    if (idx == 0 || idx == 1)
        throw(SpanException("Not enought elements. No span can be found"));
    std::vector<int>::iterator max, min;
    max = std::max_element(_vec.begin(), _vec.end());
    min = std::min_element(_vec.begin(), _vec.end());
    std::cout << "max: " << *max << std::endl;
    std::cout << "min: " << *min << std::endl;
    return (*max - *min);
}

Span::~Span() {}

void Span::print()
{
    std::cout << "Vector contains:";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

/**
 * use the reserve method to preallocate memory for a certain number of elements,
 *  which avoids multiple reallocations as elements are added
 *
 */