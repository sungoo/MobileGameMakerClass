#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) :Player(), _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	//if (_pet != nullptr)
	//	delete _pet;
}

