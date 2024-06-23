/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:52:51 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 12:32:36 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    // Prevent instantiation by making constructors private
    Serializer( void );
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

#endif // SERIALIZER_H