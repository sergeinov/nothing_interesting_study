//Прототипы используемых в данном задании функций:
int square(const int& val);		// для задания 1.5
const char* NameOfMonth(int month);
const char* DataStr(int day, int month, int year);

extern int& ref;	// обьявление внешней переменной

// для задания  2.1.
int IncByValue(int value);
int IncByReference(int& value);
int IncByPointer(int* value);


// для задания для задания  2.2
int Swap(int* nX, int* nY);
int Swap(int& nX, int& nY);