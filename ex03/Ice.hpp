/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:00:37 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/29 11:57:28 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	~Ice(void);
	Ice(const Ice& src);
	Ice& operator=(const Ice& src);
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif
