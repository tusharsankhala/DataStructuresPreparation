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
		size = s > 2 ? s : 2;
		data = new T[size];
	}

	~StackArray()
	{
		delete[] data;
	}

	// Operations on Stack.
	bool Push(T val)
	{
		if (top == size - 1)
		{
			std::cout << "Stack Overflow, Can't add elements" << '\n';
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
		if (index > size - 1) && (index < 0)
		{
			std::cout << "Index is greater then size" << '\n';
			return -1;
		}

		T num = data[top - (index - 1)];
		
		return num;
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
			std::cout << "Stack Underflow, It's Empty" << '\n';
			return true;
		}

		return false;
	}

	void Display()
	{
		std::cout << "Stack:";
		for (int i=top; i >= 0; --i)
		{
			std::cout << " " << data[i];
		}

		std::cout << '\n';
	}

private:
	size_t size = 0;
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
	
	stackArray.Display();
	stackArray.Push(60);
	stackArray.IsFull();

	std::cout<< "Element at 2 index of stack: " << stackArray.Peek(2) <<'\n';

	stackArray.Pop();
	std::cout << "Element at 3 index of stack: " << stackArray.Peek(3) << '\n';
	stackArray.Display();

	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
	stackArray.Pop();
}