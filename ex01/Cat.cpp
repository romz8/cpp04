/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:22:21 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 16:31:50 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/***************** Canonical Const / Dest / Copy *****************************/

Cat::Cat(void)
{
	this->setType("Cat");
	this->_feline_brain = new Brain;
	std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_feline_brain;
	std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat& src)
{
	this->_type = src.getType();
	if (src._feline_brain)
		this->_feline_brain = new Brain(*src._feline_brain);
	else
		this->_feline_brain = NULL;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		if (src._feline_brain)
			delete this->_feline_brain;
		if (src._feline_brain)
			this->_feline_brain = new Brain(*src._feline_brain);
		else
			this->_feline_brain = NULL;
	}
	std::cout << "Cat Copy Assignmeent" << std::endl;
	return (*this);
}

/**************************** Member Method *********************************/

void	Cat::makeSound(void) const
{
	std::cout << "Felinae sound - meoooow meooooow" << std::endl;
}

void	Cat::setBrain(int index, std::string idea)
{
	if (this->_feline_brain)
		this->_feline_brain->setIdea(index, idea);
}

std::string	Cat::getBrain(int index) const
{
	if(this->_feline_brain == NULL)
		return("Empty Brain");
	return (this->_feline_brain->getIdea(index));
}
