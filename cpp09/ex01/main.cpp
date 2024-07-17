#include "RPN.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Error: invalid arguments" << std::endl, 1);

    std::string input = av[1];
    if (input.empty())
        return (std::cerr << "Error: invalid arguments" << std::endl, 2);
    RPN stack;
    std::istringstream iss(input);
    std::string el;
    while (iss)
    {
        if (iss >> el)
        {
            try
            {
                if (stack.isOperator(el) && stack.getSize() > 1)
                {
                    int rightNbr = stack.getValue();
                    stack.popValue();
                    int leftNbr = stack.getValue();
                    stack.popValue();
                    int res = stack.evaluateExpression(leftNbr, rightNbr, el[0]);
                    stack.setValue(res);
                }
                else if (!stack.isOperator(el))
                {
                    std::stringstream ss(el);
                    int value;
                    if (ss >> value)
                        stack.setValue(value);
                    else
                        throw RPN::RpnException("Error");
                }
                else
                    ;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
                return (-1);
            }
        }
    }
    std::cout <<  stack.getValue() << std::endl;
    return (0);
}
