#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"


/// <summary>
/// �翵��
/// ���� ��Ʈ����
/// �� cannon�� �ϸ��� ���� ��Ʈ���� �޾Ƽ� ����
/// cannon�� HP : 5
/// ������ hp -1, hp�� 0�̸� cannon �����
/// </summary>

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>(Vector2(130, 550));

	_cannon1->isControlled = true;

	//attack2
	/*for (auto bullet : _cannon1->GetBullets()) {
		bullet->SetTarget(_cannon2);
	}*/
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

	//attack1
	for (auto bullet : _cannon1->GetBullets()) {
		bullet->Attack_Cannon(_cannon2);
	}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
