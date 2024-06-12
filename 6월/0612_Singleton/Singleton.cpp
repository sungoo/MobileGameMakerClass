#include <iostream>

using namespace std;

//Singleton
// 1. �������� ������ �����ؾ� �Ѵ�.
// 2. ���α׷��� �� �ϳ��� �����ؾ� �Ѵ�.
// 3. �����Ҵ� �Ǿ�� �Ѵ�.(�����͸� Data ������, ���� ��ü�� Heap��..)
//

class SoundManager {

	static SoundManager* instance;

	string warriorSound = "������ ����!!";
	string archerSound = "��ó ����!!";
private:
	SoundManager(){}
	~SoundManager(){}

public:
	//private�� ������ �� �ִ� ��� : public �ɹ��Լ�
	static void Create() {
		if(instance == nullptr)
			instance = new SoundManager();
	}
	static void Delete() {
		if (instance != nullptr)
			delete instance;
	}

	static SoundManager* GetInstance() {
		if (instance != nullptr)
			return instance;
		return nullptr;
	}

	void PrintAllSound() {
		cout << warriorSound << endl;
		cout << archerSound << endl;
	}
	void PrintWarriorSound() {
		cout << warriorSound << endl;
	}
};
SoundManager* SoundManager::instance = nullptr;

class Warrior
{
public:
	Warrior() { SoundManager::GetInstance()->PrintWarriorSound(); }
	~Warrior();

private:

};

int main() {
	SoundManager::Create();//���� ó�� �����ؼ� ���� ���߿� ����

	Warrior* warrior = new Warrior();

	delete warrior; //������ Ƚ���� ������ ���� ����
	SoundManager::Delete();

	return 0;
}