# Cpp Module 04

This module of 42 school’s C++ lessons explores the concepts of subtype polymorphism, abstract classes and interfaces in OOP. 

## Status

Validated on 31/01/2024. Grade: 100%

## **Ex00: Introduction to Polymorphism with class Hierarchy**

- **Key Concepts**: Basic polymorphism, class inheritance, and the use of virtual functions. This exercise introduces the concept of an animal hierarchy, where **`Cat`** and **`Dog`** classes inherit from a base **`Animal`** class.
- all classes share a `makeSound()`  function, virtualized in the base class, that displays a different sound (for each animal). It leverages polymorphism and the `main()` tests dynamic binding in upcast as reference or pointer to verify that function lookup is overriden by derived class.

## **Exercise 01: Deep Copy and Brain Class**

- **Key Concepts**: Deep copying, dynamic memory allocation, and further exploration of polymorphism. The introduction of the **`Brain`** class, which is used by **`Cat`** and **`Dog`**, emphasizes the need for deep copy constructors and assignment operators to manage dynamic memory correctly.

## **Exercise 02: Abstract Classes and Polymorphism**

- **Key Concepts**: This exercise aims to solidify understanding of polymorphism, virtual destructors, and how to properly manage resources in a polymorphic class hierarchy. also introduce the concept of pure virtual functions and abstract classes.

## **Exercise 03: Interfaces and Multiple Inheritance**

- **Key Concepts**: Introduction to interfaces in C++ through abstract classes with pure virtual functions. This exercise explores multiple inheritance and how interfaces can be used to design flexible and modular systems. It also touches on the use of concrete classes like **`Cure`** and **`Ice`** that implement the **`AMateria`** interface.
- **Interfaces and Abstract Classes**: The exercise uses interfaces (**`ICharacter`**, **`IMateriaSource`**) and abstract classes (**`AMateria`**) to define contracts for the behavior of characters and materia. This teaches the concept of interfaces in C++ and how they enforce a structure while allowing for flexibility in implementation.
    - `ICharacter.hpp` and `IMateriaSource.hpp` define interfaces for characters and materia sources.
    - `AMateria.hpp` is an abstract class that serves as a base for different types of materia, demonstrating the use of pure virtual functions to create an interface.
- **Factory Design Pattern**: The **`MateriaSource`** class implements the factory design pattern, allowing for the creation of materia objects at runtime based on their type. This pattern is crucial for scenarios where the object types to be created can vary and are not known at compile time.

## Usage

```bash
cd ex00 && make && ./polymorphism
cd ex01 && make && ./Brain
cd ex02 && make && ./Abstract
cd ex03 && make && ./Interface
```
