// Given an integer x, return true if x is a palindrome, and false otherwise.

// Solution:-

class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases:
        // 1. Negative numbers are not palindromes (e.g., -121 reads -121 forwards, but 121- backwards).
        // 2. Numbers ending in 0 (and not 0 itself) cannot be palindromes.
        //    For a number like 10, to be a palindrome, its first digit must also be 0, which is not how numbers are represented.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        // Build the reverted number until it becomes greater than or equal to x.
        // This effectively reverses only the second half of the number.
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + (x % 10);
            x /= 10;
        }
        // When the loop terminates, we have two scenarios:
        // 1. If the number has an even number of digits, x and revertedNumber should be equal.
        //    (e.g., x = 1221 -> x becomes 12, revertedNumber becomes 12. Loop ends.)
        // 2. If the number has an odd number of digits, x will be the middle digit,
        //    and revertedNumber will have the middle digit at its most significant place.
        //    To compare, we can remove the middle digit from revertedNumber by dividing by 10.
        //    (e.g., x = 121 -> x becomes 1, revertedNumber becomes 12. Loop ends.
        //           Then, x (1) should equal revertedNumber / 10 (12 / 10 = 1).)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};