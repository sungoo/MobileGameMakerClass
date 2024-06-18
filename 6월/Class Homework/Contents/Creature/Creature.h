#pragma once
class Creature
{
protected://�ɹ����� // �Ӽ�
	string name;
	string major;
	int BaseHP;//���� 1�� �⺻��
	int MaxHP;
	int cur_hp;
	int BaseATK;//���� 1�� �⺻��
	int atk;
	int _giveExp = 10;
	bool isActive;

public://�ɹ��Լ� // ���
	Creature(string name, string major, int Max_hp, int afk);
	virtual ~Creature();

	virtual void Init();

	virtual void printInfo();

	virtual void Attack(Creature* other) abstract; //���������Լ�
	virtual void Damaged(int amount, Creature* attacker = nullptr);

	void PreAttack(Creature* other);

	bool IsDead();
	virtual void Revival();

	string getName();
	string getMajor();
	int getM_hp();
	int getC_hp();
	int getAtk();
};

