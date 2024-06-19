#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//Unordered map
// ����
// - key������ Ž��(����)�� ����� �ð��� �ɸ���.
// - �߰� ���� ������ ����� �ð�
// ����
// - �ؽþ˰��� ������ ���� ���� �� -> ü�̴��� �������.
// => Ž���� �ð��� �� ���� �ɸ��� �ȴ�.
//
// map
// ����
// - key������ Ž�� �ÿ� N���� ���Ұ� ���� ��,, log N ��ŭ�� �ð��� �ɸ���.
//

struct UserInfo {
	int id;

	UserInfo(){}
	UserInfo(int id):id(id){}
};

int main() {
#pragma region Umap
	/*vector<UserInfo> users;

	users.reserve(1000);
	for (int i = 0; i < 1000; i++) {
		UserInfo info;
		info.id = i + 100;

		users.push_back(info);
	}*/

	//id�� ���׹��� �����ٰ� ����
	//id�� 555 ��°�� �ָ� ã��ʹ�.
	//������ ��� :
	/*for (int i = 0; i < users.size(); i++) {
		if (users[i].id = 555) {
			break;
		}
	}*/

	unordered_map<int, UserInfo> um;

	for (int i = 0; i < 10000; i++) {
		//���Ƿ� ���� �ؽ� �˰���
		//int key = i % 1000;

		UserInfo info;
		info.id = i;

		pair<int, UserInfo> pair = { i, info };
		um.insert(pair);
	}

	pair<int, UserInfo> Mpair = { 4999, UserInfo(4999)};
	um.insert(make_pair<int, UserInfo>(5001, UserInfo(5001)));
	um[5000] = UserInfo(5000);

	cout << um[5000].id << endl;

	unordered_map<int, UserInfo>::iterator um_iter;

	for (um_iter = um.begin(); um_iter != um.end(); um_iter++) {
		//cout << "key : " << um_iter->first << "  value : " << um_iter->second.id << endl;
	}
#pragma endregion
	///////////////////////////////////////////

	map<int, UserInfo> myMap;

	for (int i = 0; i < 1000; i++) {
		myMap[i] = UserInfo(i);
		myMap.insert(make_pair<int, UserInfo>(1 + 1000, UserInfo(i + 1000)));
	}

	map<int, UserInfo>::iterator m_iter;
	for (m_iter = myMap.begin(); m_iter != myMap.end(); m_iter++) {
		cout << "key : " << m_iter->first.id << "value : " << m_iter->second.id << endl;
	}

	return 0;
}