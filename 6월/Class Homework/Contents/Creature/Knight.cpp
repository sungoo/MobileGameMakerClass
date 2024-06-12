#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, string major, int hp, int afk):
Player(name, major, hp, afk), furi(false)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	this->Creature::PreAttack(other);
	float ratio = (float)cur_hp / (float)MaxHP;

	if (ratio < 0.5f)
		furi = true;
	else
		furi = false;

	if (furi) {
		//���� ü�� 50% �̸�
		other->Damaged(atk * 2);
	}
	else {
		other->Damaged(atk);
	}
}

void Knight::printInfo()
{
	cout << "--------------����---------------" << endl;
	cout << "�̸� : " << name << endl;
	cout << "Ŭ���� : " << major << endl;
	cout << "ü�� : " << cur_hp << endl;
	cout << "���ݷ� : " << atk << endl;
	if (furi) cout << "������ ���!" << endl;
	cout << "---------------------------------" << endl;
}
