#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int afk) :
	Player(name, hp, afk)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	this->Creature::PreAttack(other); //�ɹ��Լ� ȣ�� ���� : ��ü�� �׻� �־����
	int crit = rand() % 10;
	float ratio = crit / (float)100;

	if (ratio < 0.3f) {
		cout << "ũ��Ƽ��! ";
		other->Damaged(atk * 3);
	}
	else {
		other->Damaged(atk);
	}
}
