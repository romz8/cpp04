/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:21:18 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 14:29:17 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*======= Canonical Desclaration =======*/

Animal::Animal(void)
{
	this->_type = "Mammals";
	std::cout << "Animal Constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(const Animal& src)
{
	*this = src;
	std::cout << "Animal Cpy Constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << "Animal Operator = Assignment" << std::endl;
	return (*this);
}

/*======= Member Function =======*/

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string& type)
{
	this->_type = type;	
}
