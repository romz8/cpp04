/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:53:44 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 11:36:33 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*======= Canonical Desclaration =======*/

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Brain Cpy Constructor" << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			this->setIdea(i, src.getIdea(i));
	}
	std::cout << "Brain Operator = Assignment" << std::endl;
	return (*this);
}

/*======= Member Function =======*/

std::string	Brain::getIdea(int index) const
{
	if (index < Brain::nb_ideas && index >= 0)
		return (this->_ideas[index]);
	else
		return("idea index out of bonds - target brain is smaller");
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index < Brain::nb_ideas && index >= 0 )
		this->_ideas[index] = idea;
}

