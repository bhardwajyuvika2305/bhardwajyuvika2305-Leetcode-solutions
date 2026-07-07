//  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Solution:
#include <vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
        // Ensure nums1 is the shorter array. This simplifies the binary search
        // range.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        // 'low' and 'high' define the search space for the partition point 'i'
        // in nums1. 'i' represents how many elements are taken from nums1 into
        // the left half of the merged array.
        int low = 0;
        int high = m;

        // Perform binary search to find the correct partition.
        while (low <= high) {
            // i is the partition point for nums1.
            // It means 'i' elements are taken from nums1 to form the left half.
            int i = low + (high - low) / 2;

            // j is the partition point for nums2.
            // (m + n + 1) / 2 calculates the total number of elements required
            // in the left partition. This formula works for both odd and even
            // total lengths.
            int j = (m + n + 1) / 2 - i;

            // Define the four boundary elements for the partitions:
            // maxLeft1: The largest element in the left part of nums1. If i=0,
            // there's no left part, use INT_MIN. minRight1: The smallest
            // element in the right part of nums1. If i=m, there's no right
            // part, use INT_MAX.
            int maxLeft1 =
                (i == 0) ? std::numeric_limits<int>::min() : nums1[i - 1];
            int minRight1 =
                (i == m) ? std::numeric_limits<int>::max() : nums1[i];

            // maxLeft2: The largest element in the left part of nums2.
            // minRight2: The smallest element in the right part of nums2.
            int maxLeft2 =
                (j == 0) ? std::numeric_limits<int>::min() : nums2[j - 1];
            int minRight2 =
                (j == n) ? std::numeric_limits<int>::max() : nums2[j];

            // Check if the partition is correct:
            // A correct partition satisfies two conditions:
            // 1. All elements in the left half are less than or equal to all
            // elements in the right half.
            //    This is covered by: maxLeft1 <= minRight2 AND maxLeft2 <=
            //    minRight1
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Correct partition found!
                // Now, calculate the median based on the total number of
                // elements.
                if ((m + n) % 2 == 1) { // Total length is odd
                    // The median is the largest element in the combined left
                    // half.
                    return static_cast<double>(std::max(maxLeft1, maxLeft2));
                } else { // Total length is even
                    // The median is the average of the two middle elements.
                    // These are the largest in the left half and the smallest
                    // in the right half.
                    return (static_cast<double>(std::max(maxLeft1, maxLeft2)) +
                            std::min(minRight1, minRight2)) /
                           2.0;
                }
            } else if (maxLeft1 > minRight2) {
                // The partition 'i' in nums1 is too far to the right.
                // We need to move 'i' to the left to satisfy maxLeft1 <=
                // minRight2.
                high = i - 1;
            } else { // maxLeft2 > minRight1
                // The partition 'i' in nums1 is too far to the left.
                // We need to move 'i' to the right to satisfy maxLeft2 <=
                // minRight1.
                low = i + 1;
            }
        }

        // This line should ideally not be reached if the input arrays are valid
        // sorted arrays. It's a fallback return in case the loop terminates
        // unexpectedly (e.g., malformed input).
        return 0.0;
    }
};
