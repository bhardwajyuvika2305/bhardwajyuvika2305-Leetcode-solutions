/*You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.
We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
Return the largest possible overlap.*/

// Solution :- 

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> p1, p2;

        // Collect coordinates of all 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) p1.push_back({r, c});
                if (img2[r][c] == 1) p2.push_back({r, c});
            }
        }

        // Frequency table for shifts (offset by n to avoid negative array indices)
        std::vector<std::vector<int>> count(2 * n, std::vector<int>(2 * n, 0));
        int maxOverlap = 0;

        // Count shift vectors between every pair of 1s
        for (const auto& [r1, c1] : p1) {
            for (const auto& [r2, c2] : p2) {
                int dr = r2 - r1 + n;
                int dc = c2 - c1 + n;
                count[dr][dc]++;
                maxOverlap = std::max(maxOverlap, count[dr][dc]);
            }
        }

        return maxOverlap;
    }
};