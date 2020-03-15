#pragma once

#include <iostream>

template <class T>
class Vector
{
private:
	int size, capacity;
	T* obj;
public:
	Vector()
	{
		size = capacity = 0;
		obj = NULL;
	}

	~Vector()
	{
		delete[] obj;
	}

	Vector(int a)
	{
		size = a;
		obj = new T[size];

		for (int i = 0; i < size; i++)
		{
			obj[i] = NULL;
		}
	}
	int size_of_list();
	bool empty();
	void reserve(int);
	T& operator[](int);
	T at(int);
	T front();
	T back();
	void push_back(T element);
	void pop_back();
	void insert(int, T);
	void erase(int);

};