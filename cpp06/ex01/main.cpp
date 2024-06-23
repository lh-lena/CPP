/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:14:00 by ohladkov          #+#    #+#             */
/*   Updated: 2024/06/23 12:31:30 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data originalData;

    originalData.intValue = 42;
    originalData.floatValue = 3.14f;
    originalData.strValue = "Hey there!";

    uintptr_t serializedData = Serializer::serialize(&originalData);

    Data *deserializedData = Serializer::deserialize(serializedData);

    if (deserializedData == &originalData)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "intValue: " << deserializedData->intValue << std::endl;
        std::cout << "floatValue: " << deserializedData->floatValue << std::endl;
        std::cout << "strValue: " << deserializedData->strValue << std::endl;
    }
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;

    return (0);
}