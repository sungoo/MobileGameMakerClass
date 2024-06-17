#pragma once

template <typename T>
class Vector
{
	int _size = 0;
	int _capacity = 0;

	T* _data = nullptr;

public:
	Vector() {
		_size = 1;
		_capacity = 1;

		_data = new T[1];
	}
	~Vector() {//vector ������ ���⼭
		/*for (int i = 0; i < _capacity; i++) {
			delete _data[i];
		}*/
		delete[] _data;
	}

	void Reserve(const int capacity = 10) {
		//���� ������ ũ�⺸�� �� ���� capacity �䱸��, ����
		if (capacity < _capacity)
			return;
		//capacity ��ŭ �� ���� �����
		T* newVector = new T[capacity];
		//���� ���Ϳ� �ִ� ����� ��� �� ���ͷ� �ű��.
		for (int i = 0; i < _size; i++) {
			newVector[i] = _data[i];
		}
		//���� ���� �����
		delete[] _data;
		//�� ���͸� ����Ű�� ����
		_data = newVector;
		
		_capacity = capacity;
	}
	void PushBack(T value) {
		//���Ͱ� �� ��. => 1.2�� ũ���� �� ���ͷ� �ű��
		if (_size == _capacity) {
			int newCapacity = static_cast<int>(_capacity * 1.2f);
			Reserve(newCapacity);
		}
		//������ ����ֱ�
		_data[_size] = value;
		_size++;
	}
	void PopBack() {
		if (_size == 0)
			return;
		_data[_size - 1] = NULL;
		_size--;
	}
	void Claer() {
		for (int i = 0; i < _size; i++) {
			_data[i] = NULL;
		}
		_size = 0;
	}

	const int& Size() { return _size; }
	const int& Capacity() { return _capacity; }

	T operator[](int index) {
		if (index <0 || index >= _size)
			return NULL;
		return _data[index];
	}
};

