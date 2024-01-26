/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:55:59 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 15:44:56 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	virtual ~Animal();
	Animal (const Animal& src);
	Animal& operator=(const Animal& src);
	virtual void	makeSound(void) const;
	std::string	getType(void) const;
	void	setType(const std::string& type);
};

#endif
