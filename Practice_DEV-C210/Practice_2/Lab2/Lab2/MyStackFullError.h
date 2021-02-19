#pragma once
class MyStackFullError
{
	size_t m_size;
public:
	MyStackFullError(int n) : m_size(n) { };
	size_t GetSize() const { return m_size; };
};

