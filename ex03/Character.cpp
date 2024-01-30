/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:53:06 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:13:56 by romainjober      ###   ########.fr       */
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
		if (this->_inventory[i])
			delete this->_inventory[i];
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
		return;
	for (int i = 0; i < _storage_size; ++i)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	
}
// don't forget to test for negative and Out of bond values
void Character::unequip(int idx)
{
	if (idx >= this->_storage_size || idx < 0)
		return;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= this->_storage_size || idx < 0)
		return;
	if (this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}
