#include "Counter.h"
#include <iomanip>

/*
*	������������
*/
Counter::Counter(const char* p) : m_nOwners(1)
{
	this->m_pStr = new char[strlen(p) + 1];
	strcpy(this->m_pStr, p);					// �������� 
};

Counter::~Counter()
{
	delete[] m_pStr;	// ������� ��������� ������
};

/*
*	������
*/
void Counter::AddOwner()	// ��������� ���������
{
	m_nOwners++;
};
void Counter::RemoveOwner()	// ������� ���������
{
	m_nOwners--;
	if (m_nOwners == 0)
	{
		delete this;		// �������� ����������� ��������
	}
};

/*
*	����������
*/