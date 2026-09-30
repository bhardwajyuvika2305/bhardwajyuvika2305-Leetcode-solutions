/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b. */

// Solution :- 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        // Length must be equal
        if (n + m != s3.length())
            return false;

        // dp[j] = whether s3[0 ... i+j-1]
        // can be formed using s1[0 ... i-1] and s2[0 ... j-1]
        vector<bool> dp(m + 1, false);

        dp[0] = true;

        // Using only s2
        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Using s1 and s2
        for (int i = 1; i <= n; i++) {

            // Using only s1
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= m; j++) {

                // Take character from s1
                bool fromS1 = dp[j] &&
                    (s1[i - 1] == s3[i + j - 1]);

                // Take character from s2
                bool fromS2 = dp[j - 1] &&
                    (s2[j - 1] == s3[i + j - 1]);

                dp[j] = fromS1 || fromS2;
            }
        }

        return dp[m];
    }
};
