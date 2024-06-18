#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, string major, int hp, int afk) :
	Player(name, major, hp, afk), critRate(0.3f)
{
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	this->Creature::PreAttack(other); //�ɹ��Լ� ȣ�� ���� : ��ü�� �׻� �־����
	int crit = rand() % 30;
	float ratio = static_cast<float>(crit) / static_cast<float>(100);

	if (ratio < critRate) {
		cout << "ũ��Ƽ��! ";
		other->Damaged(atk * 3, this);
	}
	else {
		other->Damaged(atk, this);
	}
}

void Archer::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "Ŭ���� : " << major << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
	cout << "ġ��Ÿ�� : " << critRate << endl;
	cout << "---------------------------------" << endl;
}
