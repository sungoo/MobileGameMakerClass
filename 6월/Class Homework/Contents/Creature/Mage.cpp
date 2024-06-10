#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int mp, int atk):
	Player(name, hp, atk),
	mp(mp)
{
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	if (mp < 5) {
		cout << "-------------------------\n" << name << "�� ������ �����մϴ�. ������ �� �� ���ϴ�." << endl;
		mp += 50;
	}

	this->Creature::PreAttack(other);

	mp -= 5;
	other->Damaged(atk);
}
