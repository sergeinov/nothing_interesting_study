//��������� ������������ � ������ ������� �������:

// ��� ������� 1.5
int square(const int& val);

// ��� ������� 4.1
const char* NameOfMonth(int month);

// ��� ������� 4.2
const char* DataStr(int day, int month, int year);


// ���������� ������� ����������  ��� ������� 1.2
extern int& ref;	

// ��� �������  2.1.
int IncByValue(int value);
int IncByReference(int& value);
int IncByPointer(int* value);


// ��� ������� ��� �������  2.2
int Swap(int* nX, int* nY);
int Swap(int& nX, int& nY);


// ��� ������� 3.1
void PrintArray(const int ar[], size_t size);

// ��� ������� 3.2
int Min(const int ar[], size_t size2);


// ��� ������� 3.3
int MyStrCmp(const char* arr1, const char* arr2);

//��� ������� 5
int* addr_min(const int* arrMM, size_t size_MM);