#pragma once
#include "Creature.h"
class Knight :
    public Player
{
    
public:
    Knight(string name, int hp, int afk);
    virtual ~Knight();

    // Player��(��) ���� ��ӵ�
    virtual void Attack(Creature* other) override;
};

