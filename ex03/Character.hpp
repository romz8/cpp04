/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:59:15 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/31 14:36:54 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Ice.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static const int _storage_size = 4;
	std::string	_name;
	AMateria	*_inventory[_storage_size];

public:
	Character();
	Character(const std::string& name);
	~Character();
	Character(const Character& src);
	Character& operator=(const Character& src);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void _display_inventory(void);
};

#endif
