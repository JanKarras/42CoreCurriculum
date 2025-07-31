#include "../include/Array.hpp"


void printIntArray(int *arr) {
	std::cout << "STD ARRAY ->[";
	for (size_t i = 0; i < MAX_VAL - 1; i++){
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[MAX_VAL - 1];
	std::cout << "]\n";
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << numbers;
	printIntArray(mirror);
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	std::cout << numbers;
	printIntArray(mirror);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
	std::cout << numbers;
    delete [] mirror;//
    return 0;
}
