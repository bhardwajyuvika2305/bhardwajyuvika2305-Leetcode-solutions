/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

// Solution :- 

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const unordered_map<char, string> phone = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> result;
        string current;

        function<void(int)> backtrack = [&](int idx) {
            if (idx == (int)digits.size()) {   // built a full combination
                result.push_back(current);
                return;
            }
            for (char c : phone.at(digits[idx])) {
                current += c;                  // choose
                backtrack(idx + 1);            // explore
                current.pop_back();            // un-choose (backtrack)
            }
        };

        backtrack(0);
        return result;
    }
};