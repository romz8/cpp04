/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:57:14 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 17:14:14 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
private:
	std::string _type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal (const WrongAnimal& src);
	WrongAnimal& operator=(const WrongAnimal& src);
	virtual void	makeSound(void) const;
	std::string	getType(void) const;
	void	setType(const std::string& type);
};

#endif
