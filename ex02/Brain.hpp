/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:46:42 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 19:57:33 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
public:
	static const int nb_ideas = 100;
	Brain();
	~Brain();
	Brain(const Brain& src);
	Brain& operator=(const Brain& src);
	std::string getIdea(int index) const;
	void	setIdea(int index, const std::string& idea);

private:
	std::string _ideas[nb_ideas];
};

#endif
