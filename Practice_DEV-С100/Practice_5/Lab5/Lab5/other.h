//ѕрототипы используемых в данном задании функций:

// дл€ задани€ 1.5
int square(const int& val);

// дл€ задани€ 4.1
const char* NameOfMonth(int month);

// дл€ задани€ 4.2
const char* DataStr(int day, int month, int year);


// обь€вление внешней переменной  дл€ задани€ 1.2
extern int& ref;	

// дл€ задани€  2.1.
int IncByValue(int value);
int IncByReference(int& value);
int IncByPointer(int* value);


// дл€ задани€ дл€ задани€  2.2
int Swap(int* nX, int* nY);
int Swap(int& nX, int& nY);


// дл€ задани€ 3.1
void PrintArray(const int ar[], size_t size);

// дл€ задани€ 3.2
int Min(const int ar[], size_t size2);


// дл€ задани€ 3.3
int MyStrCmp(const char* arr1, const char* arr2);

//дл€ задани€ 5
int* addr_min(const int* arrMM, size_t size_MM);