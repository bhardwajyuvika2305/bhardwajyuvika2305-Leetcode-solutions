/*Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.*/

// Solution :-

class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        // i represents the current digit place (1, 10, 100, ...)
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            long long high = n / divider;
            long long current = (n / i) % 10;
            long long low = n % i;
            
            if (current == 0) {
                count += high * i;
            } else if (current == 1) {
                count += high * i + (low + 1);
            } else {
                count += (high + 1) * i;
            }
        }
        return count;
    }
};
