/* Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
Return a boolean indicating whether the matching covers the entire input string (not partial).
*/

// Solutiom :- 

#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // dp[i][j] = true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true; // empty string matches empty pattern 

        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // Case 1: use '*' as zero occurrences (skip "x*")
                    dp[i][j] = dp[i][j - 2];
                    
                    // Case 2: use '*' as one or more occurrences
                    // preceding char must match current s[i-1]
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Direct match or '.' wildcard
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};