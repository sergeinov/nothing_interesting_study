#include "Base.h"

// ������������
Base::Base() : count(0), capacity(2), pBase(new Pair[2]) {}; 
Base::~Base() { delete[] pBase; };


