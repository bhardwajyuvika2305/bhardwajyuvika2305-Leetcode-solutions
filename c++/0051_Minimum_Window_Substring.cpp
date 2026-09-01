/* Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique. */

// Solution :- 

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> target_freq(128, 0);
        for (char c : t) {
            target_freq[c]++;
        }

        vector<int> window_freq(128, 0);
        int required = 0; // Number of unique characters in t with met frequencies
        for (int count : target_freq) {
            if (count > 0) required++;
        }

        int formed = 0;
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        while (right < s.length()) {
            char c = s[right];
            window_freq[c]++;

            if (target_freq[c] > 0 && window_freq[c] == target_freq[c]) {
                formed++;
            }

            // Shrink the window from the left as long as it remains valid
            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                window_freq[c]--;
                if (target_freq[c] > 0 && window_freq[c] < target_freq[c]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};