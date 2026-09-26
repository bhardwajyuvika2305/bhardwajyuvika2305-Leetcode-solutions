/*An n-bit gray code sequence is a sequence of 2n integers where:
Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.*/

// Solution :- 

class Solution {
public:
    std::vector<int> grayCode(int n) {
        int totalElements = 1 << n;
        std::vector<int> result(totalElements);
        
        for (int i = 0; i < totalElements; ++i) {
            result[i] = i ^ (i >> 1);
        }
        
        return result;
    }
};

 

 
