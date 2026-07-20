/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
 */

// Solution :-

# include <iostream>
# include <vector>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // skip dup i
            // Pruning: 4 smallest > target → no point going further
            if ((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            // Pruning: 4 largest < target → i too small, try next
            if ((long long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue; // skip dup j
                if ((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if ((long long)nums[i]+nums[j]+nums[n-1]+nums[n-2] < target) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left]  == nums[left+1])  left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++; right--;
                    }
                    else if (sum < target) left++;
                    else                   right--;
                }
            }
        }
        return result;
    }
};