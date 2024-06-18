#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Func(const int& val) {
	if (val > 15)
		return true;
	return false;
}

void X3(int& val) {
	val *= 3;
}

int main() {

	vector<int> mVec;

	mVec.push_back(3);
	mVec.push_back(5);
	mVec.push_back(7);
	mVec.push_back(9);
	mVec.push_back(1);

	mVec.push_back(21);
	mVec.push_back(4);
	mVec.push_back(6);
	mVec.push_back(8);
	mVec.push_back(1);

	//1_ 1�� �ִ��� ã��. �׸��� index Ȥ�� iterator�ڸ� ��ȯ
	int index = 0;
	for (index; index < mVec.size(); index++) {
		if (mVec[index] == 1) break;
	}
	if (index == mVec.size())
		cout << "�ε����� 1 �߰� ����." << endl;
	else
		cout << "�ε����� 1 �߰�. ��ġ : " << index+1 << endl;
	
	vector<int>::iterator mit = mVec.begin();
	for (mit; mit != mVec.end(); mit++) {
		if (*mit == 1) break;
	}
	if (mit == mVec.end())
		cout << "���ͷ����ͷ� 1 �߰� ����." << endl;
	else
		cout << "���ͷ����ͷ� 1 �߰�. ��ġ : " << &*mit << endl;

	mit = std::find(mVec.begin(), mVec.end(), 1);
	if (mit != mVec.end())
		cout << *mit << endl;
	//2_ 15���� ū ���� �ִ��� ã�� index Ȥ�� iterator �ڸ� ��ȯ
	struct Finder_1 {
		bool operator()(const int& val) {
			if (val > compareNum)
				return true;
			return false;
		}
		int compareNum = 0;
	};
	Finder_1 finder_1;

	finder_1.compareNum = 15;
	mit = std::find_if(mVec.begin(), mVec.end(), finder_1);//find_if�� �����Լ��� �����Լ��� ���� �� ����
	cout << *mit << endl;

	//3_ ��� ���� 50���� ������ bool�� �˸���
	struct Finder_2
	{
		bool operator()(const int& val) {
			if (val < compareNum)
				return true;
			return false;
		}
		int compareNum = 0;
	};
	Finder_2 finder_2;
	finder_2.compareNum = 50;

	bool istrue = std::all_of(mVec.begin(), mVec.end(), finder_2);
	if (istrue)
		cout << "��� ���� 50���� ����" << endl;
	else
		cout << "50 �̻��� ���� ����" << endl;

	//4_ �ϳ��� 30���� ū ���� �ִ��� bool�� �˸���
	finder_1.compareNum = 30;
	istrue = std::any_of(mVec.begin(), mVec.end(), finder_1);
	if (istrue)
		cout << "30���� ū ���� ����" << endl;
	else
		cout << "30���� ū ���� ����" << endl;

	//5_ ���Ұ� 3�� ���ҵ��� ������ �˾Ƴ���
	
	int cnt = std::count(mVec.begin(), mVec.end(), 3);
	cout << "3�� ������ ���� : " << cnt << endl;

	//6_ ���Ұ� 5 �̻��� ���� ������ �˾Ƴ���
	finder_1.compareNum = 4;
	cnt = std::count_if(mVec.begin(), mVec.end(), finder_1);
	cout << "5 �̻� ������ ���� : " << cnt << endl;

	//7_ ��� ���ҿ� 3 ���ϱ�
	cout << "��� ���� 3 ���ϱ�" << endl;
	for_each(mVec.begin(), mVec.end(), X3);
	
	for (mit = mVec.begin(); mit != mVec.end(); mit++) {
		cout << *mit << ' ';
	}
	cout << endl;

	//8_ �ߺ� ���� �����ϱ�
	cout << "�ߺ� ���� ����" << endl;
	
	auto it = std::unique(mVec.begin(), mVec.end());

	mVec.resize(std::distance(mVec.begin(), it));

	for (mit = mVec.begin(); mit != it; mit++) {
		cout << *mit << ' ';
	}
	cout << endl;
	//9_ ���Ұ� 12�� �� �����
	cout << "remove 12" << endl;
	it = std::remove(mVec.begin(), mVec.end(), 12);
	for (mit = mVec.begin(); mit != it; mit++) {
		cout << *mit << ' ';
	}
	cout << endl;

	//10_ ���Ұ� 10���� ������ �����
	finder_2.compareNum = 10;
	cout << "remove x < 10" << endl;
	it = std::remove_if(mVec.begin(), mVec.end(), finder_2);
	for (mit = mVec.begin(); mit != it; mit++) {
		cout << *mit << ' ';
	}
	cout << endl;

	return 0;
}