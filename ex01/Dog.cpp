/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:43:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 16:31:57 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->setType("Dog");
	this->_canide_brain = new Brain;
	std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_canide_brain;
	std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog& src)
{
	this->_type = src.getType();
	if (src._canide_brain)
		this->_canide_brain = new Brain(*src._canide_brain); //we need to intantiande a brain * in the class dog, using the Brain constructor 
	else
		this->_canide_brain = NULL;
	std::cout << "Dog Cpy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		this->_type = src.getType();
		if (this->_canide_brain)
			delete this->_canide_brain;
		if (src._canide_brain)
			this->_canide_brain = new Brain(*src._canide_brain);
		else
			this->_canide_brain = NULL;
	}
	std::cout << "Dog Operator = Assignment" << std::endl;
	return (*this);
}

/*======= Member Function =======*/

void	Dog::makeSound(void) const
{
	std::cout << "Bark  - wouf wouf" << std::endl;
}

void	Dog::setBrain(int index, std::string idea)
{
	if (this->_canide_brain)
		this->_canide_brain->setIdea(index, idea);
}

std::string	Dog::getBrain(int index) const
{
	if (this->_canide_brain == NULL)
		return ("Empty Brain");
	return (this->_canide_brain->getIdea(index));
}
