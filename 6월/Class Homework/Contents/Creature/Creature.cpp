#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, string major, int Max_hp, int afk) :
	name(name), major(major), MaxHP(Max_hp), atk(afk)
{
	cur_hp = Max_hp;
}

Creature::~Creature()
{
}

void Creature::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "Ŭ���� : " << major << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "---------------------------------" << endl;
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

void Creature::Revival()
{
	cur_hp = MaxHP;
}

string Creature::getName()
{
	return name;
}

string Creature::getMajor()
{
	return major;
}

int Creature::getM_hp()
{
	return MaxHP;
}

int Creature::getC_hp()
{
	return cur_hp;
}

int Creature::getAtk()
{
	return atk;
}

