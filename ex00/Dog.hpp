/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:38:44 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 12:07:26 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog (const Dog& src);
	Dog& operator=(const Dog& src);
	void	makeSound(void) const;
};

#endif
