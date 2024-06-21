#include "pch.h"
#include "World.h"

World::World():
	player(nullptr),
	computer(nullptr),
	MonsterLeft(CREATURE_NUM)
{
	//make cpu object
	ResetCPU();

	//make goblins object
	goblins.reserve(CREATURE_NUM);
	for (int i = 0; i < CREATURE_NUM; i++) {
		Monster* monster = new Goblin("Gobline", "Gobline", 50, 10, 10);
		goblins.push_back(monster);
	}

	//make player object
	int select = Input();

	//rivival all
	Init();

	Run(select);
}

World::~World()
{
	if (player != nullptr)
		delete player;
	if (computer != nullptr)
		delete computer;
	//vector�� ���� �ʱ�ȭ�Ǿ������, �� �ȿ� ��� �����͵��� ������ �� �����Ƿ�,
	//vector �Ҹ� ������ �̸� ���빰 ������Ű��
	for (int i = 0; i < goblins.size(); i++) {
		delete goblins[i];
	}
}

void World::Init()
{//�÷��̾�, ��ǻ��, ��� �ʱ�ȭ
	if(player != nullptr)
		player->Revival();
	if(computer != nullptr)
		computer->Revival();

	for (int i = 0; i < CREATURE_NUM; i++) {
		if(goblins[i] != nullptr)
			goblins[i]->Revival();
	}
	MonsterLeftUpdate();
}

void World::ResetCPU()
{
	int comNum = 0;

	if (computer != nullptr) {
		delete computer;
		computer = nullptr;
	}
	comNum = rand() % 3 + 1;
	SelectPlayer("computer", comNum, &computer);
}

void World::SelectPlayer(string name, int num, Creature** creature)
{
	PlayerType pClass = (PlayerType)num;
	switch (pClass)
	{
	case World::NONE:
		cout << "��ü ������ ������ �߻��߽��ϴ�." << endl;
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
	default:
		cout << "��ü ������ ������ �߻��߽��ϴ�." << endl;
		break;
	}
}

int World::Input()
{
	int pNum = 0;
	int choose = 0;
	string name;

	cin.clear();

	if (player == nullptr) {
		cout << "�̸� �Է� : ";
		cin >> name;
		cout << "1~3 ������ Ŭ���� �Է�\n1 . Knight\t2 . Archer\t3 . Mage : ";
		cin >> pNum;

		SelectPlayer(name, pNum, &player);
	}

	ResetCPU();
	
	cout << "���� ���� : 1 . vs ��ǻ��\t2 . vs ��� : ";
	cin >> choose;

	switch (choose)
	{
	case 1:
	case 2:
		break;
	default:
		cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
		return 0;
		break;
	}
	cout << "Get Ready for the Fight!" << endl << endl;
	return choose;
}

int World::End()
{
	if (player->IsDead()) 
		return 1;
	if (computer->IsDead())
		return 2;
	if (GoblinsClear()) {
		return 3;
	}
	if (player == nullptr || computer == nullptr)
		return -1;
		
	return 0;
}

void World::Run(int choose)
{
	if (End() == -1)
		return;
	//choose�� ���� Battle While ������
	switch (choose)
	{
	case 1://vs CPU
			player->printInfo();
			computer->printInfo();
		while (!player->IsDead() && !computer->IsDead())
		{
			Battle1();
		}
		break;
	case 2://vs Goblins
			player->printInfo();
		while (!player->IsDead() && !GoblinsClear())
		{
			PrintMonsterInfo(MonsterLeft - 1);
			Battle2();
		}
		break;
	default:
		break;
	}
	if (End() == 2)
		return;

	Init();

	int newChoose = Input();

	Run(newChoose);
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
	if (goblins[it] == nullptr)
		return;
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
	int target = MonsterLeft - 1;
	player->Attack(goblins[target]);
	if (goblins[target]->IsDead()) {
		target--;
		MonsterLeftUpdate();
		if (target < 0)
			return;
	}
	goblins[target]->Attack(player);
}

void World::MonsterLeftUpdate()
{
	int left = 10;
	for (auto g : goblins) {
		if (g->IsDead())
			left--;
	}

	MonsterLeft = left;
}

bool World::GoblinsClear()
{
	if (MonsterLeft == 0)
		return true;
	return false;
}
