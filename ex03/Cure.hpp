/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:11 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 16:14:02 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	~Cure(void);
	Cure(const Ice& src);
	Cure& operator=(const Ice& src);
	void use(ICharacter& target);
};

#endif