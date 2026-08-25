/* Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.*/

// Solution :-

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        int left = 1, right = x;
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Using mid <= x / mid instead of mid * mid <= x to prevent integer overflow
            if (mid <= x / mid) {
                ans = mid;     // Store valid candidate
                left = mid + 1; // Try to find a larger valid integer
            } else {
                right = mid - 1; // mid is too large
            }
        }
        
        return ans;
    }
};