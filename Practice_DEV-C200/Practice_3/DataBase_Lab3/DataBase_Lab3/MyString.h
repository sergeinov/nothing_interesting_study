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
	MyString(MyString&& object);		// конструктор move

	// метод получени€ значени€
	const char* GetString() const;
	// метод мен€ет строку
	void SetNewString(const char* source);

	//ѕерегрузка оператора присваивани€ =
	MyString& operator=(const MyString& otherStr);	// дл€ обьекта

	MyString& operator=(MyString&& other);		//	дл€ временного обьекта справа
	MyString& operator=(const char* str);		// дл€ строки справа "programmer"
	bool operator==(const char* str) const;

	// ѕерегрузка оператора << 
	//friend std::ostream& operator<<(std::ostream& out, const MyString& RightObject);

	//ѕерегрузка оператора +
	const MyString operator+(const MyString& RightObject);

	//ѕерегрузка оператора +=
	const MyString& operator+=(const MyString& RightObject);
};




