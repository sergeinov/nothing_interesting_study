#pragma once

class MyString
{
private:
	char* m_pName;
public:
	//конструкторы
	MyString();
	MyString(const char* pName);
	// деструктор
	~MyString();

	// конструктор копировани€
	MyString(const MyString& otherStr);

	// метод получени€ значени€
	const char* GetString() const;
	// метод мен€ет строку
	void SetNewString(const char* source);

	//ѕерегрузка оператора присваивани€ =
	MyString& operator=(const MyString& otherStr);

	// ѕерегрузка оператора << 
	//friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);

	//ѕерегрузка оператора +
	const MyString& operator+(const MyString& RightObject);

	//ѕерегрузка оператора +=
	const MyString& operator+=(const MyString& RightObject);
};




