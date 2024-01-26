/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:13:55 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 11:02:14 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_feline_brain;

public:
	Cat();
	~Cat();
	Cat (const Cat& src);
	Cat& operator=(const Cat& src);
	void	makeSound(void) const;
	void	setBrain(int index, std::string idea);
	std::string	getBrain(int index) const;
};

#endif
