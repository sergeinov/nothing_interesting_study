#include "myBochka.h"

//�����������
Bochka::Bochka() { m_volume = 0; m_spirt = 0; };

Bochka::Bochka(float volume, float spirt)
{
	m_volume = volume;
	m_spirt = spirt;
};

void Bochka::Pereliv(Bochka& bochka)
{

	m_spirt = (m_spirt * m_volume + bochka.m_spirt) / (m_volume + 1);  // ��������� ������� ������� ������

	m_volume = m_volume + 1;						// �������� � ������

	bochka.m_volume = bochka.m_volume - 1;        //����������� �� ������ �����
};

float Bochka::getSpirt()
{
	return m_spirt;
};
