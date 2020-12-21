#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:

    // �����������
    MyString() { m_pStr = nullptr; };
    MyString(const char* pStr);
    // ����������
    ~MyString();

    // ���������� �����������
    MyString(const MyString& otherStr);

    // ����� ��������� ����
    // ������ � ����������� �� ����� ���� m_pStr
    const char* GetString() const { return m_pStr; };

    // ����� ������ ������
    void SetNewString(char* source);
};
