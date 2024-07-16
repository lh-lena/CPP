/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:58:50 by ohladkov          #+#    #+#             */
/*   Updated: 2024/07/16 14:55:39 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

/**
 * https://cplusplus.com/reference/stack/stack/
 * https://stackoverflow.com/questions/75093686/how-to-make-a-c-stack-container-iterable
*/
#endif