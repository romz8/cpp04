/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:13:55 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 12:15:18 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat (const Cat& src);
	Cat& operator=(const Cat& src);
	void	makeSound(void) const;
};

#endif
