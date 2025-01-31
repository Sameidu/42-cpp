#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Dog* puppy= new Dog();
	Cat* kitty = new Cat();
	std::ostringstream oss;

	for (int i = 0; i < 100; i++)
	{
		oss.str("");
		oss << (i + 1);
		kitty->getBrain()->setIdea(i, "Idea " + oss.str());
		puppy->getBrain()->setIdea(i, "Idea " + oss.str());
		std::cout << "Kitty: " << kitty->getBrain()->getIdea(i) << std::endl;
		std::cout << "Puppy: " << puppy->getBrain()->getIdea(i) << std::endl;
	}

	delete puppy;
	delete kitty;

	Animal *animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}