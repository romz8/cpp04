/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:54:13 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 16:08:25 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "Character.hpp"
# include "colors.h"

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria(const AMateria& src);
	AMateria& operator=(const AMateria& src);
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif