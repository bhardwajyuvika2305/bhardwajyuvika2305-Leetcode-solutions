/*You are given a string s. 
You can convert s to a palindrome by adding characters in front of it.
Return the shortest palindrome you can find by performing this transformation.*/

// Solution :- 

class Solution {
public:
    string shortestPalindrome(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        int n = temp.length();

        vector<int> lps(n, 0);

        // Calculate LPS array
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }

            if (temp[i] == temp[j]) {
                j++;
            }

            lps[i] = j;
        }

        // Longest palindromic prefix length
        int len = lps[n - 1];

        // Remaining suffix
        string add = s.substr(len);

        reverse(add.begin(), add.end());

        return add + s;
    }
};
