#pragma once

class Bochka
{
private:
	double m_volume;
	double m_spirt;

public:
	// конструктор
	Bochka() { m_volume = 0; m_spirt = 0; };
	Bochka(double volume, double spirt)
	{
		m_volume = volume;
		m_spirt = spirt;
	};
	
	// метод переливания из бочки в бочку
	void Pereliv(double& content, double& volume);



	double getSpirt()
	{
		return m_spirt;
	};
	double getVolume()
	{
		return m_volume;
	};


};
