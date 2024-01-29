/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:03:27 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/29 11:57:17 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/************************** Canonical Suite ********************************/
Ice::Ice(void) : AMateria("ice")
{
	std::cout << BG_MAGENTA " Default Contructor Ice " RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << BG_MAGENTA " Default Destructor Ice " RESET << std::endl;
}

Ice::Ice(const Ice& src)
{
	this->_type = src.getType();
	std::cout << BG_MAGENTA " Copy Constructor Ice " RESET << std::endl;
	
}

Ice& Ice::operator=(const Ice& src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << BG_MAGENTA " Asignment Constructor Ice " RESET << std::endl;
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