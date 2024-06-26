/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:00:57 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/28 19:00:58 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "iter.hpp"

int main()
{
    int i[] = {1, 2, 3, 4, 5};
    iter(i, 5, printElement<int>);

    std::string c[] = {"Hi", "there", "!"};
    iter(c, 3, printElement<std::string>);

    float f[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f};
    iter(f, 5, printElement<float>);

    return (0);
}