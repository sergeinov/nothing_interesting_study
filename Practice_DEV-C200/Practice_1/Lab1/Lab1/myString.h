#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса

    public:
    // конструктор
    MyString();
    MyString(const char* pStr);
    // деструктор
    ~MyString();

    // коструктор копирования
    MyString(const MyString& otherStr);

    // метод получения поля
    // почему в определении не видит поле m_pStr
    inline const char* GetString() const
    {
        if (m_pStr)
        {
            return m_pStr;
        }
        else
        {
            return "empty...";
        }
    };

    // метод меняет строку
    void SetNewString(const char* source);
};
