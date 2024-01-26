/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:14:55 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 16:17:00 by rjobert          ###   ########.fr       */
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
}


/************************** Member Fuction ********************************/
void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an Cure bolt at " << target.getName() << " *";
	std::cout << std::endl;
}