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
	int choose = 0;
	int goblinNum = 4;
	string name;

	cin.clear();

	if (player == nullptr) {
		cout << "�̸� �Է� : ";
		cin >> name;
		cout << "1~3 ������ Ŭ���� �Է�\n1 . Knight\t2 . Archer\t3 . Mage : ";
		cin >> pNum;

		SelectPlayer(name, pNum, &player);
	}
	
	cout << "���� ���� : 1 . vs ��ǻ��\t2 . vs ��� : ";
	cin >> choose;

	switch (choose)
	{
	case 1:
		if (computer != nullptr) {
			delete computer;
			computer = nullptr;
		}
		comNum = rand() % 3 + 1;
		SelectPlayer("computer", comNum, &computer);
		Run(1);
		break;
	case 2:
		for (int i = 0; i < CREATURE_NUM; i++) {
			SelectPlayer("Gobline", goblinNum, &goblins[i]);
		}
		Run(2);
		break;
	default:
		cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
		break;
	}
}

int World::End()
{
	if (player->IsDead()) 
		return 1;
	if (computer->IsDead())
		return 2;
	if (GoblinsClear())
		return 3;
	return 0;
}

void World::Run(int choose)
{
	while (true)
	{
		if (End() != 0)
			break;
		//choose�� ���� Battle While ������
		switch (choose)
		{
		case 1://vs CPU
			Battle1();
			break;
		case 2://vs Goblins
			Battle2();
			break;
		}
	}
	if (End() == 2)
		return;
	player->Revival();
	computer->Revival();
	Input();
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

bool World::GoblinsClear()
{
	if (MonsterLeft == 0)
		return true;
	return false;
}
