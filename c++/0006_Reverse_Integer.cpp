// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Solution:-

#include <limits> // Required for std::numeric_limits<int>::max() and min()

class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0;

        while (x != 0) {
            int digit = x % 10;

            // Overflow checks before modifying reversed_x:
            // For positive overflow
            if (reversed_x > std::numeric_limits<int>::max() / 10 || 
                (reversed_x == std::numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0;
            }
            // For negative overflow
            if (reversed_x < std::numeric_limits<int>::min() / 10 || 
                (reversed_x == std::numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0;
            }

            // Build the reversed number
            reversed_x = reversed_x * 10 + digit;

            // Remove the last digit from x
            x /= 10;
        }

        return reversed_x;
    }
};