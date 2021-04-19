#pragma once
#include<memory>
#include<iostream>
#include <vector>


class human
{
	std::shared_ptr<human > mam;
	std::shared_ptr<human > dad;
	std::vector<std::weak_ptr<human >> child;
	std::string name;
public:
	human() = default;
	human(std::string& name) : name(name) { };
	human(const human& human) = delete;						// ����������� ����������� // ���������� ������
	human(human&& other)									//  ���������� �����
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	human& operator=(const human& other) = delete;			// �������� ������������	// ����������� ������
	human& operator=(human&& other)							// ���������� ����� 
	{
		
		return *this;
	}


	static void childP();
};

