/* ou are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

// Solution :- 

#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for end of valid elements in nums1
        int j = n - 1;      // Pointer for end of nums2
        int idx = m + n - 1; // Pointer for placement at the back of nums1

        // Compare elements from the back and place the larger element at nums1[idx]
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }

        // If elements remain in nums2, copy them over
        // (If elements remain in nums1, they are already in their correct sorted positions)
        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }
};