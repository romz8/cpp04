/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:22:21 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 12:34:53 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/***************** Canonical Const / Dest / Copy *****************************/

Cat::Cat(void)
{
	this->setType("Cat");
	std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat& src)
{
	*this = src;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	if (this != &src)
		this->setType(src.getType());
	std::cout << "Cat Copy Assignmeent" << std::endl;
	return (*this);
}

/**************************** Member Method *********************************/

void	Cat::makeSound(void) const
{
	std::cout << "Felinae sound - meoooow meooooow" << std::endl;
}
