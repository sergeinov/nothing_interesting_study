#pragma once

class Bochka
{
	private:
		float m_volume;
		float m_spirt;

	public:
		// �����������
		Bochka();
		Bochka(float volume, float spirt);
	
		// ����� ����������� �� ����� � �����
		void Pereliv(Bochka& bochka);

		float getSpirt();


};
