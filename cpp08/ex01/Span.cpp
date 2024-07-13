#include "Span.hpp"

Span::Span(unsigned int n) : _nSize(n), idx(0)
{
    if (UINT_MAX - abs(n) + 1 == _nSize)
        throw(SpanException("Error. Invalid size"));
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

void    Span::addNumbersRange(int first, int n, const int & val)
{
    if ((first + n) > _nSize || first > idx || first < 0 || n < 0)
        throw(SpanException("Error. Invalid range"));
    try
    {
        _vec.insert(_vec.begin() + first, n, val);
    }
    catch (std::exception &e)
    {
        std::cerr <<"Exception: " << e.what() << std::endl;
    }
    idx = _vec.size();
}

int Span::shortestSpan()
{
    std::vector<int>::iterator it;
    std::vector<int> tmp_vec = _vec;
    int n = 0;
    int min_diff = INT_MAX;
    int tmp = -1;
    if (idx == 0 || idx == 1)
        throw(SpanException("Not enought elements. No span can be found"));
    std::sort(tmp_vec.begin(), tmp_vec.end());
    it = tmp_vec.begin();
    for (int i = 0; i < _nSize - 1; ++i, ++it)
    {
        tmp =*(it + 1) - *it;
        if ( tmp < min_diff && tmp > 0)
            min_diff = tmp;
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
    return (*max - *min);
}

Span::~Span() {}

void Span::print()
{
    std::cout << "Vector contains:";
    if (idx < 30)
    {
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
            std::cout << ' ' << *it;
    }
    else
    {
        for (std::vector<int>::iterator it = _vec.begin(); it != _vec.begin() + 10; ++it)
            std::cout << ' ' << *it;
        std::cout << " . . . ";
        for (std::vector<int>::iterator it = _vec.end() - 10; it != _vec.end(); ++it)
            std::cout << ' ' << *it;
    }
   
    std::cout << "/END"  << std::endl;
}

/**
 * use the reserve method to preallocate memory for a certain number of elements,
 *  which avoids multiple reallocations as elements are added
 *
 */