#include "Case.h"

bool Case::operator()(const char* first, const char* second)
{
	char simbol = *first;
	char simbol2 = *second;

	return ( simbol < simbol2 );
}
