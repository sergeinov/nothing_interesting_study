#include "Pair.h"

// конструкторы
Pair::Pair() {};
Pair::Pair(const char* key, const MyData& data) : key(key), data(data){ };


bool Pair::operator==(const char* key) const
{
	return this->key == key;
};


