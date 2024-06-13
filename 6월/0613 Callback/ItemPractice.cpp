#include <iostream>

using namespace std;

struct Item
{
	int price;
	int tier;
	int atk;

	Item() :price(0), tier(0), atk(0) {}

	void PrintItem() {
		cout << "Price : " << price << endl;
		cout << "Tier : " << tier << endl;
		cout << "atk : " << atk << endl;
	}
};

//�Լ��� ã�� ���
Item* FindItem_Price_Func(Item* arr, int size, int price) {
	//�Ű����� price�� �´� �������� ã�Ƽ�, return.
	//���� ���ٸ� nullptr ��ȯ

	Item* result = nullptr;

	for (int i = 0; i < size; i++) {
		if ((arr + i)->price == price)
			result = (arr + i);
	}
	return result;
}
////////////////////////////////////////////////////////////////
//�Լ� �����͸� �̿��ؼ� ã�� ���
Item* FindItem_FuncPtr(Item* arr, int size, bool(*func)(const Item&)) {
	Item* result = nullptr;

	for (int i = 0; i < size; i++) {
		if (func(arr[i]))
			result = &arr[i];
	}
	return result;
}
bool Ptr_Price(const Item& item) {
	if (item.price == 10000)
		return true;
	return false;
}
bool Ptr_Tier(const Item& item) {
	if (item.tier == 8)
		return true;
	return false;
}
////////////////////////////////////////////////////////////////
//�Լ� ��ü�� ã�� ���
struct Finder {
	int itemPrice;
	int itemTier;
	int itemAtk;

	Finder():itemPrice(0), itemTier(0), itemAtk(0){}

	bool* operator()(const Item& item) {

		bool finding[3] = { false };

		if (itemPrice == item.price)
			finding[0] = true;
		if (itemTier == item.tier)
			finding[1] = true;
		if (itemAtk == item.atk)
			finding[2] = true;
		return finding;
	}
};

struct FinderTA {
	int itemPrice;
	int itemTier;
	int itemAtk;

	FinderTA() :itemPrice(0), itemTier(0), itemAtk(0) {}

	bool* operator()(const Item& item) {

		bool finding[3] = { false };

		//if (itemPrice == item.price)
			finding[0] = true;
		if (itemTier == item.tier)
			finding[1] = true;
		if (itemAtk == item.atk)
			finding[2] = true;
		return finding;
	}
};

struct FinderPT {
	int itemPrice;
	int itemTier;
	int itemAtk;

	FinderPT() :itemPrice(0), itemTier(0), itemAtk(0) {}

	bool* operator()(const Item& item) {

		bool finding[3] = { false };

		if (itemPrice == item.price)
			finding[0] = true;
		if (itemTier == item.tier)
			finding[1] = true;
		//if (itemAtk == item.atk)
			finding[2] = true;
		return finding;
	}
};

template<typename I, typename T>
I* FindItem_Functor(I* arr, int size, T finder) {

	I* result = nullptr;
	for (int i = 0; i < size; i++) {
		if (finder(arr[i])[0] && finder(arr[i])[1] && finder(arr[i])[2])
			result = &arr[i];
	}
	return result;
}
//Item* FindItem_FunctorPT(Item* arr, int size, Finder finder) {
//
//	Item* result = nullptr;
//	for (int i = 0; i < size; i++) {
//		if (finder(arr[i])[0] && finder(arr[i])[1])
//			result = &arr[i];
//	}
//	return result;
//}

int main() {
	Item items[10];
	for (int i = 0; i < 10; i++) {
		items[i].price = 500 * (i + 1) * 3;
		items[i].tier = (10 - i);
		items[i].atk = 10 * (i + 1);
	}

	Item* findItem = nullptr;

	//�Լ� �����͸� ����ؼ�
	//Tier�� 8�� �ָ� ã�Ƽ� ���
	findItem = FindItem_FuncPtr(items, 10, Ptr_Tier);
	if (findItem != nullptr)
		findItem->PrintItem();

	cout << endl;
	//�Լ� ��ü�� ����ؼ�
	//Price�� 9000�̰�, tier�� 5�� �� ã��
	findItem = nullptr;
	FinderPT findPT;
	findPT.itemPrice = 9000;
	findPT.itemTier = 5;
	findItem = FindItem_Functor(items, 10, findPT);
	if (findItem != nullptr)
		findItem->PrintItem();

	cout << endl;
	//�Լ� ��ü�� ����ؼ�
	//price = 3000, tier = 9, atk = 20 ã��
	findItem = nullptr;
	Finder find;
	find.itemPrice = 3000;
	find.itemTier = 9;
	find.itemAtk = 20;
	findItem = FindItem_Functor(items, 10, find);
	if (findItem != nullptr)
		findItem->PrintItem();

	cout << endl;
	//�Լ� ��ü ���ø��� ����ؼ� tier = 9, atk =  20 ã��
	findItem = nullptr;
	FinderTA findTA;
	findTA.itemTier = 9;
	findTA.itemAtk = 20;
	findItem = FindItem_Functor(items, 10, findTA);
	if (findItem != nullptr)
		findItem->PrintItem();

	return 0;
}