#pragma once
class Creature
{
protected://�ɹ����� // �Ӽ�
	string name;
	int MaxHP;
	int cur_hp;
	int atk;

public://�ɹ��Լ� // ���
	Creature(string name, int Max_hp, int afk);
	virtual ~Creature();

	void printInfo();

	virtual void Attack(Creature* other) abstract; //���������Լ�
	virtual void Damaged(int amount);

	void PreAttack(Creature* other);

	bool IsDead() { return cur_hp <= 0; }
};

