#pragma once

class Bochka
{
	private:
		float m_volume;
		float m_spirt;

	public:
		// конструктор
		Bochka();
		Bochka(float volume, float spirt);
	
		// метод переливания из бочки в бочку
		void Pereliv(Bochka& bochka);

		float getSpirt();


};
