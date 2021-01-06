//-------------------------------------------
// Stack implementation using Array. 
// - Array is created at runtime.
//-------------------------------------------

#include <iostream>

template <typename T>
class StackArray
{
public:
	explicit StackArray(size_t s) 
	{
		size = s;
		data = new T[size];
	}

	~StackArray()
	{
		delete[] data;
	}

	// Operations on Stack.
	bool Push(T val)
	{
		if (top == size)
		{
			std::cout << "Stack is Full, Can't add elements" << '\n';
			return false;
		}

		data[++top] = val;

		return true;
	}

	bool Pop()
	{
		if (top < 0)
		{
			std::cout << "Stack is Empty, Can't remove elements" << '\n';
			return false;
		}

		std::cout << "Item is removed: " << data[top] << '\n';
		--top;

		return true;
	}

	T Peek(size_t index)
	{
		if (index >= size)
		{
			std::cout << "Index is greater then size" << '\n';
			return -1;
		}

		return data[index];
	}

	bool IsFull()
	{
		if (top == size-1)
		{
			std::cout << "Stack is Full" << '\n';
			return true;
		}

		return false;
	}

	bool IsEmpty()
	{
		if (top < 0)
		{
			std::cout << "Stack is Empty" << '\n';
			return true;
		}

		return false;
	}

	void Print()
	{
		std::cout << "Stack:";
		for (int i=0; i <= top; ++i)
		{
			std::cout << " " << data[i];
		}
	}

private:
	size_t size;
	int top = -1;
	T* data = nullptr;
};

int main()
{
	StackArray<int> stackArray{ 5 };

	stackArray.Push(10);
	stackArray.Push(20);
	stackArray.Push(30);
	stackArray.Push(40);
	stackArray.Push(50);
	
	stackArray.Print();
	stackArray.Push(60);
	stackArray.IsFull();


	stackArray.Pop();
	stackArray.Print();

	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
}