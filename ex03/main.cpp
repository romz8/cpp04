/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:56:55 by romainjober       #+#    #+#             */
/*   Updated: 2024/01/31 13:56:12 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int subject_main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

int materia_test()
{
    std::cout <<std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout<< BG_GREEN "                  MATERIA TESTING                        " RESET << std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout <<std::endl;
    std::cout << std::endl << BG_YELLOW "Test 1 : Creating MateriaSource, empty then learn" RESET << std::endl;
    MateriaSource* src = new MateriaSource();
    std::cout <<std::endl << YELLOW "displaying content (null)" RESET << std::endl;
    src->_display_templates();
    std::cout << std::endl << YELLOW "learning 2 Ice and 1 Cure materia" RESET << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->_display_templates();
    
    std::cout << std::endl << BG_YELLOW "Test 2 : Deep copy MateriaSource (with Assignment toverloader)" RESET << std::endl;
    MateriaSource copy = *src;
    std::cout << std::endl << YELLOW "Display content (same as source)" RESET << std::endl;
    copy._display_templates();
    
    std::cout << std::endl << YELLOW "adding 1 Cure in original " RESET << std::endl;
    src->learnMateria(new Cure());
    std::cout << std::endl << YELLOW "display Original " RESET << std::endl;
    src->_display_templates();
    std::cout << std::endl << YELLOW "display Copy " RESET << std::endl;
    copy._display_templates();
    
    std::cout << std::endl << YELLOW "adding 1 Ice in copy " RESET << std::endl;
    copy.learnMateria(new Ice());
    std::cout << std::endl << YELLOW "display Original " RESET << std::endl;
    src->_display_templates();
    std::cout << std::endl << YELLOW "display Copy " RESET << std::endl;
    copy._display_templates();
    
    std::cout << std::endl << BG_YELLOW "Test 3 : Creating Materia From Templates" RESET << std::endl;
    AMateria *m1 = NULL;
    AMateria *m2 = NULL;
    AMateria *m3 = NULL;
    
    m1 = src->createMateria("ice");
    if (m1)
        std::cout << "From template created materia of type: " << m1->getType() << std::endl;
    else
        std::cout << "Impossible to learn fro template, unkmown type " << std::endl;

    m2 = src->createMateria("cure");
    if (m2)
        std::cout << "From template created materia of type: " << m2->getType() << std::endl;
    else
        std::cout << "Impossible to learn fro template, unkmown type " << std::endl;

    m3 = src->createMateria("Water");
    if (m3)
        std::cout << "From template created materia of type: " << m3->getType() << std::endl;
    else
        std::cout << "Impossible to learn fro template, unkmown type " << std::endl;
    std::cout << std::endl << BG_YELLOW "Test 4 : Trying to learn too much material" RESET << std::endl;
    src->learnMateria(m1);
    src->learnMateria(m2);
    std::cout << std::endl << BG_YELLOW "Test 5 : Trying to learn NULL materia" RESET << std::endl;
    src->learnMateria(m3);
    
    std::cout << std::endl << BG_GREEN "Cleaning Memory from allocated ressources" RESET << std::endl;
    delete src;
    delete m1;
    delete m2;
    return (0);
    
}
/********************** My main() ***********************/

int main_random() {
    std::cout << "Creating MateriaSource and learning Materias..." << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\nCreating Characters..." << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    std::cout << "\nCreating and Equipping Materias to Characters..." << std::endl;
    AMateria* tmp1 = NULL;
	AMateria* tmp2 = NULL;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
	
    tmp2= src->createMateria("cure");
    me->equip(tmp2);

    std::cout << "\nUsing Materias on Characters..." << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\nTesting edge cases..." << std::endl;
    me->use(100, *bob); // Invalid index
    me->equip(NULL); // Equip null
    me->unequip(0);     // Unequip and use again
    me->use(0, *bob);

    std::cout << "\nTesting Copy Constructor and Assignment Operator for Character..." << std::endl;
    Character alice("Alice");
    alice.equip(src->createMateria("ice"));
    Character aliceClone(alice);
    aliceClone.use(0, *bob);

    Character aliceAssigned;
    aliceAssigned = alice;
    aliceAssigned.use(0, *bob);

    std::cout << "\nTesting MateriaSource Cloning..." << std::endl;
    
    std::cout << "\nCleaning up resources..." << std::endl;
  
	// deleting only the unequip materai (the on still in character equipment will be freed by character destructor so deletling them -> double free)
	if (tmp1)
		delete tmp1;
	delete bob;
    delete me;
    delete src;
	
    std::cout << "\nTests completed." << std::endl;
    return 0;
}

int main()
{
    materia_test();
    return (0);
}
