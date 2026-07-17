/* Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".*/

// Solution :- 


#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int col = 0; col < (int)strs[0].size(); col++) {
            char c = strs[0][col];                       // reference character

            for (int row = 1; row < (int)strs.size(); row++) {
                // Mismatch OR current string is too short
                if (col >= (int)strs[row].size() || strs[row][col] != c) {
                    return strs[0].substr(0, col);       // prefix ends here
                }
            }
        }

        return strs[0];   // strs[0] itself is the common prefix
    }
};