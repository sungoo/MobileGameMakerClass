#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, string major, int Max_hp, int afk) :
	name(name), major(major), BaseHP(Max_hp), BaseATK(afk), isActive(true)
{
	MaxHP = BaseHP;
	cur_hp = Max_hp;
	atk = BaseATK;
}

Creature::~Creature()
{
}

void Creature::Init()
{
	cur_hp = MaxHP;
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

void Creature::Damaged(int amount, Creature* attacker = nullptr)
{
	cur_hp -= amount;

	if (attacker != nullptr && dynamic_cast<Monster*>(this) != nullptr) {
		Player* p = dynamic_cast<Player*>(attacker);
		if (p != nullptr) {
			p->GainExp(_giveExp);
			p->LevelUp();
		}
	}

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

bool Creature::IsDead()
{
	return cur_hp <= 0;
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

