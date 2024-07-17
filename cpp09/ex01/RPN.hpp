#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>

class RPN
{
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    class RpnException : public std::exception
    {
        public:
            RpnException(const std::string &message);
            const char *what() const throw();
            ~RpnException() throw();
        private:
            std::string _msg;
    };

    void    setValue(int value);
    int     getValue( void );
    int     getSize( void );
    void    popValue( void );
    bool    isOperator(const std::string &token);
    int     evaluateExpression(int leftNbr, int RightNbr, char tocken);
private:
    std::stack<int> _rpn;
};

#endif