// Given a string s, return the longest palindromic substring in s.

// Solution:

#include <string>
class Solution {
public:
    // Helper function to expand around a center and return the length of the palindrome.
    // 'left' and 'right' are the initial center(s) of the potential palindrome.
    int expandAroundCenter(const std::string& s, int left, int right) {
        int n = s.length();
        // Expand as long as pointers are within bounds and characters match
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        // When the loop terminates:
        // 'left' is one position to the left of the actual palindrome's start.
        // 'right' is one position to the right of the actual palindrome's end.
        // The length of the palindrome is (right - 1) - (left + 1) + 1, which simplifies to right - left - 1.
        return right - left - 1;
    }

    std::string longestPalindrome(std::string s) {
        if (s.empty()) {
            return "";
        }
        // A single character is always a palindrome, so initialize with length 1.
        if (s.length() == 1) {
            return s;
        }

        int start = 0;       // Stores the starting index of the longest palindrome found so far.
        int maxLength = 1;   // Stores the maximum length of a palindrome found so far.

        // Iterate through each character in the string.
        // Each character 'i' can be the center of an odd-length palindrome (s[i])
        // and/or part of the center of an even-length palindrome (s[i], s[i+1]).
        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindrome (e.g., "aba", center is 'b' at index 1)
            // Expand around a single character 's[i]'
            int len1 = expandAroundCenter(s, i, i);
            if (len1 > maxLength) {
                maxLength = len1;
                // Calculate the start index for this palindrome.
                // If a palindrome of length 'len1' is centered at 'i',
                // its start index is i - (len1 - 1) / 2.
                start = i - (len1 - 1) / 2;
            }

            // Case 2: Even length palindrome (e.g., "abba", center is between 'b' and 'b' at indices 1 and 2)
            // Expand around two adjacent characters 's[i]' and 's[i+1]'
            // Ensure i+1 is a valid index before checking.
            if (i + 1 < s.length()) {
                int len2 = expandAroundCenter(s, i, i + 1);
                if (len2 > maxLength) {
                    maxLength = len2;
                    // Calculate the start index for this palindrome.
                    // If a palindrome of length 'len2' is centered between 'i' and 'i+1',
                    // its start index is i - (len2 - 1) / 2.
                    // This formula works for both odd and even lengths.
                    start = i - (len2 - 1) / 2;
                }
            }
        }
        
        // After checking all possible centers, extract the longest palindromic substring
        // using the recorded 'start' index and 'maxLength'.
        return s.substr(start, maxLength);
    }
};
