#pragma once
#define CREATURE_NUM 10

class World
{
	Creature* player;
	Creature* computer;
	//���߿� ���� ������ ���� ����� ó���ϴ� Ŭ������ ����°� ������..
	Creature* goblins;
	int MonsterLeft;

public:
	enum PlayerType {
		NONE,
		KNIGHT,
		ARCHER,
		MAGE,
		GOBLINE,
	};

	World();
	~World();
	//���� ���� : ���� ������ / ���� ���Կ�����
	//���� ���� �ʿ�
	//World(const World& other);
	//World& operator=(const World& other);

	void Init();

private:
	void SelectPlayer(string name, int num, Creature** creature);
	void Input();
public:
	int End();
	void Run(int choose);

	void PrintPlayerInfo();
	void PrintCpuInfo();
	void PrintMonsterInfo(int it);

	void Battle1();
	void Battle2();//����

	void MonsterLeftUpdate();
	bool GoblinsClear();
};

