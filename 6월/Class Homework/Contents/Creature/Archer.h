#pragma once
#include "Creature.h"
class Archer :
    public Player
{

public:
    Archer(string name, int hp, int afk);
    virtual ~Archer();

    // Player��(��) ���� ��ӵ�
    virtual void Attack(Creature* other) override;
};

