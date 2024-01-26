/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 12:07:34 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->setType("Dog");
	std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog& src)
{
	*this = src;
	std::cout << "Dog Cpy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
		this->setType(src.getType());
	std::cout << "Dog Operator = Assignment" << std::endl;
	return (*this);
}

/*======= Member Function =======*/

void	Dog::makeSound(void) const
{
	std::cout << "Bark  - wouf wouf" << std::endl;
}
