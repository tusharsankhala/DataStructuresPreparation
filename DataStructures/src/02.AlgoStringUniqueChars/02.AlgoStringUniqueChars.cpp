// 02.AlgoStringUniqueChars.cpp
// Algorithm to find if a string has all the unique characters.

#include <iostream>
#include <map>
#include <string>
#include <memory>


// Method 1. Use of Hash Map (Associative Containers).
/*
int main()
{
    std::string str = "Bhavya";
    char* buffer = &str[0];
    std::map<char, int> map;

    for (uint32_t i = 0; i < str.size(); ++i)
    {
        if(map.count(buffer[i]) == 0)
        {
            map[buffer[i]] = 0;            
        }
        else if (map.count(buffer[i]) > 0)
        {
            int val = map.at(buffer[i]);
            val++;
            map[buffer[i]] = val;
        }
    }
}
*/

// Method 2. Using BitWise operators.
// Returns true if all characters of str are 
// unique. 
// The idea is to use an integer variableand use bits in its binary
// representation to store whether a character is present or not.
// Typically an integer has at - least 32 bits and we need to store presence / absence
// of only 26 characters.
// Assumptions : (1) str contains only characters 
//                   from 'a' to 'z' 
//               (2) integers are stored using 32 
//                   bits 

int main()
{
    std::string str = "bhavya";

    // An integer to store presence/absence 
    // of 26 characters using its 32 bits. 
    int checker = 0;

    for (uint32_t i = 0; i < str.size(); ++i)
    {
        int val = (str[i] - 'a');

        // If bit corresponding to the
        // current charater is already set.
        if((checker & (1 << val)) > 0)
        {
            return - 1;
        }

        // Set bit in checker.
        checker |= (1 << val);
    }

    return 0;
}