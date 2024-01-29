/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:43:49 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/29 19:11:48 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/****************************** Canonicals ***********************************/

MateriaSource::MateriaSource(void)
{
	_init_templates();
	std::cout << "MateriaSource Default Constructor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	_clear_templates();
	std::cout << "MateriaSource Default Destructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	_init_templates();
	*this = src;
	std::cout << "MateriaSource Copy Constructor" << std::endl;
	
}
MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		_clear_templates();
		for (int i = 0; i < _tmplate_size; ++i)
		{
			if (src._templates[i])
				this->_templates[i] = src._templates[i]->clone();
		}
	}
	std::cout << "MateriaSource Assignment Operator" << std::endl;
	return (*this);
}

/************* TO Implement ************/
void learnMateria(AMateria*);
AMateria* createMateria(std::string const & type);


/****** Member function ***********/
void	MateriaSource::_init_templates(void)
{
	for (int i = 0; i < _tmplate_size; ++i)
		this->_templates[i] = NULL;
}

void	MateriaSource::_clear_templates(void)
{
	for (int i = 0; i < _tmplate_size; ++i)
	{
		if (this->_templates[i] != NULL)
		{
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
	}
}