/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:45:48 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/25 18:19:49 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int subject_main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}

void Wrong_test()
{
	std::cout << std::endl;
	std::cout << "\33[32m***** Running Tests of Wrong Classes****\33[0m" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\33[33mtesting wronganimal as WrongAnimal\33[0m" << std::endl;
	{
		WrongAnimal unicorn;
		std::cout << unicorn.getType() << std::endl;
		unicorn.makeSound();
	}
	std::cout << std::endl;
	std::cout << "\33[33mtesting wrongcat as WrongCat\33[0m" << std::endl;
	{
		WrongCat	tiger;
		std::cout << tiger.getType() << std::endl;
		tiger.makeSound();
	}
	std::cout << std::endl;
	std::cout << "\33[33mtesting wrongcat as WrongAnimal : Reference upcast\33[0m" << std::endl;
	{
		WrongCat	unicat;
		WrongAnimal& uniger = unicat;
		std::cout << uniger.getType() << std::endl;
		uniger.makeSound();
	}
	std::cout << std::endl;
	std::cout << "\33[33mtesting wrongcat as WrongAnimal: Pointer upcast\33[0m" << std::endl;
	{
		WrongCat	unicat;
		WrongAnimal* uniger = &unicat;
		std::cout << uniger->getType() << std::endl;
		uniger->makeSound();
	}
}

int main()
{
	std::cout << std::endl;
	std::cout << "\33[32m***** Running subject's main ****\33[0m" << std::endl;
	std::cout << std::endl;
	subject_main();
	Wrong_test();
	return (0);
}

