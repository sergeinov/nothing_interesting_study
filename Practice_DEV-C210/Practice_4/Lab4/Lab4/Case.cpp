#include "Case.h"
#include<string>

bool Case::operator()(const char* first, const char* second) const
{
	/*char simbol = *first;
	char simbol2 = *second;

	return ( simbol < simbol2 );*/

	return strcmp(first, second) < 0;
}
