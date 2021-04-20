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
	human(const std::string& name) : name(name) { };

	human(const human& human) = delete;						// конструктор копирования // копировать нельзя
	human(human&& other) = delete;							//  конструктор перемещения

	human& operator=(const human& other) = delete;			// оператор присваивания	// присваивать нельзя
	human& operator=(human&& other)	= delete;				// конструктор


	std::string getName() const;
	std::string setName(std::string str);

	static std::shared_ptr<human> childCreate(std::string name, std::shared_ptr<human > m = nullptr, std::shared_ptr<human > d = nullptr);
	static void PrintP(std::shared_ptr<human > value);
};

