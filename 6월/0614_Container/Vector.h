#pragma once

template <typename T>
class Vector
{
	unsigned int _size = 0;
	unsigned int _capacity = 0;

	T* _data = nullptr;

public:
	Vector() {
	}
	~Vector() {//vector ������ ���⼭
		delete[] _data;
	}

	class Iterator {
		T* ptr;
	public:
		Iterator() : ptr(nullptr){}
		Iterator(T* otherPtr) : ptr(otherPtr){}
		//Iterator ����⿡ �ʿ��� �͵�
		//������Ի�����
		Iterator(const Iterator& other) { ptr = other.ptr; }
		//������Կ�����
		Iterator& operator=(const Iterator& other) { ptr = other.ptr; return *this; }
		//!= �񱳿�����
		bool operator != (const Iterator& other) { return ptr != other.ptr; }
		bool operator == (const Iterator& other) { return ptr == other.ptr; }
		//++ ����������
		Iterator& operator++() {
			++ptr;

			return *this;
		}
		Iterator operator++(int) {
			Iterator result = *this;
			
			++(this->ptr);

			return result;
		}
		//* ����������
		T& operator*() {
			return (*ptr);
		}
	};

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
	void PushBack(const T& value) {
		//���Ͱ� �� ��. => 1.2�� ũ���� �� ���ͷ� �ű��
		if (_size == _capacity) {
			int newCapacity = static_cast<int>(_capacity * 1.5f);
			Reserve(newCapacity);
		}
		//������ ����ֱ�
		_data[_size] = value;
		_size++;
	}
	void PopBack() {
		if (_size == 0)
			return;
		_size--;
	}
	void Claer() {
		_size = 0;
	}

	const int& Size() { return _size; }
	const int& Capacity() { return _capacity; }

	T& operator[](int index) {
		if (index < 0 || index >= _size)
			return _data[0];
		return _data[index];
	}

	Vector<T>::Iterator begin() {
		return Vector<T>::Iterator(_data);
	}
	Vector<T>::Iterator end() {
		return Vector<T>::Iterator(_data + _size);
	}
};

