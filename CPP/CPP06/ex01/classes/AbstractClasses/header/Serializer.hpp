#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include "../../../include/libs.hpp"
#include "../../DataClasses/header/Data.hpp"

class Data;

class Serializer {
	private:
		Serializer( void );
	public:
		virtual ~Serializer( void );
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
