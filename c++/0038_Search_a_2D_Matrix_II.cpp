/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

// Solution :- 

#include <vector>
using namespace std;

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& mat, int target) {
            if (mat.empty() || mat[0].empty()) return false;
        int m = mat.size(), n = mat[0].size();

        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;
            } else if (target < mat[r][c]) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};
