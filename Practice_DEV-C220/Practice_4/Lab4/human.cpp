#include "human.h"

std::string human::getName() const
{
	return this->name;
}

std::string human::setName(std::string str)
{
	this->name = str;
	return this->name;
}

std::shared_ptr<human> human::childCreate(std::string name, std::shared_ptr<human > m, std::shared_ptr<human > d)
{
	auto temp = std::make_shared<human>(name);
	if ( m )
	{
		temp->mam = m;
		m->child.push_back(temp);
	}
	if ( true )
	{

	}

	return temp;
}

void human::PrintP(std::shared_ptr<human> value)
{


}
