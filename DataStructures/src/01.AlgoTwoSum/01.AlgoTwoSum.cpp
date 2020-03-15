// 01.AlgoTwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Two Sum Problem.

#include <iostream>
#include <map>
#include <vector>

/*
// O(n^2) Approach
// 1. Start i from 0 to n-2
// 2. Start j from i+1 to n-1.
// Try adding their sum.
// If found then return the index.
int main()
{
    int arr[] = {2, 15, 11, 7};
    int target = 22;
    bool found = false;

    int noOfElements = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < noOfElements - 1; ++i)
    {
        for (int j = i + 1; j < noOfElements; ++j)
        {
            if ((arr[i] + arr[j]) == target)
            {
                std::cout << "Index is [" << arr[i] << "," << arr[j] << "]" << std::endl;
                std::cout << "Index is [" << i+1 << "," << j+1 << "]" << std::endl;
                found = true;
                return found;
            }
        }
    }

    return found;
}
*/
// Two Pass Hash Table.
// O(n) Approach
// Use of Hash Map. LookUp and insertion time 0(1).
int main()
{
    std::vector<int> numbers = { 2, 15, 11, 7 };
    std::vector<int> res;
    std::map<int, int>hmap;
    hmap.clear();

    int target = 9;

    for (int i = 0; i < numbers.size(); i++)
    {
        hmap[numbers[i]] = i;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (hmap.find((target - numbers[i])) != hmap.end())
        {
            if (i < hmap[target - numbers[i]])
            {
                res.push_back(i + 1);
                res.push_back(hmap[target - numbers[i]] + 1); 
                //return res;
            }
            if (i > hmap[target - numbers[i]])
            {
                res.push_back(hmap[target - numbers[i]] + 1);
                res.push_back(i + 1);
                //return res;
            }
        }
    }

    return 0;
}