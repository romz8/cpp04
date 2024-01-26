/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:38:44 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 10:59:20 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_canide_brain;

public:
	Dog();
	~Dog();
	Dog (const Dog& src);
	Dog& operator=(const Dog& src);
	void	makeSound(void) const;
	void	setBrain(int index, std::string idea);
	std::string	getBrain(int index) const;
};

#endif
