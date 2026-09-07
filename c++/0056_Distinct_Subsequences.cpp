/* Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
*/

// Solution :- 

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        // dp[j] will hold the number of subsequences for t[0...j-1]
        std::vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: an empty target t can be formed in 1 way
        dp[0] = 1;

        for (int i = 1; i <= m; ++i) {
            // Traverse backwards to use values from the previous state of `dp`
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n];
    }
};