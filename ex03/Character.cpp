/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:53:06 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/31 15:54:38 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void)
{
	for (int i = 0; i < _storage_size; ++i)
		this->_inventory[i] = NULL;
	this->_name = "Nameless";
	std::cout << BG_YELLOW "Default Character Constructor" RESET << std::endl;
}	

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i <_storage_size; ++i)
		this->_inventory[i] = NULL;
	std::cout << BG_YELLOW "Parametized (name) Character Constructor" RESET << std::endl;
}


Character::~Character(void)
{
	for (int i = 0; i < _storage_size; ++i)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << BG_YELLOW "Default Character Destructor" RESET << std::endl;
}

Character::Character(const Character& src) : _name(src._name)
{
	for (int i = 0; i < _storage_size; ++i)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << BG_YELLOW "Character Copy Constructor" RESET << std::endl;
}
Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < _storage_size; ++i)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}
	
std::string const & Character::getName(void) const
{
	return (this->_name);
}
void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << RED "Cannot add NULL material to inventory" RESET << std::endl;
		return;
	}
	for (int i = 0; i < _storage_size; ++i)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << RED "Cannot add - Inventory full" RESET << std::endl;
	
}
// don't forget to test for negative and Out of bond values
void Character::unequip(int idx)
{
	if (idx >= this->_storage_size || idx < 0)
	{
		std::cout << RED "Index Out of Range" RESET << std::endl;
		return;
	}
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= this->_storage_size || idx < 0)
	{
		std::cout << RED "Index Out of Range" RESET << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << RED "Cannot use - empty / NULL material" RESET << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

void Character::_display_inventory(void)
{
	std::cout << "Character " << this->getName() << " has in inventory : ";
	std::cout << std::endl;
	for (int i = 0; i < _storage_size; ++i)
	{
		if (this->_inventory[i] != NULL)
			std::cout << "slot [" << i << "]  is : " << this->_inventory[i] << " of type: " << this->_inventory[i]->getType();
		else
			std::cout << "slot [" << i << "]  is : empty/ NULL";
		std::cout << std::endl;
	}
}
