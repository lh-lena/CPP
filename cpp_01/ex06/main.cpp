/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:45:50 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:45:56 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int av, char **ac)
{
    if (av != 2)
        return (std::cout << "use DEBUG, INFO, WARNING or ERROR as parameter" << std::endl, 1);
    Harl harl;

    harl.complain(ac[1]);
    
    return 0;
}
