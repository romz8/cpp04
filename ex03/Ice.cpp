/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:03:27 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:15:02 by romainjober      ###   ########.fr       */
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
