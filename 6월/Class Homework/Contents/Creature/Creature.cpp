#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int afk) :
	name(name), cur_hp(hp), atk(afk)
{
}

Creature::~Creature()
{
}

void Creature::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
}

void Creature::Damaged(int amount)
{
	cur_hp -= amount;

	cout << name << "���� " << amount << "������!!" << endl;

	if (cur_hp < 0)
		cur_hp = 0;

	printInfo();

	if (IsDead()) {
		cout << name << "�� ����߽��ϴ�." << endl;
	}
}

void Creature::PreAttack(Creature* other)
{
	cout << name << "�� " << other->name << "���� ������ �õ��մϴ�." << endl;
}

