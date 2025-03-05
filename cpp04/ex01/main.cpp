#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	// Test 1: This test verifies that the Cat copy constructor properly performs a deep copy of the brain
	std::cout << YELLOW << "\n=== Testing Deep Copy for Cat ===" << RESET << std::endl;
	Cat *original = new Cat();

	original->setIdea(0, "I want to catch a mouse");
	original->setIdea(1, "I want to sleep");

	Cat copy = Cat(*original);

	std::cout << "Original cat idea 0: " << original->getIdea(0) << std::endl;
	std::cout << "Copy cat idea 0: " << copy.getIdea(0) << std::endl;

	original->setIdea(0, "I want to eat fish");

	std::cout << "\nAfter changing original:" << std::endl;
	std::cout << "Original cat idea 0: " << original->getIdea(0) << std::endl;
	std::cout << "Copy cat idea 0: " << copy.getIdea(0) << std::endl;

	delete original;

	// Test 2: This test ensures that the Dog assignment operator creates a true deep copy
	std::cout << YELLOW << "\n=== Testing Deep Copy for Dog with Assignment ===" << RESET << std::endl;
	Dog dog1;
	dog1.setIdea(0, "I want to play fetch");
	dog1.setIdea(1, "I want to bark at mailman");

	Dog dog2;
	dog2 = dog1;

	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;

	dog1.setIdea(0, "I want to dig a hole");

	std::cout << "\nAfter changing dog1:" << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;

	// Test 3: This test validates that copies remain valid even after the original object is deleted
	std::cout << YELLOW << "\n=== Testing Memory Safety After Original Deletion ===" << RESET << std::endl;
	Cat *chatOriginal = new Cat();
	chatOriginal->setIdea(0, "Je suis le chat originel");

	Cat *chat2 = new Cat(*chatOriginal);
	Cat chat3;
	chat3 = *chatOriginal;

	std::cout << "Before deletion - Original cat idea: " << chatOriginal->getIdea(0) << std::endl;
	std::cout << "Before deletion - Chat2 idea: " << chat2->getIdea(0) << std::endl;
	std::cout << "Before deletion - Chat3 idea: " << chat3.getIdea(0) << std::endl;

	delete chatOriginal;
	std::cout << "\nAfter deletion of original:" << std::endl;
	std::cout << "Chat2 idea: " << chat2->getIdea(0) << std::endl;
	std::cout << "Chat3 idea: " << chat3.getIdea(0) << std::endl;

	delete chat2;

	// Test 4: Original array test demonstrating polymorphism with various animal types
	std::cout << YELLOW << "\n=== Original Animal Array Test ===" << RESET << std::endl;
	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	return 0;
}