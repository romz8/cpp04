/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:43:49 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:38:37 by romainjober      ###   ########.fr       */
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

/*********************** Factory Pattern *********************************/

/*
Memory Management : Careful here on how we handle src if no space left, 
should we delete or transfer ownership of memory to main ? subject is unclear
*/
void MateriaSource::learnMateria(AMateria* src)
{
	bool clone_complete = false;

	if (!src)
		return ;
	for (int i = 0; i < _tmplate_size; ++i)
	{
		if(this->_templates[i] == NULL)
		{
			this->_templates[i] = src;
			clone_complete = true;
			break ;
		}
	}
	if (clone_complete != true)
		std::cout << "Impossible to learn a new Materia, MateriaSource Class is full" << std::endl;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _tmplate_size; ++i)
	{
		if (this->_templates[i])
			if (this->_templates[i]->getType() == type)
				return (this->_templates[i]->clone());
	}
	return (0);
}


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
