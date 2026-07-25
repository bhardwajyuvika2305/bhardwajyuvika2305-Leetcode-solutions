/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?*/

// Solution :- 

#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Min-heap storing the top k largest elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};