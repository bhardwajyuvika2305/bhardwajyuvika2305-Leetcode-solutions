/* You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'
However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
For example, "11106" can be decoded into:
"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.
Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
The test cases are generated so that the answer fits in a 32-bit integer.
 */

 // Solution :- 

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        // dp[i] represents the number of ways to decode substring s[0...i-1]
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string has 1 valid decoding way
        dp[1] = 1; // We already checked s[0] != '0'

        for (int i = 2; i <= n; ++i) {
            // Check single digit decoding (s[i-1])
            int singleDigit = s[i - 1] - '0';
            if (singleDigit >= 1 && singleDigit <= 9) {
                dp[i] += dp[i - 1];
            }

            // Check two digit decoding (s[i-2...i-1])
            int twoDigits = std::stoi(s.substr(i - 2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
