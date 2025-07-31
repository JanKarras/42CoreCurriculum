#include "../include/Dog.h"
#include "../include/Cat.h"

int main() {
const size_t arraySize = 10;
const size_t halfSize = arraySize / 2;
const Animal* animals[arraySize];
// Fill the array: first half with Dogs, second half with Cats
for (size_t i = 0; i < halfSize; ++i) {
    animals[i] = new Dog();
}
for (size_t i = halfSize; i < arraySize; ++i) {
    animals[i] = new Cat();
}
// Test the sounds
for (size_t i = 0; i < arraySize; ++i) {
    animals[i]->makeSound();
}
// Delete the animals
for (size_t i = 0; i < arraySize; ++i) {
    delete animals[i];
}
// Deep copy test
// Test
Dog dog1;
dog1.setIdea("search for food", 0);
dog1.setIdea("search for pee", 1);
dog1.setIdea("search for bone", 2);
Dog dog2 = dog1;  // Kopieren durch Konstruktor

std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
std::cout << "dog1 idea: " << dog1.getIdea(1) << std::endl;
std::cout << "dog2 idea: " << dog2.getIdea(1) << std::endl;
std::cout << "dog1 idea: " << dog1.getIdea(2) << std::endl;
std::cout << "dog2 idea: " << dog2.getIdea(2) << std::endl;

// Änderung an dog1 und Überprüfung, ob dog2 unberührt bleibt
dog1.setIdea("Woof", 0);
std::cout << "dog1 idea after modification: " << dog1.getIdea(0) << std::endl;
std::cout << "dog2 idea after dog1 modification: " << dog2.getIdea(0) << std::endl;

return 0;
}
