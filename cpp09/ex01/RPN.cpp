#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _rpn = other._rpn;
    }
    return (*this);
}

/*
** --------------------------------- EXCEPTION -------------------------------
*/

RPN::RpnException::RpnException(const std::string &message) : _msg(message) {};

const char *RPN::RpnException::what() const throw()
{
    return (_msg.c_str());
}

RPN::RpnException::~RpnException() throw() {};

/*
** --------------------------------- METHODS ----------------------------------
*/

bool    RPN::isOperator(const std::string& token)
{
    std::string op = "+-*/";
    if (op.find(token) == std::string::npos)
        return (false);
    return (true);
}


int RPN::evaluateExpression(int leftNbr, int RightNbr, char tocken)
{
    switch (tocken)
    {
    case '+':
        return (leftNbr + RightNbr);
    case '-':
        return (leftNbr - RightNbr);
    case '*':
        return (leftNbr * RightNbr);
    case '/':
        return (leftNbr / RightNbr);
    default:
        throw RPN::RpnException("Error: unexpected operator");
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int RPN::getValue( void )
{
    return (_rpn.top());
}

int RPN::getSize( void )
{
    return (_rpn.size());
}

void RPN::setValue(int value)
{
    _rpn.push(value);
}

void RPN::popValue( void )
{
    _rpn.pop();
}
