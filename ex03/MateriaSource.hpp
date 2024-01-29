/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:54:12 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/29 18:53:45 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public MateriaSource
{
private:
	static const int _tmplate_size = 4;
	AMateria *_templates[_tmplate_size];
	void	_init_templates(void);
	void	_clear_templates(void);
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& src);
	MateriaSource& operator=(const MateriaSource& src);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif