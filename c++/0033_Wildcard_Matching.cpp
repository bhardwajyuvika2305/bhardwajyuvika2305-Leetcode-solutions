/* Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

// Solution :- 

#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        int m = s.length(), n = p.length();

        while (sIdx < m) {
            // Case 1: Exact match or '?' wildcard
            if (pIdx < n && (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Encountered '*' wildcard
            else if (pIdx < n && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++; // Assume '*' matches empty sequence initially
            }
            // Case 3: Mismatch, but we have a previous '*' to backtrack to
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                sTmpIdx++;
                sIdx = sTmpIdx;
            }
            // Case 4: Mismatch and no '*' available
            else {
                return false;
            }
        }

        // Skip any remaining '*' in pattern
        while (pIdx < n && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == n;
    }
};