#include <iostream>
#include <vector>
#include <sstream>

bool is_sorted(const std::vector<int>& arr) {
    // Überprüft, ob das Array in aufsteigender Reihenfolge sortiert ist
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false; // Rückgabe false, wenn eine Zahl kleiner als die vorherige ist
        }
    }
    return true; // Wenn keine Fehler gefunden wurden, Rückgabe true
}

int main() {
    std::string line;
    std::vector<int> numbers;
	
    while (std::getline(std::cin, line)) {
        std::istringstream stream(line);
        int num;
        while (stream >> num) {
            numbers.push_back(num); // Füge jede Zahl zum Vector hinzu
        }
    }

    // Überprüft, ob das Array korrekt sortiert ist
    if (is_sorted(numbers)) {
        std::cout << "Die Zahlen sind korrekt sortiert!" << std::endl;
    } else {
        std::cout << "Die Zahlen sind NICHT korrekt sortiert!" << std::endl;
    }

    return 0;
}
