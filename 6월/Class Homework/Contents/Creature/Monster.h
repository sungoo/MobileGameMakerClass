#pragma once
#include "Creature.h"
class Monster :public Creature
{
public:
    Monster(string name, string major, int hp, int afk);
    Monster(string name, string major, int hp, int atk, int exp);
    virtual ~Monster();

    // Creature��(��) ���� ��ӵ�
    virtual void Attack(Creature* other) override;
};

