#include "Counter.h"
#include <iomanip>

/*
*	����������� ����������
*/
Counter*  pHead = nullptr;
unsigned int m_curCounters = 0;

/*
*	������������
*/
Counter::Counter(const char* p) : m_nOwners(1)
{
	this->m_pStr = new char[strlen(p) + 1];
	strcpy(this->m_pStr, p);					// �������� 

	//�������� � ������
	
};


Counter::~Counter()
{
	delete[] m_pStr;	// ������� ��������� ������ 

	//��������� �� ������

};

/*
*	������
*/
void Counter::AddOwner()	// ��������� ���������
{
	m_nOwners++;
	//m_curCounters++;
};
void Counter::RemoveOwner()	// ������� ���������
{
	m_nOwners--;
	//m_curCounters--;
	if (m_nOwners == 0)
	{
		delete this;		// �������� ����������� �������� ~Counter()
	}
}
Counter* Counter::find(const char* str)		// ��� ������  ������� ������
{
	Counter* p = pHead;		// ��������� �� ������ ������
	while ( p != nullptr )
	{
		if ( !strcmp(str, p->m_pStr) )
		{
			p->m_nOwners++;				// ���� ������� ������ , ���������� ���������
			return p;					// ���������� �����
		}
		p = p->pNext;					// ����������� �� ��������� ������
	}
	return new Counter(str);	// ���� �� ����� ������� �����, ����� �����������
}
;

/*
*	����������
*/