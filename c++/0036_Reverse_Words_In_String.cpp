/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

// Solution :-

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            
            // Extract the word
            int j = i;
            while (j < n && s[j] != ' ') j++;
            
            string word = s.substr(i, j - i);
            
            // Append word to front or handle spaces
            if (ans.length() == 0) {
                ans = word;
            } else {
                ans = word + " " + ans;
            }
            
            i = j;
        }
        
        return ans;
    }
};