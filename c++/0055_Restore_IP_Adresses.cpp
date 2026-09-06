/*A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/

// Solution :- 

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        
        // A valid IPv4 address requires between 4 and 12 digits
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        string currentPath = "";
        backtrack(s, 0, 0, currentPath, result);
        return result;
    }

private:
    void backtrack(const string& s, int startIndex, int partsCount, string currentPath, vector<string>& result) {
        // Base Case: If we formed 4 parts and used the entire string
        if (partsCount == 4) {
            if (startIndex == s.length()) {
                result.push_back(currentPath);
            }
            return;
        }

        // Try forming segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (startIndex + len > s.length()) break;

            string segment = s.substr(startIndex, len);
            
            // Check for leading zero rule (e.g., "01", "00" are invalid, but "0" is valid)
            if (segment.length() > 1 && segment[0] == '0') break;

            // Check if segment value is <= 255
            int val = stoi(segment);
            if (val > 255) break;

            // Append segment to path with dot delimiter
            string nextPath = currentPath + (partsCount == 0 ? "" : ".") + segment;
            
            backtrack(s, startIndex + len, partsCount + 1, nextPath, result);
        }
    }
};