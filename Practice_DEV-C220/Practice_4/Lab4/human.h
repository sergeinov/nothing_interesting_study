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
	human(const human& human) = delete;						// конструктор копирования // копировать нельзя
	human(human&& other)									//  перемещать можно
	{
		this->m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	human& operator=(const human& other) = delete;			// оператор присваивания	// присваивать нельзя
	human& operator=(human&& other)							// перемещать можно 
	{
		
		return *this;
	}


	static void childP();
};

