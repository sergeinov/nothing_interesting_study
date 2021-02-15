#pragma once
class MyStackFullError
{

public:
	size_t m_size;

	MyStackFullError(int n) : m_size(n) { };
};

