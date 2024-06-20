#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//�̵�(�̻�)
//
//

class Pet {

};

class Player {
public:
	Player() {
		cout << "�⺻ ������ ȣ��" << endl;
		pet = new Pet();
	}
	Player(int hp) {
		cout << "Ÿ�� ��ȯ ������ ȣ��" << endl;
		pet = new Pet();
	}
	Player(const Player& other) {
		cout << "���� ������ ȣ��" << endl;
		
		pet = new Pet(*other.pet);
	}

	//&& : ������ ����
	// 1. ������ ����
	// 2. �̻縦 ���
	//
	Player(Player&& other) noexcept {
		cout << "�̵������� ȣ��" << endl;
		if (pet != nullptr)
			delete pet;

		pet = other.pet;
		other.pet = nullptr;
	}

	~Player() {
		cout << "�Ҹ��� ȣ��" << endl;
		if (pet != nullptr) delete pet;
	}

	Pet* pet;
};

//������ ���۷���??
// Lvalue : ������
// => ������ �� �ִ� �� = ��򰡿� ����Ǿ��ִ�.
// == ��ǥ) ������
// 
// Rvalue : ������
// => ������ �� ���� �� = ���
// == ��ǥ) const
//

//1. Call by Value
// => ������ �ٲ��� �ʴ´�.
// ==> �Լ� ���ο��� �������� �ص� ������ ����
// �Ű������� ũ��� �ڷ����� ���� �ٸ�
//void SetPlayer(Player p) {
//
//}

//2. Call by Address
// => ������ �ٲ��
// �Ű������� ũ��� �������� ũ�⿡ ����
// ���� : ���� ��ƴ�. �߸� ���� �޸� ������ ���� �� �ִ�.
void SetPlayer(Player* const p) {
	//p + 1; ������ ������ ����
}

//3. Call by Reference
// => ������ �ٲ��
// �Ű������� ũ��� �������� ũ�⿡ ����
// ���� : ���� ���ϴ� = �޸� ���� ���ɼ��� ����.
// ���� : ���� �������� �����ް� ������ ���, ���뼺�� ����.
void SetPlayer(Player& p) {
	//p + 1; ������ ���� �Ұ���
}

//4. ������ ���� ����
// => ������ ���� ����
// �Ű������� ũ��� �������� ũ�⿡ ������..?
// - �̻�(������ �Ѽ��� �� �ִ�.)
// ������ ����ε� ������ �����ϴ�(??)
// 
void SetPlayer(Player&& p, Player&& l) {
	delete p.pet;
	p.pet = l.pet;
}

int main() {
	Player* playerB = new Player();
	Player* playerA = new Player(std::move(*playerB));
	cout << "====================================" << endl;
	unique_ptr<Player> pPtr = make_unique<Player>();
	unique_ptr<Player> pPtr2 = std::move(pPtr);//pPtr�� �ƿ� ��������, ���߿� �Ҹ��� ȣ�⵵ pPtr2�� ���� pPtr ������ �Ҹ��ڰ� ȣ���.(�ᱹ playerA, playerB, pPtr2 ��ü���� �����ϴ� ����)
	cout << "====================================" << endl;
	delete playerA;
	delete playerB;

}