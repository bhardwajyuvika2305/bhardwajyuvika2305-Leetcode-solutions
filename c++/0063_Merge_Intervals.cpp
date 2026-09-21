/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

// Solution :- 

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by starting time
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged is empty OR no overlap with the last merged interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlap exists: merge by updating end time
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};