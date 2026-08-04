/* You are given an integer array nums consisting of unique integers.
Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
The smallest and largest integers of the original range are still present in nums.
Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.*/

// Solution :- 

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> result;
        
        for (int i = min_val; i <= max_val; ++i) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};