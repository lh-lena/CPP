/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:43:55 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:43:57 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl ( void ) {}
Harl::~Harl ( void ) {}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << 
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n"
    << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << 
    "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n"
    << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << 
    "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n"
    << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << 
     "This is unacceptable! I want to speak to the manager now.\n"
    << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::* members_ptr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = -1;

    for (i = 0; i < 4; i++)
    {
        if (lvl[i] == level)
        {
            break ;
        }
    }

    switch (i)
    {
        case 0:
            (this->*members_ptr[0])();
        case 1:
            (this->*members_ptr[1])();
        case 2:
            (this->*members_ptr[2])();
        case 3:
            (this->*members_ptr[3])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
            break ;
    }
}
