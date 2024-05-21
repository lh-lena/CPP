/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:15:10 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/21 19:15:11 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	nbrOfIdeas = 100;
	ideas = new std::string[nbrOfIdeas];
	for (int i = 0; i < nbrOfIdeas; i++) {
        ideas[i] = "Default Idea";
    }
	std::cout << "Default Brain constructor called" << std::endl; 
}

Brain::Brain( const Brain & src )
{
	this->nbrOfIdeas = src.nbrOfIdeas;
	this->ideas = new std::string[this->nbrOfIdeas];
	for (int i = 0; i < this->nbrOfIdeas; i++) {
		this->ideas[i] = src.ideas[i];
	}
    std::cout << "Brain copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Brain destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		this->nbrOfIdeas = rhs.nbrOfIdeas;
		delete [] ideas;
		this->ideas = new std::string[this->nbrOfIdeas];
		ideas = new std::string[this->nbrOfIdeas];
		for (int i = 0; i < this->nbrOfIdeas; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
        std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & i )
{
	for (int n = 0; n < i.nbrOfIdeas; n++) {
		o << i.getIdea(n) << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Brain::setIdea(int index, const std::string & idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string		Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	else
		return ("");
}

/* ************************************************************************** */