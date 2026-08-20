/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.*/

// Solution :-

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1; // Base case: prefix sum of 0 appears once before array starts
        
        int currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currentSum += num;
            
            // Check if (currentSum - k) exists in map
            if (m.find(currentSum - k) != m.end()) {
                count += m[currentSum - k];
            }
            
            // Increment frequency of current prefix sum
            m[currentSum]++;
        }
        
        return count;
    }
};