template<typename T>
void easyfind(T &container, int second) {
	typename T::iterator it = std::find(container.begin(), container.end(), second);

	if (it != container.end()) {
		std::cout << "Element found: " << *it << std::endl;
	} else {
		throw std::out_of_range("Element not found in container");
	}
}
