#include <iostream>

using namespace std;

class Pet {

};

class Player {
public :
	//������ : �⺻������ , Ÿ�Ժ�ȯ ������

	//�⺻������
	Player() : 
		//�����ʱ�ȭ ����. ���⼱ ��� �ʱ�ȭ ����
		hp(0), 
		maxhp(150), 
		hpRef(hp),
		target(nullptr),
		pet(nullptr)
	{
		hp = maxhp;
		pet = new Pet();
		cout << "�⺻������ ȣ��" << endl;
	}

	//Ÿ�Ժ�ȯ ������
	Player(int hp) :
		hp(hp),
		maxhp(150),
		hpRef(hp),
		target(nullptr),
		pet(nullptr)
	{
		hp = maxhp;
		pet = new Pet();
		cout << "Ÿ�Ժ�ȯ ������ ȣ��" << endl;
	}

	//���������
	//�Ϲ������� ������ִ� ������ // ��������� ����� �� ������� // �Ϲ������� ����� : �������� ShallowCopy
	//�Ϲ������� ������� ��, ��� ��������� �����Ѵ�.
	Player(const Player& other)
		: maxhp(other.maxhp),
		hp(other.hp),
		hpRef(other.hpRef),
		target(other.target),
		pet(nullptr)
	{
		hp = maxhp;
		pet = new Pet(*other.pet);//DeepCopy ���� ����
		cout << "��������� ȣ��" << endl;
	}

	~Player(){
		delete pet;
	}

	void SetTarget(Player* other) {
		target = other;
	}
	void Attack() {
		cout << "����!" << endl;
		target->hp -= 10;
	}

private:
	//�⺻�ڷ���
	int hp;
	
	const int maxhp;
	int& hpRef;//����
	Player* target;
	Pet* pet; //4 bite
};

int main() {
	Player a = Player();//�⺻������ ȣ��
	Player b = Player(5);//Ÿ�Ժ�ȯ ������ ȣ��
	Player c = 2;//Ÿ�Ժ�ȯ������ ȣ��
	Player d = Player(c);//��������� ȣ��

	cout << endl;

	Player* mPlayer = new Player();//�⺻������
	Player* bPlayer = new Player(5);//Ÿ�Ժ�ȯ������
	Player* cPlayer = new Player(2);//Ÿ�Ժ�ȯ������
	Player* dPlayer = new Player(*cPlayer);//���������  //*cPlayer : ����������. ������ �İ���. �ᱹ�� cPlayer�� ����Ű�� new Player(2)

	Player* a_p = new Player();
	Player* b_p = new Player(*a_p);

	delete a_p;
	delete b_p;

	delete dPlayer;
	delete cPlayer;
	delete bPlayer;
	delete mPlayer;
}