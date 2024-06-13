#include <iostream>

using namespace std;

//Functor = Func + Actor
//�Լ���ü
//��ü�̰�, �Լ�ó�� �� �� �ִ� ��ü
// ()�Լ� �����ڸ� �����ε��ؼ� �� �� ����.
// �ݹ鰳������ �� �� �ִ�.
// [�Լ� �����Ϳ��� ������]
// = �Ӽ�(�ɹ�����)�� ���� �� �ִ�.
//
struct Functor {//struct ����, �⺻ ���������ڰ� public�̶� ���̰� ���� ��, ��ü��.

	int _aInt;
	int _bInt;

	Functor():_aInt(3), _bInt(5)
	{
		cout << "Functor ����" << endl;
	}

	//������ �����ε�
	void operator()() {//() : �Լ� ������
		cout << "HelloWorld" << endl;
		cout << _aInt + _bInt << endl;
	}
	//�Ű����� �޴� ����
	void operator()(int number) {
		cout << number << endl;
	}
};

class Player {

	Functor* _functor;

public:
	void Excute() {
		if (_functor != nullptr)
			(*_functor)();
	}

	void SetFunctor(Functor* functor) {
		_functor = functor;
	}
};



int main() {
	Functor functor;

	functor();
	functor(1);

	functor._aInt = 9;
	functor._bInt = 10;
	functor();
}