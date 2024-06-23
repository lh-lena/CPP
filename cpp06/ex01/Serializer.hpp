/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:52:51 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 11:52:51 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>
# include "Data.h"

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& src);
    ~Serializer();
};

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

#endif // SERIALIZER_H