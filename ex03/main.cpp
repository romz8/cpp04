/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:56:55 by romainjober       #+#    #+#             */
/*   Updated: 2024/01/31 16:30:04 by rjobert          ###   ########.fr       */
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
    std::cout << std::endl << YELLOW "Display content (same type as source / different pointer)" RESET << std::endl;
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

int character_test()
{
    std::cout <<std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout<< BG_GREEN "                CHARACTER TESTING                        " RESET << std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout <<std::endl;
    std::cout << std::endl << BG_YELLOW "Creating Materia" RESET << std::endl;
    AMateria *s1, *s2;
    s1 = new Ice();
    s2 = new Cure();
    
    std::cout << std::endl << YELLOW "Creating and filling a MateriaSrouce" RESET << std::endl;
    MateriaSource src;
    src.learnMateria(s1);
    src.learnMateria(s2);
    
    std::cout << std::endl << YELLOW "Display MateriaSrouce" RESET << std::endl;
    
    src._display_templates();
    std::cout << std::endl << BG_YELLOW "TEST 1 : creating a Character and use inventory" RESET << std::endl;
    
    std::cout << std::endl << YELLOW "Create bob, with empty inventory (default constructor)" RESET << std::endl;
    Character *Bob = new Character("Bob");
    Bob->_display_inventory();
    
    std::cout << std::endl << YELLOW "now equip Bob with 2 materia from the materia source (ice and cure) - same pointers" RESET << std::endl;
    Bob->equip(s1);
    Bob->equip(s2);
    Bob->_display_inventory();
    
    std::cout << std::endl << YELLOW "now we unequip Bob in those 2 slots, empty inventory" RESET << std::endl;
    std::cout << YELLOW "we do these because memory ownership is in MateriaSource and not Character" RESET << std::endl;
    std::cout << YELLOW "we would have a double free if we keep it here (both destructor would delete it)" RESET << std::endl;
    Bob->unequip(0);
    Bob->unequip(1);
    Bob->_display_inventory();

    std::cout << std::endl << YELLOW "create 2 materia out of the factory" RESET << std::endl;
    AMateria *m1 = src.createMateria("ice");
    AMateria *m2 = src.createMateria("cure");
    
    std::cout << std::endl << YELLOW "now we equip Bob with these materia - same type but different pointers" RESET << std::endl;
    Bob->equip(m1);
    Bob->equip(m2);
    Bob->_display_inventory();
    
    std::cout << std::endl << BG_YELLOW "TEST 2 : Deep Copy - Assignment overloader " RESET << std::endl;
    Character *copy = new Character();
    *copy = *Bob;
    std::cout << std::endl << YELLOW "displaying source character inventory" RESET << std::endl;
    Bob->_display_inventory();
    std::cout << std::endl << YELLOW "displaying copy character inventory - same type but different pointers" RESET << std::endl;
    copy->_display_inventory();
    std::cout << std::endl << YELLOW "now deleting copy" RESET << std::endl;
    delete copy;
    
    std::cout << std::endl << BG_YELLOW "TEST 3 : Equip / Unequip edge cases" RESET << std::endl;
    Bob->unequip(0);
    Bob->unequip(1);
    Bob->equip(s1);
    Bob->equip(s2);
    Bob->equip(m1);
    Bob->equip(m2);
    Bob->_display_inventory();
    std::cout << std::endl << YELLOW "adding NULL" RESET << std::endl;
    Bob->equip(NULL);
    std::cout << std::endl << YELLOW "Testing incorrrect index (1000, -1, 4)" RESET << std::endl;
    Bob->unequip(10000);
    Bob->unequip(-1);
    Bob->unequip(5);
    std::cout << std::endl << YELLOW "Testing use incorrect index 100" RESET << std::endl;
    Bob->use(100, *Bob);
    std::cout << std::endl << YELLOW "Testing Unequip slot 0 and use after" RESET << std::endl;
    Bob->unequip(0);
    Bob->use(0, *Bob);
    
    std::cout << std::endl << BG_GREEN "Cleaning Memory from allocated ressources" RESET << std::endl;
    Bob->unequip(0);
    Bob->unequip(1);
    delete Bob;
    
    return (0);
}

int fight_club()
{
    std::cout <<std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout<< BG_GREEN "                FIGHT CLUB TESTING                       " RESET << std::endl;
    std::cout<< GREEN "************************************************************" RESET << std::endl;
    std::cout <<std::endl;
    std::cout << std::endl << BG_YELLOW "Creating Materia" RESET << std::endl;
    AMateria *s1, *s2, *m1, *m2;
    s1 = new Ice();
    s2 = new Cure();

    MateriaSource src;
    src.learnMateria(s1);
    src.learnMateria(s2);
    m1 = src.createMateria("ice");
    m2 = src.createMateria("cure");
    src.learnMateria(m1);
    src.learnMateria(m2);
    src._display_templates();
    std::cout << std::endl << BG_YELLOW "Creating 2 Fighters" RESET << std::endl;
    Character tyler("Tyler");
    Character durden("Durden");
    std::cout << std::endl << BG_YELLOW "Equipping the 2 Fighters" RESET << std::endl;
    tyler.equip(s1);
    tyler.equip(s2);
    tyler.equip(m1);
    tyler.equip(m2);
    durden.equip(m2);
    durden.equip(m1);
    durden.equip(s2);
    durden.equip(s1);
    tyler._display_inventory();
    durden._display_inventory();
    std::cout <<std::endl;
    std::cout << std::endl << BG_YELLOW "           FIGHT TIME          " RESET << std::endl;
    std::cout <<std::endl;
    tyler.use(0, durden);
    durden.use(0, durden);
    durden.use(1, tyler);
    tyler.use(1, tyler);
    durden.use(3, tyler);
    tyler.use(3, durden);
    
    std::cout << std::endl << BG_YELLOW "FIGHT is over, remeber the first rule of the fight club" RESET << std::endl;
    std::cout << std::endl << YELLOW "Unequipping fighers, and we don't talk about the fight club" RESET << std::endl;
    
    for (int i = 0; i < 4; ++i)
    {
        tyler.unequip(i);
        durden.unequip(i);
    }
    return (0);
}


int main()
{
    materia_test();
    character_test();
    fight_club();
    return (0);
}
