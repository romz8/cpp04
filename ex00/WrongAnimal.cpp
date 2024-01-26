/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:55:39 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 17:20:41 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/************** Canonical Cstor, Dstor, Cpy *********************************/


WrongAnimal::WrongAnimal(void): _type("Unicorn Monster")
{
	std::cout << "Default WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Default WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& src)
{
	*this = src;
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	return (*this);
}

/******************* Member Method ***************************************/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Making a strong noise" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(const std::string& type)
{
	this->_type = type;	
}
