// Given an m x n matrix, return all elements of the matrix in spiral order.

// Solution :- 

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse Right across the top row
            for (int col = left; col <= right; ++col) {
                result.push_back(matrix[top][col]);
            }
            top++; // Shrink top boundary

            // 2. Traverse Down along the right column
            for (int row = top; row <= bottom; ++row) {
                result.push_back(matrix[row][right]);
            }
            right--; // Shrink right boundary

            // 3. Traverse Left across the bottom row (if top <= bottom)
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--; // Shrink bottom boundary
            }

            // 4. Traverse Up along the left column (if left <= right)
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    result.push_back(matrix[row][left]);
                }
                left++; // Shrink left boundary
            }
        }

        return result;
    }
};