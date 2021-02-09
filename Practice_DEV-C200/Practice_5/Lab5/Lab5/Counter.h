#pragma once
class Counter
{
private:
	Counter* pNext;					// ��������� �� ��������� Counter
	char* m_pStr;					// ��������� �� ����������� ��������� ������
	unsigned int m_nOwners;			// ������� ���������� ������

	static Counter* pHead;				// ��������� �����
	static unsigned int m_curCounters;	// ������� ����������

	friend class MyString;				// ������ � ����� ��� ������ MyString

	/*
	*	������������
	*/
	Counter(const char* p);
	~Counter();

	/*
	*	������
	*/

	void AddOwner();
	void RemoveOwner();
	static Counter* find(const char* str);

	/*
	*	����������
	*/
	
};



// !TODO
/*
�	����������� ��� ������
�	�� ���� �������� MyString �������� �������
�	������� ������ �� ��������

*/