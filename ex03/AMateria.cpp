/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:42 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:13:42 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/************************** Canonical Suite *********************************/
AMateria::AMateria(void)
{
	std::cout << BG_CYAN " Default Contructor AMateria " RESET << std::endl;
}
AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << BG_CYAN " Parametized Contructor AMateria on type: " << this->getType();
	std::cout << RESET << std::endl;
}
AMateria::~AMateria(void)
{
	std::cout << BG_CYAN " Default Destructor AMateria " RESET << std::endl;
}
AMateria::AMateria(const AMateria& src)
{
	this->_type = src.getType();
	std::cout << BG_CYAN " Copay Contructor AMateria " RESET << std::endl;
}
AMateria& AMateria::operator=(const AMateria& src)
{
	if (this != &src)
		this->_type = src.getType();
	std::cout << BG_CYAN " Assignment Operator AMateria " RESET << std::endl;
	return (*this);
}
	
/******************** Mber function and Pure Virutal Fnction *****************/

std::string const & AMateria::getType() const
{
	return(this->_type);
} 


void AMateria::use(ICharacter& target)
{
	std::cout << RED " AMateria is BEING USED ON: " RESET << target.getName() << std::endl;	
}
