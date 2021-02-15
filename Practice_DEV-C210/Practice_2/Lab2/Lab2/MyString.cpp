#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include"MyString.h"

/*
*   конструкторы
*/
MyString::MyString() : m_pStr(nullptr) { };

MyString::MyString(const char* Str)
{
    if ( Str )
    {
        int size = strlen(Str) + 1;
        m_pStr = new char[ size ];
        memcpy(m_pStr, Str, size);
        //strcpy(m_pName, pName);
    }
    else
    {
        Str = nullptr;
    }
};

MyString::~MyString()                           // деструктор
{
    delete[] m_pStr;
};

MyString::MyString(const MyString& otherStr)    // коструктор копирования
{
    if ( otherStr.m_pStr )
    {
        this->m_pStr = new char[ strlen(otherStr.m_pStr) + 1 ];
        strcpy(this->m_pStr, otherStr.m_pStr);
    }
    else
    {
        this->m_pStr = nullptr;
    }
};

MyString::MyString(MyString&& otherStr)         // конструктор перемещения move
{
    this->m_pStr = otherStr.m_pStr;
    otherStr.m_pStr = nullptr;
};

/*
*   перегрузки
*/
MyString& MyString::operator=(const MyString& otherStr)     //Перегрузка оператора копирования
{
    if ( this != &otherStr )                       // проверка для самоприсваивания
    {
        delete[] this->m_pStr;                      // освобождаем предидущий блок памяти
        if ( otherStr.m_pStr )
        {
            this->m_pStr = new char[ strlen(otherStr.m_pStr) + 1 ];   // выделяем память
            strcpy(this->m_pStr, otherStr.m_pStr);                  // копируем
        }
        else
        {
            this->m_pStr = nullptr;
        }
    }
    return *this;                               // для обеспечения цепочечного присваивания возвращаем по ссылке адрес объекта
}

MyString& MyString::operator=(MyString&& otherStr)
{
    if ( this != &otherStr )
    {
        delete[] this->m_pStr;
        m_pStr = otherStr.m_pStr;
        otherStr.m_pStr = nullptr;
    }
    return *this;
}


/*
*   методы
*/
