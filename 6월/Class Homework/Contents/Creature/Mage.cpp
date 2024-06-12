#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, string major, int hp, int mp, int atk):
	Player(name, major, hp, atk),
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

void Mage::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "Ŭ���� : " << major << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << mp << endl;
	cout << "---------------------------------" << endl;
}
