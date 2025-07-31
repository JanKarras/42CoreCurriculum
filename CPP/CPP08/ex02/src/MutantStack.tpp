#include "../include/MutantStack.hpp"
template<typename T>
MutantStack<T>::MutantStack( void ) {

}

template<class T>
MutantStack<T>::~MutantStack( void ) {

}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) {
	*this = other;
}

template<class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		this->c = other.c;
	}
	return (*this);
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ) {
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ) {
	return (this->c.end());
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const {
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const {
	return (this->c.end());
}
