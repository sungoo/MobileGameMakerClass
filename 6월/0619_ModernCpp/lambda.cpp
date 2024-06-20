#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

struct Item {
	int price;
	int tier;
	int atk;

	Item(int price, int tier, int atk): price(price), tier(tier), atk(atk){}
};

//�����Լ�
// [] () -> {}
// [ĸ��, �ܺκ����� �����ؼ� ����ϴ� �κ�]
// (�Ű�����)
// -> ��ȯ�ڷ���
// {�ڷ��}
//

int main() {
	srand(time(nullptr));

	vector<Item*> items;

	for (int i = 0; i < 10; i++) {
		int tier = rand()%10 + 1;
		Item* item = new Item(tier * 100, tier, tier * 5);

		items.push_back(item);
	}

	//callable ��ü
	struct ItemFinder_Tier {
		bool operator()(Item* a) {
			return a->tier == tier;
		}
		int tier;
	};

	ItemFinder_Tier ti;
	ti.tier = 0;

	int capture = 1;
	//int* capter_ptr = new int(1);
	items.erase(std::remove_if(items.begin(), items.end(), [capture](const Item* i)->bool {
		return i->tier == capture;
		}), items.end());

	//Items�� ���ݼ����� �������� ����
	std::sort(items.begin(), items.end(), [](const Item* a, const Item* b)->bool {
		return a->price > b->price;
		});
}