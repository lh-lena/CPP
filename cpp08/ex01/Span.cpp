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
}

int RandomNumber() { return (std::rand() % 100); }

void Span::addRandomNumbers()
{
    std::generate_n(_vec.begin(), 5, RandomNumber);
    // std::for_each(_vec.begin(), _vec.begin() + _nSize, RandomNumber);
}

int Span::shortestSpan()
{
    std::vector<int>::iterator it, low, next_low, tmp_low, tmp_next_low;
    int n = 0;
    int min_diff = __INT_MAX__;
    if (idx == 0 || idx == 1)
        throw(SpanException("Not enought elements. No span can be found"));
    std::sort(_vec.begin(), _vec.end());
    it = _vec.begin();
    for (int i = 0; i < _nSize - 1; i++, it++)
    {
        if (*(it + 1) - *it < min_diff)
            min_diff = *(it + 1) - *it;
    }
    return (min_diff);
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