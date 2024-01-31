/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:03:27 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/31 13:26:27 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/************************** Canonical Suite ********************************/
Ice::Ice(void) : AMateria("ice")
{
	std::cout << MAGENTA " Default Contructor Ice " RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << MAGENTA " Default Destructor Ice " RESET << std::endl;
}

Ice::Ice(const Ice& src)
{
	this->_type = src.getType();
	std::cout << MAGENTA " Copy Constructor Ice " RESET << std::endl;
	
}

Ice& Ice::operator=(const Ice& src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << MAGENTA " Asignment Constructor Ice " RESET << std::endl;
	return (*this);
}


/************************** Member Fuction ********************************/
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}

AMateria* Ice::clone(void) const
{
	std::cout << "Cloning Ice object" << std::endl;
	return (new Ice());
}
