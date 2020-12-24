#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������

    public:
    // �����������
    MyString();
    MyString(const char* pStr);
    // ����������
    ~MyString();

    // ���������� �����������
    MyString(const MyString& otherStr);

    // ����� ��������� ����
    // ������ � ����������� �� ����� ���� m_pStr
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

    // ����� ������ ������
    void SetNewString(const char* source);
};
