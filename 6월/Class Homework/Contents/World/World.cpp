#include "pch.h"
#include "World.h"

World::World():
	player(nullptr),
	computer(nullptr),
	goblin(nullptr),
	MonsterLeft(CREATURE_NUM)
{
	int select = Input();

	goblins.reserve(CREATURE_NUM);
	for (int i = 0; i < goblins.size(); i++) {
		Monster* monster = new Monster("Gobline", "Gobline", 50, 10);
	}

	Init();

	Run(select);
}

World::~World()
{
	if (player != nullptr)
		delete player;
	if (computer != nullptr)
		delete computer;
	if (goblin != nullptr) {
		delete goblin;
	}
	//vector�� ���� �ʱ�ȭ�Ǿ������, �� �ȿ� ��� �����͵��� ������ �� �����Ƿ�,
	//vector �Ҹ� ������ �̸� ���빰 ������Ű��
	for (int i = 0; i < goblins.size(); i++) {
		delete goblins[i];
	}
}

void World::Init()
{//�÷��̾�, ��ǻ��, ��� �ʱ�ȭ
	player->Revival();
	computer->Revival();
	for (int i = 0; i < CREATURE_NUM; i++) {
		goblins[i]->Revival();
	}
}

void World::ResetCPU()
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

int World::Input()
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

		player->printInfo();
		computer->printInfo();
		cout << "Get Ready for the Fight!" << endl << endl;

		return 1;
		break;
	case 2:
		for (int i = 0; i < CREATURE_NUM; i++) {
			SelectPlayer("Gobline", goblinNum, &goblin);
		}
		return 2;
		break;
	default:
		cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
		break;
	}
	return 0;
}

int World::End()
{
	if (player->IsDead()) 
		return 1;
	if (computer->IsDead())
		return 2;
	if (goblin->IsDead()) {
		return 3;
	}
	if (player == nullptr || computer == nullptr || goblin == nullptr)
		return -1;
		
	return 0;
}

void World::Run(int choose)
{
	while (true)
	{
		if (End() != -1)
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
		default:
			break;
		}

	}
	if (End() == 2)
		return;
	Init();
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
	/*cout << "--------------���---------------" << endl;
	cout << "�̸� : " << goblins[it]->getName() << endl;
	cout << "������ ü�� : " << goblins[it]->getC_hp() << endl;
	cout << "������ ���ݷ� : " << goblins[it]->getAtk() << endl;
	cout << "���� �� : " << MonsterLeft << endl;
	cout << "---------------------------------" << endl;*/
	goblin->printInfo();
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
	player->Attack(goblin);
	if (goblin->IsDead())
		return;
	goblin->Attack(player);
}

void World::MonsterLeftUpdate()
{
	/*int left = 0;
	for (auto g : goblins) {
		if (!g->IsDead())
			left++;
	}

	MonsterLeft = left;*/
}

bool World::GoblinsClear()
{
	if (MonsterLeft == 0)
		return true;
	return false;
}
