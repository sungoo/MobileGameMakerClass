#include <iostream>

using namespace std;

//Template
// Class
// => ��ü(�ǹ�)�� ���� ���赵
// => Template... �� ���赵�� ���� Ʋ
//

//�Լ� ���ø� : �Լ� ����
//���ø� �⺻����
template<class T = int>
T Add(T a, T b) {
	T c = a + b;

	return c;
}
//���ø��� Ư��ȭ
template<>
double Add(double a, double b) {
	double c = a + b;
	cout << "Double" << endl;

	return c;
}

//Ŭ���� ���ø� �⺻����
template <typename T>
class Player {
public:
	T _hp;
	int _mp;

	T GetHP() {
		return _hp;
	}
	void SetHP(const T& hp) {
		_hp = hp;
	}
};

//Ŭ���� ���ø� Ư��ȭ
template<>
class Player<double> {
public:
	double _hp;
};

int main() {
	double c = Add(1.2, 2.5);
	cout << c << endl;

	Player<int> player;
	Player<double> player2;

	return 0;
}