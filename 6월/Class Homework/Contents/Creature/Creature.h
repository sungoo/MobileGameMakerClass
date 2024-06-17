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

public://�ɹ��Լ� // ���
	Creature(string name, string major, int Max_hp, int afk);
	virtual ~Creature();

	virtual void printInfo();

	virtual void Attack(Creature* other) abstract; //���������Լ�
	virtual void Damaged(int amount);

	void PreAttack(Creature* other);

	bool IsDead() { return cur_hp <= 0; }
	virtual void Revival();

	string getName();
	string getMajor();
	int getM_hp();
	int getC_hp();
	int getAtk();
};

