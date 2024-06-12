#include "pch.h"
#include "World.h"

World::World():
	player(nullptr),
	computer(nullptr),
	goblins(),
	MonsterLeft(CREATURE_NUM)
{
	Input();
	Init();
}

World::~World()
{
	if (player != nullptr)
		delete player;
	if (computer != nullptr)
		delete computer;
	if (goblins != nullptr) {
		for (int i = 0; i < CREATURE_NUM; i++) {
			delete goblins[i];
		}
	}
}

void World::Init()
{
}

void World::SelectPlayer(string name, int num, Creature** creature)
{
	PlayerType pClass = (PlayerType)num;
	switch (pClass)
	{
	case World::NONE:
		cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;
		break;
	case World::KNIGHT:
		*creature = new Knight(name, "Knight", 250, 40);
		break;
	case World::ARCHER:
		*creature = new Archer(name, "Archer", 300, 30);
		break;
	case World::MAGE:
		*creature = new Mage(name, "Mage", 200, 20, 50);
		break;
	case World::GOBLINE:
		*creature = new Monster(name, "Gobline", 50, 10);
		break;
	default:
		cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;
		break;
	}
}

void World::Input()
{
	int pNum = 0;
	int comNum = 0;
	int goblinNum = 4;
	string name;

	cout << "�̸� �Է� : ";
	cin >> name;
	cout << "1~3 ������ Ŭ���� �Է�\n1 . Knight\t2 . Archer\t3 . Mage : ";
	cin >> pNum;
	comNum = rand() % 3 + 1;

	SelectPlayer(name, pNum, &player);
	SelectPlayer("computer", comNum, &computer);
	for (int i = 0; i < CREATURE_NUM; i++) {
		SelectPlayer("Gobline", goblinNum, &goblins[i]);
	}
}

bool World::End()
{
	if (player->IsDead() || computer->IsDead())
		return true;
	else
		return false;
}

void World::PrintPlayerInfo()
{
	player->printInfo();
}

void World::PrintCpuInfo()
{
	computer->printInfo();
}

void World::PrintMonsterInfo(int it)
{
	cout << "--------------���---------------" << endl;
	cout << "�̸� : " << goblins[it]->getName() << endl;
	cout << "������ ü�� : " << goblins[it]->getC_hp() << endl;
	cout << "������ ���ݷ� : " << goblins[it]->getAtk() << endl;
	cout << "���� �� : " << MonsterLeft << endl;
	cout << "---------------------------------" << endl;
}

void World::Battle1()
{
	player->Attack(computer);
	if (computer->IsDead())
		return;
	computer->Attack(player);
}

void World::Battle2()
{
}

void World::MonsterLeftUpdate()
{
	int left = 0;
	for (auto g : goblins) {
		if (!g->IsDead())
			left++;
	}

	MonsterLeft = left;
}
