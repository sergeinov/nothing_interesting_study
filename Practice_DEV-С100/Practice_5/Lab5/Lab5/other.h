//��������� ������������ � ������ ������� �������:
int square(const int& val);		// ��� ������� 1.5
const char* NameOfMonth(int month);
const char* DataStr(int day, int month, int year);

extern int& ref;	// ���������� ������� ����������

// ��� �������  2.1.
int IncByValue(int value);
int IncByReference(int& value);
int IncByPointer(int* value);


// ��� ������� ��� �������  2.2
int Swap(int* nX, int* nY);
int Swap(int& nX, int& nY);