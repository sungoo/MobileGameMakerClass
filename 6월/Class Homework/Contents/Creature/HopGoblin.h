#pragma once
#include "Monster.h"

struct DamageTable {
	//�� �� ������
	int _Damage = 0;
	//���� ������
	int _Total = 0;

	Creature* _who = nullptr;

	DamageTable(int dmg, Creature* newbe);
};
class HopGoblin :public Monster
{
	//�÷��̾ ���� ������
	vector<DamageTable*> _DamageRate;

	struct CompDamageTable {
		bool operator()(const DamageTable* a, const DamageTable* b);
	};

public:
	HopGoblin(string name, string major, int hp, int atk, int exp);
	virtual ~HopGoblin();

	//�� ���� �� ���� �÷��̾� ����
	void Attack(vector<Creature*> others);
	//�÷��̾� ���ڰ� �ҷ��� ���� �Լ�
	void SingleDamaged(int amount, Creature* attacker);
	//������ ��� ��� �� ������ ó��
	void Damaged();

	void PreAttack(vector<Creature*> others);
};

