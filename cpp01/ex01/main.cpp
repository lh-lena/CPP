/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:29:35 by ohladkov          #+#    #+#             */
/*   Updated: 2024/05/10 12:29:48 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Miki");
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
