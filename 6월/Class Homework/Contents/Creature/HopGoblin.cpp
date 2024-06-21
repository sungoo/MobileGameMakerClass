#include "pch.h"
#include "HopGoblin.h"

HopGoblin::HopGoblin(string name, string major, int hp, int atk, int exp):
	Monster(name, major, hp, atk, exp)
{
	_DamageRate.reserve(10);

	//_DamageRate.resize(10, nullptr);
}

HopGoblin::~HopGoblin()
{
	for (int i = 0; i < _DamageRate.size(); i++) {
		if (_DamageRate[i] != nullptr)
			delete _DamageRate[i];
	}
}

void HopGoblin::Attack(vector<Creature*> others)
{

}

void HopGoblin::SingleDamaged(int amount, Creature* attacker)
{
	//���� ��ȸ�Ͽ� �÷��̾� ���� Ž��
	for (auto it : _DamageRate) {
		if (it->_who == attacker) {
			//���� �÷��̾� ������ �̹� ���� �� => damage ����
			it->_Damage = amount;
			it->_Total += amount;
			//�̹� ���� �÷��̾��� ������ ��, 
			// �� �� �������� 0����
			// ���� ���������� ���� �� ��ġ�� �̵�.(0���� ���� �� Sort)
			if (attacker->IsDead()) {
				it->_Damage = 0;
				it->_Total = 0;
			}
			CompDamageTable comp;
			std::sort(_DamageRate.begin(), _DamageRate.end(), comp);
			return;
		}
	}
	//������ �÷��̾��� ������ �� => �� �÷��̾� ���� �߰�
	DamageTable* newPlayerData = new DamageTable(amount, attacker);
	_DamageRate.push_back(newPlayerData);
}

void HopGoblin::Damaged()
{
	int amount = 0;

	for (auto it : _DamageRate) {
		if (!it->_who->IsDead())
			amount += it->_Damage;
	}

	cur_hp -= amount;

	cout << name << "���� " << amount << "������!!" << endl;

	if (cur_hp < 0)
		cur_hp = 0;

	printInfo();

	if (IsDead()) {
		cout << name << "�� ����߽��ϴ�." << endl;
	}
}

void HopGoblin::PreAttack(vector<Creature*> others)
{
}

bool HopGoblin::CompDamageTable::operator()(const DamageTable* a, const DamageTable* b)
{
	return a->_Total > b->_Total;
}

DamageTable::DamageTable(int dmg, Creature* newbe):
	_Damage(dmg), _Total(dmg), _who(newbe)
{
}
