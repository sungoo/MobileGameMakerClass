#pragma once
#include "Creature.h"
class Monster :
    public Creature
{
public:
    Monster(string name, int hp, int afk);
    virtual ~Monster();

    // Creature��(��) ���� ��ӵ�
    virtual void Attack(Creature* other) override;
};

