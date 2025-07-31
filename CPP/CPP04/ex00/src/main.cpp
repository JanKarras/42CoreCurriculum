#include "../include/Dog.h"
#include "../include/Cat.h"
#include "../include/WrongAnimal.h"
#include "../include/WrongCat.h"

int main() {
	std::cout << "=== Correct Polymorphism ===\n";
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;
	std::cout << "\n=== Incorrect Polymorphism ===\n";
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	// Falscher Polymorphismus: Ruft die Methode der Basisklasse auf
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
