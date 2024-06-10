#pragma once
class World
{
	Creature* player;
	Creature* computer;

public:
	enum PlayerType {
		NONE,
		KNIGHT,
		ARCHER,
		MAGE,
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
	bool End();

	void Battle1();
	void Battle2();//����
};

