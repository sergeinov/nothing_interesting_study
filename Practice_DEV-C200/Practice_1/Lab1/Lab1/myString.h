#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:

    // конструктор
    MyString() { m_pStr = nullptr; };
    MyString(const char* pStr);
    // деструктор
    ~MyString();

    // коструктор копирования
    MyString(const MyString& otherStr);

    // метод получения поля
    // почему в определении не видит поле m_pStr
    const char* GetString() const { return m_pStr; };

    // метод меняет строку
    void SetNewString(char* source);
};
