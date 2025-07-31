/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:27:04 by jkarras           #+#    #+#             */
/*   Updated: 2025/07/31 13:27:07 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define MAX_VAL 5

template <class T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array( void );
		Array(unsigned int size);
		Array(const Array<T> &other);
		~Array( void );
		Array<T> &operator=(const Array<T> &other);
		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;
		unsigned int getSize( void ) const;
};

template <class T>
std::ostream &operator<<(std::ostream &stream, const Array<T> &other) {
	stream << "MY  ARRAY ->[";
	for (unsigned int i = 0; i < other.getSize(); i++) {
		stream << other[i]; 
		if (i < other.getSize() - 1) {
			stream << ", ";
		}
	}
	stream << "]\n";
	return stream;
}

template <class T>
Array<T>::Array( void ) : _array(NULL), _size(0) {

}

template <class T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {
	for (unsigned int i = 0; i < _size; i++) {
		this->_array[i] = T();
	}
}

template <class T>
Array<T>::~Array( void ) {
	delete[] (this->_array);
	this->_array = NULL;
}

template <class T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _size(other.getSize()) {
	if (_size > 0) {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		if (this->_array != NULL) {
			delete[] (this->_array);
		}
		this->_size = other.getSize();
		if (this->_size > 0) {
			this->_array = new T[this->_size];
			for (size_t i = 0; i < this->_size; i++) {
				this->_array[i] = other._array[i];
			}
		} else {
			this->_array = NULL;
		}
	}
	return (*this);
}

template <class T>
unsigned int Array<T>::getSize( void ) const {
	return (this->_size);
}

template <class T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw std::exception();
	}
	return (_array[i]);
}

template <class T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size) {
		throw std::exception();
	}
	return _array[i];
}

#endif
