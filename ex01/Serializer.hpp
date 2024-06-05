#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();
	public:
	static uintptr_t serialize(Data *data);
	static Data* deserialize(uintptr_t raw);
};

#endif
