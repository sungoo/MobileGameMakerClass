#include <iostream>

using namespace std;

//ĳ����

//C��Ÿ�� ĳ����
//�⺻�ڷ��� ĳ���� (����!)

//C++ ��Ÿ�� ĳ����(4�ѻ�)
//1. Static Cast
//=> ������� ��ȯ�� ���
//=> ������ �ð��� ĳ����

//2. Dynamic Cast
// => ��� �������� ������(vftable)�� �־�� ��� ����
// => ĳ������ �����ϸ� nullptr�� ��ȯ�Ѵ�.
// => ��Ÿ�� �� ĳ����

//3. Const Cast
// => �����ü�� ������ü�� ĳ����

//4. Reinterpret Cast
// => ��� ����ȯ�� ���
//

class Player {
public:
	virtual void PrintPlayer() { cout << "Player�Դϴ�." << endl; }
};
class Knight :public Player {
public:
	virtual void PrintPlayer() { cout << "Knight�Դϴ�." << endl; }
};
class Mage :public Player {
public:
	virtual void PrintPlayer() { cout << "Mage�Դϴ�." << endl; }
	int mana;
};

void ManaUp(Player* player) {
	Mage* mage = dynamic_cast<Mage*>(player);

	if (mage == nullptr) {
		cout << "Mage�� �ƴմϴ�." << endl;
		return;
	}

	mage->PrintPlayer();
	cout << "�ִ� ������ �����߽��ϴ�!" << endl;
}

//pkt : 17kb/s (�ʴ� ��Ŷ ���۷�), fps 140
enum PacketID {
	NONE = 0,
	LOG_IN,
	LOG_SUCCESS,
	CREATE_ACCOUNT,
	PLAYER_RUN,
};

struct Protocol_test_S {//Server�� ������
	PacketID pid = PacketID::LOG_IN;
	int id;
	int password;
};
struct Protocol_test_C {//Client�� ������
	PacketID pid = PacketID::LOG_SUCCESS;
	bool succeed;
};

int main() {
	int aint = 5;
	float afloat = static_cast<float>(aint); // 16���� => �ε��Ҽ���
	bool abool = (bool)aint;
	//int* aptr = (int*)aint; //...aptr == 5

	Player* player1 = new Knight();
	//int* aptr = static_cast<int*>(player);
	//int* aptr = reinterpret_cast<int*>(player);
	Player* player2 = new Mage();

	ManaUp(player1);
	ManaUp(player2);

	//���ͷ� ���
	//char* str1 = "Hello"; //rodata

	//Data ����
	//- bss		: �ʱ�ȭ���� ���� ��������
	//- data	: �ʱ�ȭ�� ��������
	//- rodata	: ���

	char* str1 = const_cast<char*>("Hello"); //����� �Ǵµ�, ������ �Ұ�.
	str1[1] = 'z';

	//Ŭ���̾�Ʈ �α��� �õ�
	Protocol_test_S pkt;
	pkt.pid = PacketID::LOG_IN;
	pkt.id = 12345;
	pkt.password = 12345;

	//�������� �α��� üũ �� �������� ����
	Protocol_test_S* s_pkt = reinterpret_cast<Protocol_test_S*>(&pkt);

	//Ŭ���̾�Ʈ���� �α��� ��������
}