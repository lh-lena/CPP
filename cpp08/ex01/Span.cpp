#include "Span.hpp"

Span::Span(unsigned int n) : _nSize(n), idx(0) {
    _arr = new int[_nSize];
    this->idx = 0;
}

Span::Span(const Span & src) : _nSize(src._nSize), idx(src.idx) {
    *this = src;
}

Span & Span::operator=(const Span & src)
{
    if (&src != this)
    {
        _nSize = src._nSize;
        delete[] _arr;
        for (int i = 0; i < _nSize; i++)
            _arr[i] = src._arr[i];
    }
    return (*this);
}

Span::SpanException::SpanException(const std::string & msg) : _msg(msg) {}

const char *Span::SpanException::what() const throw()
{
    return (_msg.c_str());
}

void    Span::addNumber(int n)
{
    if (idx == _nSize)
        throw (SpanException("Reached max of elements"));
    _arr[idx++] = n;
}


int     Span::shortestSpan()
{

}
int     Span::longestSpan()
{
    
}

Span::~Span()
{
    delete [] _arr;
}

