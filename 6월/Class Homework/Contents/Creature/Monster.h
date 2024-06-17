#pragma once
#include "Creature.h"
class Monster :public Creature
{
    int _exp = 10;
public:
    Monster(string name, string major, int hp, int afk);
    Monster(string name, string major, int hp, int atk, int exp);
    virtual ~Monster();

    int GetEXP();

    // Creature��(��) ���� ��ӵ�
    virtual void Attack(Creature* other) override;
};

