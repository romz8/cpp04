/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:11:20 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 18:21:03 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include "Cat.hpp"

/***************** Canonical Const / Dest / Copy *****************************/

WrongCat::WrongCat(void)
{
	this->setType("WrongCat");
	std::cout << "Default WrongCat Constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Default WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
	*this = src;
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
		this->setType(src.getType());
	std::cout << "WrongCat Copy Assignmeent" << std::endl;
	return (*this);
}

/**************************** Member Method *********************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "Non-Cat noises : imagine a cat-unicorn sound" << std::endl;
}
