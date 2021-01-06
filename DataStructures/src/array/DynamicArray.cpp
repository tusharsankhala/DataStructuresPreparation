// Dynamic array.cpp :
// Wrapping a C-Style array to a dynamic array.
//

#include <iostream>
#include <array>
#include <string>
#include <sstream>

template <typename T>
class DynamicArray
{
public:
    DynamicArray(int n)
    {
        this->n = n;
        data = new T[n];
    }

    DynamicArray(const DynamicArray& arr)
    {
        this->n = arr.n;
        data = new T[n];

        for (int i=0; i<n; ++i)
        {
            data[i] = arr.data[i];
        }
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T operator[](int index) const 
    {
        return data[index];
    }

    T& at(int index)
    {
        if (index < n)
            return data[index];

        throw "Index out of range";
    }

    size_t size() const
    {
        return n;
    }

    ~DynamicArray()
    {
        n = 0;
        delete[] data;
    }

    T* begin()
    {
        return data;
    }

    const T* begin() const
    {
        return data;
    }

    T* end()
    {
        return data + n; 
    }

    const T* end() const
    {
        return data + n;
    }

    friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, const DynamicArray<T>& arr2)
    {
        DynamicArray<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    // To String Function.
    std::string toString(const std::string sep = ",")
    {
        if (n == 0)
            return " ";

        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; ++i)
        {
            os << sep << data[i];
        }

        return os.str();
    }

private:
    int n;
    T* data;
};

struct Student
{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    return (os << "[ Name: " << student.name << ", Standard: " << student.standard << "]\n");
}

/*
int main()
{
    int n;
    std::cout << "Enter the no of Students for Class 1" << '\n';
    std::cin >> n;
    DynamicArray<Student> class1{ n };

    std::string name;
    int standard = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Enter the name of the Students" << i << '\n';
        std::cin >> name;
        
        std::cout << "Enter the Standard of the Students" << i << '\n';
        std::cin >> standard;
        class1[i] = Student{ name, standard };
    }

    try
    {
        // Exception Thrown.
        class1.at(n);
    }
    catch (...)
    {
        std::cout << "Exception Caught" << std::endl;
    }
    
    // Deep Copy.
    auto class2 = class1; 
    std::cout << "Class 2 after initialized from class 1" << '\n';
    std::cout << class2.toString();
    
    auto class3 = class1 + class2;
    std::cout << "Class 3 after initialized from class 1 + class2" << '\n';
    std::cout << class3.toString();
}
*/