
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include"MyString.h"

// конструкторы
MyString::MyString()
{
    m_pName = nullptr;
};
MyString::MyString(const char* pName)
{
    m_pName = new char[strlen(pName) + 1];
    strcpy(m_pName, pName);
};

// деструктор
MyString::~MyString()
{
    delete[] m_pName;
}

// коструктор копирования
MyString::MyString(const MyString& otherStr)
{
    if (otherStr.m_pName)
    {
        // выделяем память под строку m_pStr и копируем  в нее параметр конструктора pStr
        m_pName = new char[strlen(otherStr.m_pName) + 1];
        strcpy(m_pName, otherStr.m_pName);
    }
    else
    {
        m_pName = 0;
    }
};

// метод получения значения
const char* MyString::GetString() const
{
    // проверка на пустой указатель
    if (!this)
    {
        return "NULL...";
    }

    if (m_pName)
    {
        return m_pName;
    }
    else
    {
        return "empty...";
    }
};

// метод меняет строку
void MyString::SetNewString(const char* source)
{
    delete[] m_pName;
    m_pName = new char[strlen(source) + 1];
    strcpy(m_pName, source);

}

//Перегрузка оператора присваивания =
MyString& MyString::operator=(const MyString& otherStr)
{
    if (this != &otherStr)                       // проверка для самоприсваивания
    {
        delete[] this->m_pName;                  // освобождаем предидущий блок памяти
        m_pName = new char[strlen(otherStr.m_pName) + 1];   // выделяем память
        strcpy(m_pName, otherStr.m_pName);      // копируем
    }
    return *this;                               // для обеспечения цепочечного присваивания возвращаем по ссылке адрес объекта
};

//Перегрузка оператора +
const MyString& MyString::operator+(const MyString& RightObject)
{
    if (RightObject.m_pName)
    {
        strcat(this->m_pName, RightObject.m_pName);      // конкатенация строк
    }
    return *this;
};

//Перегрузка оператора +=
const MyString& MyString::operator+=(const MyString& RightObject)
{
    int size = 0;

    if (RightObject.m_pName)
    {
        size = strlen(RightObject.m_pName) + strlen(this->m_pName) + 1;     // память для двух строк
        char* temp = new char[size];            // выделяем память на временную переменную

        // проверка на пустой объект левого операнда
        if (m_pName)
        {
            strcpy(temp, this->m_pName);            // копируем во временную
        }

        strcat(temp, RightObject.m_pName);      // конкатенация строк
        delete[] this->m_pName;                 // освобождаем предидущий блок памяти
        this->m_pName = temp;                         // присваиваем указатель временной на основную
    }
    return *this;
};