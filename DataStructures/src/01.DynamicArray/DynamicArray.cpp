#include "DynamicArray.h"

template<class T>
int Vector<T>::size_of_list()
{
	return size;
}

template<class T>
bool Vector<T>::empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

template<class T>
void Vector<T>::reserve(int Num)
{
	if (capacity > Num)
		return;
	T* temp = new T[Num];
	for (int i = 0; i < size; i++)
	{
		temp[i] = obj[i];
	}
	if (obj != NULL) delete[] obj;

	obj = temp;
	capacity = Num;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return obj[index];
}

template<class T>
T Vector<T>::at(int i)
{
	return obj[i];
}

template<class T>
T Vector<T>::front()
{
	return obj[0];
}

template<class T>
T Vector<T>::back()
{
	return obj[size - 1];
}

template<class T>
void Vector<T>::insert(int i, T e)
{
	obj[i] = e;
}

template<class T>
void Vector<T>::erase(int i)
{
	if (i >= 0 && i < size)
	{
		for (int j = 0; j < size; j++)
		{
			obj[j] = obj[j + 1];
		}
		obj[size] = NULL;
	}
}

template class Vector<int>;