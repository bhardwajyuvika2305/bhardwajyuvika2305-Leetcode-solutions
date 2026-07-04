// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//Solution:
#include <vector>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {  // j = i+1 (avoid duplicate pairs)
                if (nums[i] + nums[j] == target) {
                    return {i, j};   // return the pair as a vector
                }
            }
        }
        return {}; // if no pair found
    }
};