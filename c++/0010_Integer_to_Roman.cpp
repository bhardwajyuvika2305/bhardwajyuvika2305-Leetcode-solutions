// Given an integer, convert it to a Roman numeral.

// Solution :- 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // All 13 values including subtractive pairs, high → low
        vector<pair<int, string>> table = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
            {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
            {1,    "I"}
        };

        string result;
        for (auto& [val, sym] : table) {
            while (num >= val) {   // keep subtracting until we can't
                result += sym;
                num    -= val;
            }
        }
        return result;
    }
};