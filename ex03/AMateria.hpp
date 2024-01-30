/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:54:13 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/30 18:07:20 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
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
