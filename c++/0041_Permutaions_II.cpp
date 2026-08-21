/* Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

// Solution :-

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip used elements
            if (used[i]) continue;

            // Skip duplicates: if the current element is the same as the previous one,
            // and the previous one was not used in this recursion path, skip it.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, result, current, used);

            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        // Sort to bring duplicate numbers adjacent to each other
        sort(nums.begin(), nums.end());

        backtrack(nums, result, current, used);
        return result;
    }
};