#include "Archer.h"

Archer::Archer()
{
	// �̷� ���� ���� ä�� ����~
	if(_pet == nullptr)
		_pet = new Pet();
}

Archer::Archer(int hp) : Player(hp)
{
	// �̷� ���� ���� ä�� ����~
	if (_pet == nullptr)
		_pet = new Pet();
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	if (_pet != nullptr)
		delete _pet;
}

