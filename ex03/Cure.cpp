/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:14:55 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:14:40 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/************************** Canonical Suite ********************************/
Cure::Cure(void) : AMateria("cure")
{
	std::cout << BG_GREEN " Default Contructor Cure " RESET << std::endl;
}

Cure::~Cure(void)
{
	std::cout << BG_GREEN " Default Destructor Cure " RESET << std::endl;
}

Cure::Cure(const Cure& src)
{
	this->_type = src.getType();
	std::cout << BG_GREEN " Copy Constructor Cure " RESET << std::endl;
	
}

Cure& Cure::operator=(const Cure& src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << BG_GREEN " Asignment Constructor Cure " RESET << std::endl;
	return (*this);
}


/************************** Member Fuction ********************************/
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
	std::cout << std::endl;
}

AMateria* Cure::clone(void) const
{
	std::cout << "Cloning Cure object" << std::endl;
	return (new Cure());
}
