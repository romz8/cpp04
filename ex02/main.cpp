/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:45:48 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/26 14:32:25 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void Brain_test()
{
	std::cout << std::endl;
	std::cout << "\33[32m ============== Running Tests ====================\33[0m" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "\33[32m===================================================" << std::endl;
	std::cout << "=============creating dynamically into array =============" << std::endl;
	std::cout << " ===========================================================\33[0m" << std::endl;
	
	std::cout << "\33[33m ** Creating and filling the array ** \33[0m" << std::endl;
	Animal *array[4];
	int size = sizeof(array) / sizeof(array[0]);
	std::cout << "Array size is : " <<  size << std::endl;
	for (int i = 0; i < size; ++i)
	{	
		if (i % 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << "\33[33m ** Testing sounds ** \33[0m" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "type " << array[i]->getType() << " is : "; 
		array[i]->makeSound();
	}
	
	std::cout << std::endl;
	std::cout << "\33[32m ============== Ending Tests ====================\33[0m" << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "\t";
		std::cout << "\33[31mcleaning memory\33[0m" << std::endl;
		delete array[i];
		std::cout << "\t";
	}
	std::cout << std::endl;
}

void	Deep_copy_test(void)
{
	std::cout << "\33[32m===================================================" << std::endl;
	std::cout << "============= Running Deep copy test =============" << std::endl;
	std::cout << " ===========================================================\33[0m" << std::endl;
	Dog src_dog;
	Cat src_cat;
	src_dog.setBrain(0, "Food food food");
	src_dog.setBrain(1, "I want to bite my tail");
	src_dog.setBrain(2, "I want to play on the beach");
	src_cat.setBrain(0, "cat fooooooooood");
	src_cat.setBrain(1, "I want valerian");
	src_cat.setBrain(2, "I want to scratch all the furniture");
	
	std::cout << "\33[33m ** original thoughts ** \33[0m" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << " Source dog idea: " << src_dog.getBrain(i)  << std::endl;
		std::cout << " Source cat idea: " << src_cat.getBrain(i)  << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "\33[33m ** Making (deep) copies ** \33[0m" << std::endl;
	Dog cpy_dog(src_dog);
	Cat cpy_cat(src_cat);
	
	std::cout << "\33[33m ** thougths inside copies ** \33[0m" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << " copy dog is type: " << cpy_dog.getType() << ", its idea is : " << cpy_dog.getBrain(i)  << std::endl;
		std::cout << " copy cat is type: " << cpy_cat.getType() << ", its idea is: " << cpy_cat.getBrain(i)  << std::endl;
	}
	
	std::cout << "\33[33m ** Changing source dog & cat copies ** \33[0m" << std::endl;
	src_dog.setBrain(0, "too much croquettes");
	src_dog.setBrain(1, "I want to sleep on the couch");
	src_dog.setBrain(2, "I want to play with a human");
	src_cat.setBrain(0, "I ate too much pate");
	src_cat.setBrain(1, "I am high on valerian");
	src_cat.setBrain(2, "I want a new cat tree");
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\33[35m ** DOG source vs copy brain ** \33[0m" << std::endl;
		std::cout << " Source dog new idea: " << src_dog.getBrain(i)  << std::endl;
		std::cout << " copy dog idea: " << cpy_dog.getBrain(i)  << std::endl;
		std::cout << std::endl;
		std::cout << "\33[35m ** CAT source vs copy brain ** \33[0m" << std::endl;
		std::cout << " Source cat idea: " << src_cat.getBrain(i)  << std::endl;
		std::cout << " copy cat idea: " << cpy_cat.getBrain(i)  << std::endl;
		std::cout << std::endl;
	}
	std::cout << "\33[33m ** Changing copy dog & cat copies ** \33[0m" << std::endl;
	cpy_dog.setBrain(0, "I want to pimp my niche");
	cpy_dog.setBrain(1, "Remember to call my owner");
	cpy_dog.setBrain(2, "I am a Labrador?");
	cpy_cat.setBrain(0, "I want a golden cat tree");
	cpy_cat.setBrain(1, "I give zeor f**ck about my owner");
	cpy_cat.setBrain(2, "I used to be in God in Egypt");
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\33[35m ** DOG source vs copy brain ** \33[0m" << std::endl;
		std::cout << " Source dog idea: " << src_dog.getBrain(i)  << std::endl;
		std::cout << " copy dog new idea: " << cpy_dog.getBrain(i)  << std::endl;
		std::cout << std::endl;
		std::cout << "\33[35m ** CAT source vs copy brain ** \33[0m" << std::endl;
		std::cout << " Source cat idea: " << src_cat.getBrain(i)  << std::endl;
		std::cout << " copy cat idea: " << cpy_cat.getBrain(i)  << std::endl;
		std::cout << std::endl;
	}
}

int main()
{
	//Animal forbidden; //addedd test : should not pass the compiler
	Brain_test();
	Deep_copy_test();
	return (0);
}

