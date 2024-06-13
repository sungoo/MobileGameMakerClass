#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, string major, int hp, int mp, int atk):
	Player(name, major, hp, atk),
	MaxMP(mp)
{
	cur_mp = MaxMP;
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	if (cur_mp < 5) {
		cout << "-------------------------\n" << name << "�� ������ �����մϴ�. ������ �� �� ���ϴ�." << endl;
		cur_mp += 50;
	}

	this->Creature::PreAttack(other);

	cur_mp -= 5;
	other->Damaged(atk);
}

void Mage::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "Ŭ���� : " << major << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "���� : " << cur_mp << endl;
	cout << "---------------------------------" << endl;
}

void Mage::Revival()
{
	cur_hp = MaxHP;
	cur_mp = MaxMP;
}
